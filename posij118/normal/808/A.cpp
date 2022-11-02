#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, cifry, nn, mocnina, a;
    cin >> n;
    cifry=0;
    nn=n;
    mocnina=1;

    while(nn>0){
        cifry++;
        nn/=10;
    }

    for(int i=0; i<cifry-1; i++){
        mocnina*=10;
    }

    a=(-n)%mocnina;

    cout << a+mocnina;



}