#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;
class Fuzzy{

float hamasedikit=0;
float hamasedang=0;
float hamabanyak=0;

float pestisidasedikit=0;
float pestisidacukup=0;
float pestisidabanyak=0;

float hasilpanensedikit=0;
float hasilpanencukup=0;
float hasilpanenbanyak=0;

float terbesarX, terbesarY;

public:

    void angotahama(float inputhama){
        if(inputhama<=200){
            hamasedikit=1;
            hamasedang=0;
            hamabanyak=0;
        }
        else{
            hamasedikit=0;
            hamasedang=0;
            hamabanyak=1;
        }
    if((inputhama>200)&&(inputhama<1200)){
        if(inputhama>200&&inputhama<800){
            hamasedikit=(float)((-inputhama+800)/600);
            hamasedang=(float)((inputhama-200)/600);
            hamabanyak=0;
        }
        else{
            hamasedikit=0;
            hamasedang=(float)((-inputhama+1200)/400);
            hamabanyak=(float)((inputhama-800)/400);

        }
    }
}
    void angotapestisida(float inputpestisida){
        if(inputpestisida<=30){
            pestisidasedikit=1;
            pestisidacukup=0;
            pestisidabanyak=0;
        }
        else{
            pestisidasedikit=0;
            pestisidacukup=0;
            pestisidabanyak=1;
        }
    if((inputpestisida>30)&&(inputpestisida<120)){
        if(inputpestisida>30&&inputpestisida<90){
            pestisidasedikit=(float)((-inputpestisida+90)/60);
            pestisidacukup=(float)((inputpestisida-30)/60);
            pestisidabanyak=0;
        }
        else{
            pestisidasedikit=0;
            pestisidacukup=(float)((-inputpestisida+120)/30);
            pestisidabanyak=(float)((inputpestisida-90)/30);
        }
    }
    }
    void angotahasilpanen(float inputhasilpanen){
    if(inputhasilpanen<=50){
            hasilpanensedikit=1;
            hasilpanencukup=0;
            hasilpanenbanyak=0;
        }
        else{
            hasilpanensedikit=0;
            hasilpanencukup=0;
            hasilpanenbanyak=1;
        }
   if(inputhasilpanen>50&&inputhasilpanen<150){
        if(inputhasilpanen>50&&inputhasilpanen<93){
            hasilpanensedikit=(float)((93-inputhasilpanen)/43);
            hasilpanencukup=(float)((inputhasilpanen-50)/43);
            hasilpanenbanyak=0;
        }
        else{
            hasilpanensedikit=0;
            hasilpanencukup=(float)((150-inputhasilpanen)/57);
            hasilpanenbanyak=(float)((inputhasilpanen-93)/57);

        }
    }
    }
    void cetakmember(){
        cout << "\t\t\tJumlah Hama:" <<endl;
        cout << "\t\t\tSedikit :" << hamasedikit << endl;
        cout << "\t\t\tSedang  :" << hamasedang << endl;
        cout << "\t\t\tBanyak  :" << hamabanyak << endl;
        cout << "\n\t\t\tBanyak pestisida Digunakan:" << endl;
        cout << "\t\t\tSedikit :" << pestisidasedikit <<  endl;
        cout << "\t\t\tCukup   :" << pestisidacukup <<  endl;
        cout << "\t\t\tBanyak  :" << pestisidabanyak  << endl;
        cout << "\n\t\t\tJumlah Panen Yang Didapat:"<< endl;
        cout << "\t\t\tSedikit :" << hasilpanensedikit << endl;
        cout << "\t\t\tCukup   :" << hasilpanencukup <<   endl;
        cout << "\t\t\tBanyak  :" << hasilpanenbanyak <<  endl;
    }
    void inferensi(){
        int k=0;
        float nilaiKondisi[27];
        string kondisi[27], kondisihama[10], kondisipanen[10], kondisipestisida[10];
        float nilaihama[3]={hamasedikit,hamasedang,hamabanyak};
        float nilaipestisida[3]={pestisidasedikit,pestisidacukup,pestisidabanyak};
        float nilaihasilpanen[3]={hasilpanensedikit,hasilpanencukup,hasilpanenbanyak};

        for(int i=0;i<3;i++){
          for(int j=0;j<3;j++){
            for(int l=0;l<3;l++){
                if((nilaihama[i]>0)&&(nilaipestisida[j]>0)&&(nilaihasilpanen[l]>0)){
                    if((nilaihama[i]<=nilaipestisida[j])&&(nilaihama[i]<=nilaihasilpanen[l])){
                        nilaiKondisi[k]=nilaihama[i];
                    }else if((nilaipestisida[j]<=nilaihama[i])&&(nilaipestisida[j]<=nilaihasilpanen[l])){
                        nilaiKondisi[k]=nilaipestisida[j];
                    }else {
                        nilaiKondisi[k]=nilaihasilpanen[l];
                    }

                    if   (i == 0 && j==0 && l == 0){ //1    27 RULES
                        kondisi[k]=" RUGI ";
                    }else if (i == 0 && j==0 && l == 1){ //2
                        kondisi[k]=" UNTUNG ";
                    }else if (i == 0 && j==0 && l == 2){ //3
                        kondisi[k]=" UNTUNG ";
                    }else if (i == 0 && j==1 && l == 0){ //4
                        kondisi[k]=" RUGI ";
                    }else if (i == 0 && j==1 && l == 1){ //5
                        kondisi[k]=" UNTUNG ";
                    }else if (i == 0 && j==1 && l == 2){ //6
                        kondisi[k]=" UNTUNG ";
                    }else if (i == 0 && j==2 && l == 0){ //7
                        kondisi[k]=" RUGI ";
                    }else if (i == 0 && j==2 && l == 1){ //8
                        kondisi[k]=" RUGI ";
                    }else if (i == 0 && j==2 && l == 2){ //9
                        kondisi[k]=" UNTUNG ";
                    }else if (i == 1 && j==0 && l == 0){ //10
                        kondisi[k]=" RUGI ";
                    }else if (i == 1 && j==0 && l == 1){ //11
                        kondisi[k]=" UNTUNG ";
                    }else if (i == 1 && j==0 && l == 2){ //12
                        kondisi[k]=" UNTUNG ";
                    }else if (i == 1 && j==1 && l == 0){ //13
                        kondisi[k]=" RUGI ";
                    }else if (i == 1 && j==1 && l == 1){ //14
                        kondisi[k]=" UNTUNG ";
                    }else if (i == 1 && j==1 && l == 2){ //15
                        kondisi[k]=" UNTUNG ";
                    }else if (i == 1 && j==2 && l == 0){ //16
                        kondisi[k]=" RUGI ";
                    }else if (i == 1 && j==2 && l == 1){ //17
                        kondisi[k]=" RUGI ";
                    }else if (i == 1 && j==2 && l == 2){ //18
                        kondisi[k]=" UNTUNG ";
                    }else if (i == 2 && j==0 && l == 0){ //19
                        kondisi[k]=" RUGI ";
                    }else if (i == 2 && j==0 && l == 1){ //20
                        kondisi[k]=" RUGI ";
                    }else if (i == 2 && j==0 && l == 2){ //21
                        kondisi[k]=" UNTUNG ";
                    }else if (i == 2 && j==1 && l == 0){ //22
                        kondisi[k]=" RUGI ";
                    }else if (i == 2 && j==1 && l == 1){ //23
                        kondisi[k]=" RUGI ";
                    }else if (i == 2 && j==1 && l == 2){ //24
                        kondisi[k]=" UNTUNG ";
                    }else if (i == 2 && j==2 && l == 0){ //25
                        kondisi[k]=" RUGI ";
                    }else if (i == 2 && j==2 && l == 1){ //26
                        kondisi[k]=" RUGI ";
                    }else if (i == 2 && j==2 && l == 2){ //27
                        kondisi[k]=" UNTUNG ";
                    }
                    if(i==0){
                        kondisihama[i]=" SEDIKIT ";
                    }else if(i==1){
                        kondisihama[i]=" SEDANG ";
                    }else {
                        kondisihama[i]=" BANYAK ";
                    }
                    if(j==0){
                        kondisipestisida[j]=" SEDIKIT ";
                    }else if(j==1){
                        kondisipestisida[j]=" CUKUP ";
                    }else {
                        kondisipestisida[j]=" BANYAK ";
                    }
                    if(l==0){
                        kondisipanen[l]=" SEDIKIT ";
                    }else if(l==1){
                        kondisipanen[l]=" CUKUP ";
                    }else {
                        kondisipanen[l]=" BANYAK ";
                    }

            cout<<"\tKetika Hama"<<kondisihama[i]<<" "<<nilaihama[i]<<" Pestisida "<<kondisipestisida[j]<<" "<< nilaipestisida[j]<<" Hasil Panen "<<kondisipanen[l]<<" "<< nilaihasilpanen[l]<<" \n\tMaka "<<kondisi[k]<<" dengan nilai= "<<nilaiKondisi[k]<<"\n"<<endl;
            k=k+1;

            }
            }
          }
        }

        for (int i=0;i<k;i++){
            if(kondisi[i]==" RUGI "){
                if(i==0){
                    terbesarX=nilaiKondisi[i];
                }else{
                    if(nilaiKondisi[i]>terbesarX){
                        terbesarX = nilaiKondisi[i];
                    }
                }
            }else if(kondisi[i]==" UNTUNG "){
                if(i==1){
                    terbesarY=nilaiKondisi[i];
                }else{
                    if(nilaiKondisi[i]>terbesarY){
                        terbesarY = nilaiKondisi[i];
                    }
                }
            }
        }

        cout<<endl;

        if (terbesarX>0){
            cout<<"\t\t\tNilai RUGI\t="<<terbesarX<<endl;
        }
        if(terbesarY>0){
            cout<<"\t\t\tNilai UNTUNG\t="<<terbesarY<<endl;
        }
    }
    float defuzzifikasi(int sampel){
            float pengaliX, pengaliY;
            float Penyebut = 0;
            float Defuzzi;
            int tsampel = 0;
            float jumsampelX = 0;
            float jumsampelY = 0;
            float pengaliZ[100], tsampelZ[100];
            int delta = 0;
            int k = 0;
            float tpembilang=0, tPembilangX=0, tPembilangY=0, tPembilangZ=0;
            float PembilangX[100];
            float PembilangY[100];
            float PembilangZ[100];

            pengaliX = terbesarX;
            pengaliY = terbesarY;

            delta = 100 / sampel;
            tsampel += delta;

            for(int i=1;i<=sampel;i++){
                if(tsampel <= 50){
                    PembilangX[i] = (tsampel * pengaliX);
                    jumsampelX += 1;
                    tPembilangX += PembilangX[i];
                    cout<<"\t\t Titik sampel X = "<<tsampel<<", Pengali X = "<<pengaliX<<", Pembilang= "<<PembilangX[i]<<endl;
                }else if(tsampel >= 80){
                    PembilangY[i] = (tsampel * pengaliY);
                    jumsampelY += 1;
                    tPembilangY += PembilangY[i];
                    cout<<"\t\t Titik sampel Y = "<<tsampel<<", Pengali Y = "<<pengaliY<<", Pembilang= "<<PembilangY[i]<<endl;
                }else if((tsampel > 50) && (tsampel < 80)){
                    if(pengaliX > pengaliY){
                        tsampelZ[k] = tsampel;
                        pengaliZ[k] = (int)(((80 - tsampelZ[k])/30)*1000);
                        pengaliZ[k] = (float)(pengaliZ[k]/1000);
                        PembilangZ[k] = (tsampelZ[k] * pengaliZ[k]);
                        tPembilangZ += PembilangZ[k];
                    }else{
                        tsampelZ[k] = tsampel;
                        pengaliZ[k] = (int)(((tsampelZ[k] - 50)/30)*1000);
                        pengaliZ[k] = (float)(pengaliZ[k]/1000);
                        PembilangZ[k] = (tsampelZ[k] * pengaliZ[k]);
                        tPembilangZ += PembilangZ[k];
                    }cout<<"\t\t Titik Sampel Z = "<<tsampelZ[k]<<", Pengali Z = "<<pengaliZ[k]<<", Pembilang= "<<PembilangZ[k]<<endl;
                    k += 1;
                }
                tsampel += delta;
            }
            tpembilang += (tPembilangX+tPembilangY+tPembilangZ);
            Penyebut = (jumsampelX * pengaliX) + (jumsampelY * pengaliY);

            for(int i = 0;i < k;i++){
                Penyebut += pengaliZ[i];
            }

            cout << "\n\t\t\tterbesar x\t\t= " << terbesarX << endl;
            cout << "\t\t\tterbesar y\t\t= " << terbesarY << endl;
            cout << "\t\t\tHasil Pembilang\t\t= " << tpembilang << endl;
            cout << "\t\t\tHasil Penyebut\t\t= " << Penyebut << endl;

            Defuzzi = tpembilang / Penyebut;
            return Defuzzi;
        }
    };

int main (){
    float hama;
    float pestisida;
    float panen;
    int sampel=10;
    float na;

    Fuzzy tubes;

    cout <<"\n\t\t===================INPUT DATA===================\n\n";
    cout <<"\t\t\tMasukkan Jumlah Hama       : ";cin >> hama;
    cout <<"\t\t\tMasukkan Banyak pestisida  : ";cin >> pestisida;
    cout <<"\t\t\tMasukkan Jumlah Hasil Panen: ";cin >> panen;

    cout <<"\n\t\t==================FUZZIFIKASI===================\n\n";
    tubes.angotahama(hama);
    tubes.angotapestisida(pestisida);
    tubes.angotahasilpanen(panen);
    tubes.cetakmember();
    cout <<"\n\t\t===================INFERENSI====================\n\n";
    tubes.inferensi();
    cout <<"\n\t\t================DEFUZZIFIKASI===================\n\n";
    na = tubes.defuzzifikasi(sampel);

    cout << "\t\t\tNilai Pendapatan\t= " << na;
    cout<<endl;
    return 0;
}
