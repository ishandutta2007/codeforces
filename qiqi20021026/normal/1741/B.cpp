#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--){
        int n; cin>>n;
        if (n==3){
            cout<<"-1\n";
            continue;
        }
        if (n%2==0){
            for (int i=n;i;--i) cout<<i<<" \n"[i==1];
        }
        else{
            cout<<n-2<<' '<<n-1<<' '<<n;
            for (int i=1;i<n-2;++i) cout<<' '<<i;
            cout<<'\n';
        }
    }
}