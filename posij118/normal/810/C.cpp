#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n, dva, suma;
    suma=0;
    dva=1;
    cin >> n;

    int x[n];
    for(int i=0; i<n; i++){
        cin >> x[i];
    }

    long long int mocniny[n];
    for(int i=0; i<n; i++){
        mocniny[i]=dva;
        dva*=2;
        dva%=(1000000000+7);
    }

    sort(x, x+n);

    long long int pref[n];
    for(int i=0; i<n; i++){
        if(i<1) pref[i]=0;
        else{
            pref[i]=2*pref[i-1]+(mocniny[i]-1)*(x[i]-x[i-1]);
            pref[i]%=1000000000+7;

        }
    }

    for(int i=0; i<n; i++){
        suma+=pref[i];
    }

    suma%=1000000000+7;

    cout << suma;

}