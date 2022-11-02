#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n, k, nula;
    long long int suma;
    long double podil, kk;
    suma=0;
    nula=0;
    cin >> n >> k;
    long long int sleep[n];

    for(int i=0; i<n; i++){
        cin >> sleep[i];
    }

    for(int i=0; i<n; i++){
        if(i<k-1 && i>n-k) suma+=max(nula,(k-(k-i-1)-(k-(n-i))))*sleep[i];
        else if(i>n-k) suma+=(n-i)*sleep[i];
        else if(i<k-1) suma+=(i+1)*sleep[i];
        else suma+=k*sleep[i];
    }

    kk=k;
    podil=suma/(n-kk+1);
    cout << setprecision(20) << podil;
}