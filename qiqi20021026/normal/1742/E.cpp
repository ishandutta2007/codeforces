#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

void solve(){
    LL n,m; cin>>n>>m;
    vector<LL> a(n+1),s(n+1);
    multiset<pair<LL,LL>> se;
    se.insert({0,0});
    for (LL i=1;i<=n;++i){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
        a[i]=max(a[i-1],a[i]);
        se.insert({a[i],s[i]});
    }
    for (LL i=1;i<=m;++i){
        LL x; cin>>x;
        auto it=se.upper_bound({x+1,-1});
        --it;
        cout<<(*it).second<<" \n"[i==m];
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    LL T; cin>>T;
    while (T--){
        solve();
    }
}