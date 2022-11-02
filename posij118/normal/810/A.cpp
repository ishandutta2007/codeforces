#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long int kl;
    cin >> n >> kl;

    int znamky[n];
    for(int i=0; i<n; i++){
        cin >> znamky[i];
    }
    long long int suma;
    int pocet;
    suma=0;
    pocet=n;

    for(int i=0; i<n; i++){
        suma+=znamky[i];
    }


    while(2*suma<(2*kl-1)*pocet){
        pocet++;
        suma+=kl;
    }

    cout << pocet-n;
}