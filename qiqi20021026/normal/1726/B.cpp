#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n,m; cin>>n>>m;
    if (m%2!=0&&n%2==0){
        cout<<"No\n";
        return;
    }
    if (n>m){
        cout<<"No\n";
        return;
    }
    cout<<"Yes\n";
    if (n%2==0){
        for (int i=1;i<=n-2;++i) cout<<1<<' ';
        cout<<(m-n+2)/2<<' '<<(m-n+2)/2<<'\n';
        return;
    }
    for (int i=1;i<n;++i) cout<<1<<' ';
    cout<<(m-n+1)<<'\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) solve();

    return 0;
}