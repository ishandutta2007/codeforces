#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int f[30];
    f[0]=1;
    f[1]=1;
    for(int i=2; i<30; i++){
        f[i]=f[i-1]+f[i-2];
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<30; j++){
            if(f[j]==i){
                cout << 'O';
                break;
            }

            if(j==29) cout << 'o';
        }


    }

}