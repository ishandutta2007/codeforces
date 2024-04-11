#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--){
        int n; cin>>n;
        int a[2];
        a[0]=a[1]=1<<30;
        cout<<(1<<20)<<' ';
        a[1]^=1<<20;
        for (int i=2;i<=n-2;++i){
            cout<<i<<' ';
            a[i&1]^=i;
        }
        cout<<a[(n&1)^1]<<' '<<a[n&1]<<'\n';
    }

    return 0;
}