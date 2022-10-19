#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin>>n;
    cout<<1<<' ';
    for (int i=3;i<=n;++i) cout<<i<<' ';
    cout<<2<<'\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) solve();
}