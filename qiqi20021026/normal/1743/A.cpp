#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin>>n;
    for (int i=1;i<=n;++i){int x; cin>>x;}
    int ans=3*(10-n)*(10-n-1);
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) solve();
}