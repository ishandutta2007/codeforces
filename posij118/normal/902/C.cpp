#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, sum, skap, lb, ub, x;
    sum=0;
    skap=0;
    cin >> h;

    int a[h+1];
    for(int i=0; i<h+1; i++){
        cin >> a[i];
        sum+=a[i];
    }

    int par[sum];
    par[0]=0;
    int par2[sum];
    par2[0]=0;

    for(int i=0; i<h; i++){
        if(a[i]>=2 && a[i+1]>=2) skap=1;
    }

    x=1;
    if(skap==1){
        cout << "ambiguous" << endl;

        lb=0;
        ub=1;
        for(int i=1; i<h+1; i++){
            if((ub-lb)>=2){
                par[x]=lb+1;
                x++;
                for(int j=0; j<a[i]-1; j++){
                    par[x]=lb+2;
                    x++;
                }
            }

            else{
                for(int j=0; j<a[i]; j++){
                par[x]=lb+1;
                x++;
                }
            }

            ub=x;
            lb=x-a[i];
        }

        x=1;
        lb=0;
        for(int i=1; i<h+1; i++){
            for(int j=0; j<a[i]; j++){
                par2[x]=lb+1;
                x++;
            }
            lb+=a[i];
        }

        for(int i=0; i<sum; i++){
            cout << par[i] << " ";
        }
        cout << endl;
        for(int i=0; i<sum; i++){
            cout << par2[i] << " ";
        }
    }

    else cout << "perfect";





}