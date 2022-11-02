#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    int a[n];
    int aa[n];
    int b[k];
    int skap=0;

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    for(int i=0; i<k; i++){
        cin >> b[i];
    }

    if(k>1) cout << "Yes";
    else{
        for(int i=0; i<n; i++){
            if(a[i]==0) a[i]=b[0];
        }

        for(int i=0; i<n; i++){
            aa[i]=a[i];
        }

        sort(aa, aa + n);

        for(int i=0; i<n; i++){
            if(a[i]!=aa[i]) skap=1;
        }

        if(skap==1) cout << "Yes";
        else cout << "No";

    }
}