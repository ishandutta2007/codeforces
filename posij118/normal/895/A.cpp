#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, su, mi;
    mi=360;
    cin >> n;

    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    if(n==1){
        cout << "360";
        return 0;
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n+1; j++){
            su=0;
            for(int k=i; k<j; k++){
                su+=a[k];
            }

            mi=min(mi, abs(180-su)*2);
        }
    }

    cout << mi;

}