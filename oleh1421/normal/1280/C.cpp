#include <bits/stdc++.h>
typedef long long ll;
const long long mod=1000000007ll;
#define endl '\n'
using namespace std;
vector<pair<int,int> >g[300001];
ll sz[300001];
ll dp[300001];
ll dp1[300001];
ll n;
void dfsinit(int v,int pr){
    sz[v]=1;
    for (auto cur:g[v]){
        int to=cur.first;
        if (to==pr) continue;
        dfsinit(to,v);
        sz[v]+=sz[to];
    }
}
void dfs(int v,int pr){
    dp[v]=0;
    for (auto cur:g[v]){
        int to=cur.first;
        ll w=cur.second;
        if (to==pr) continue;
        dfs(to,v);
        dp[v]+=dp[to]+(sz[to]%2)*w;
    }
}
void dfs1(int v,int pr){
    dp1[v]=0;
    int cnt=1;
    vector<pair<ll,ll> >u;
    for (auto cur:g[v]){
        int to=cur.first;
        int w=cur.second;
        if (to==pr) continue;
        dfs1(to,v);
        dp1[v]+=dp1[to]+min(sz[to],n-sz[to])*w;
    }
}
void solve(){
    cin>>n;
    n+=n;
    for (int i=0;i<=n;i++) g[i].clear();
    for (int i=1;i<n;i++){
        int a,b,c;cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    dfsinit(1,0);
    dfs(1,0);
    dfs1(1,0);
    cout<<dp[1]<<" "<<dp1[1]<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}