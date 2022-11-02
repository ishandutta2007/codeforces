#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n, skap, pole;
    skap=0;
    cin >> n;

    int a[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a[j][i]>1){
                pole=0;
                for(int k=0; k<n; k++){
                    for(int l=0; l<n; l++){
                        if(a[l][i]+a[j][k]==a[j][i]) pole=1;
                    }
                }

                if(pole==0) skap=1;

            }
        }
    }

    if(skap==1) cout << "No";
    else cout << "Yes";
}