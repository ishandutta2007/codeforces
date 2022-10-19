#include<bits/stdc++.h>

using namespace std;

int cnt[105];

void solve(){
    int n,m; cin>>n>>m;
    memset(cnt,0,sizeof cnt);
    int ans=0;
    for (int i=1;i<=n;++i){
        int x; cin>>x;
        ++cnt[x];
        if (cnt[x]<=m) ++ans;
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) solve();
}