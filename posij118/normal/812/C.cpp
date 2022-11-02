#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    long long int n, S, k, suma, T;
    cin >> n >> S;

    long long int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    long long int s[n];

    int dmez, hmez;
    dmez=-1;
    hmez=50000;

    for(int j=0; j<40; j++){
        k=(dmez+hmez)/2;

        for(int i=0; i<n; i++){
            s[i]=a[i]+(i+1)*k;
        }

        sort(s, s + n);
        suma=0;
        T=0;

        if(k>n) hmez=k;

        else{

        for(int i=0; i<k; i++){
            suma+=s[i];
        }
        if(hmez-dmez==1 && suma<=S){
                hmez=k;
                T=suma;
        }

        else if(suma<=S){
            T=suma;
            dmez=k;
        }

        else hmez=k;

        }
    }

    cout << dmez << " " << T;

}