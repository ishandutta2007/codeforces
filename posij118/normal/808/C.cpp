#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, w, zbyva, skap;
    cin >> n >> w;
    int cup[n];
    int a[n];
    zbyva=w;
    skap=0;

    for(int i=0; i<n; i++){
        cin >> cup[i];
    }

    for(int i=0; i<n; i++){
        a[i]=(cup[i]+1)/2;
        zbyva-=a[i];
    }

    if(zbyva<0) cout << -1;
    else{
        for(int i=100; i>0; i--){
            for(int j=0; j<n; j++){
                if(cup[j]==i){
                    a[j]=min(cup[j], zbyva+a[j]);
                    zbyva-=a[j]-(cup[j]+1)/2;
                }
                if(zbyva==0){
                        skap=1;
                        break;
                }
            }

        if(skap==1) break;
        }

       for(int i=0; i<n; i++){
        cout << a[i] << " ";
       }

    }
}