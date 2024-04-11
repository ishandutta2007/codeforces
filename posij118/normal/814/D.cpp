#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    long long int n, suma, a, b;
    suma=0;
    cin >> n;
    long long int kruhy[n][2];
    long long int polomer[n];
    for(int i=0; i<n; i++){
        cin >> kruhy[i][0] >> kruhy[i][1] >> polomer[i];

    }

    for(int i=0; i<n; i++){
        kruhy[i][0]+=1000000;
        kruhy[i][1]+=1000000;
        polomer[i]=polomer[i]*4830000000000 + kruhy[i][1]*2300000+kruhy[i][0];
    }

    sort(polomer, polomer + n);
    reverse(polomer, polomer + n);

    for(int i=0; i<n; i++){
        kruhy[i][0]=polomer[i]%2300000;
        kruhy[i][1]=polomer[i]%4830000000000;
        kruhy[i][1]/=2300000;
        polomer[i]/=4830000000000;
    }



    int strom[n];
    strom[0]=-1;

    for(int i=1; i<n; i++){
        for(int j=i-1; j>-1; j--){
            if( (kruhy[j][0]-kruhy[i][0])*(kruhy[j][0]-kruhy[i][0])+(kruhy[j][1]-kruhy[i][1])*(kruhy[j][1]-kruhy[i][1])<polomer[j]*polomer[j] ){
                strom[i]=j;
                break;
            }

            if(j==0) strom[i]=-1;
        }
    }

    for(int i=0; i<n; i++){
        a=0;
        b=i;
        while(strom[b]!=-1){
            b=strom[b];
            a++;
        }

        if(a%2==1 || a==0) suma+=polomer[i]*polomer[i];
        else suma-=polomer[i]*polomer[i];
    }

    long double obsah;
    obsah=3.14159265358979323*suma;
    
    cout << setprecision(15) << obsah;

}