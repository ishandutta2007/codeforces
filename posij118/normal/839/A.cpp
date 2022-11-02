#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k, cnt, g;
    cnt=0;
    g=0;
    cin >> n >> k;

    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    for(int i=0; i<n; i++){
        cnt+=a[i];
        g+=min(cnt, 8);
        cnt=max(cnt-8, 0);
        if(g>=k){
            cout << i+1;
            break;
        }

        if(i==n-1) cout << "-1";
    }

}