#include<bits/stdc++.h>
typedef long long ll;
#define endl '\n'

using namespace std;
const int N=500010;
vector<pair<int,int> >g[N];
vector<int>order;
bool used[N];
void dfs(int v){
    used[v]=true;
    for (auto cur:g[v]){
        int to=cur.first;
        if (cur.second<0 || used[to]) continue;
        dfs(to);
    }
    order.push_back(v);
}
int comp[N];
void dfs1(int v){
    for (auto cur:g[v]){
        int to=cur.first;
        if (cur.second>0 || comp[to]) continue;
        comp[to]=comp[v];
        dfs1(to);
    }
}
ll G[N];
bool used2[N];
ll d[N];
void dfs2(int v){
    used2[v]=true;
    for (auto cur:g[v]){
        int to=cur.first;
        if (comp[to]!=comp[v]) continue;
        if (used2[to]){
            G[comp[v]]=__gcd(G[comp[v]],abs(cur.second+d[v]-d[to]));
        } else {
            d[to]=d[v]+cur.second;
            dfs2(to);
        }
    }
}
int sz[N];
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=m;i++){
        int a,b,l;cin>>a>>b>>l;
        g[a].push_back({b,l});
        g[b].push_back({a,-l});
    }
    for (int i=1;i<=n;i++){
        if (!used[i]){
            dfs(i);
        }
    }
    reverse(order.begin(),order.end());
    int cnt=0;
    for (int v:order){
        if (comp[v]) continue;
        comp[v]=++cnt;
        dfs1(v);
    }
    order.clear();
    for (int i=1;i<=n;i++){
        if (!used2[i]){
            dfs2(i);
        }
    }
    for (int i=1;i<=n;i++) sz[comp[i]]++;
    int q;cin>>q;
    for (int i=1;i<=q;i++){
        ll v,s,t;cin>>v>>s>>t;
//        if (s==0){
//            cout<<"YES\n";
//            continue;
//        }
//        if (sz[comp[v]]==1){
//            cout<<"NO\n";
//            continue;
//        }
        if (s%__gcd(G[comp[v]],t)){
            cout<<"NO\n";
        } else {
            cout<<"YES\n";
        }
    }


}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/**
1
4 0 4
4 4 4 3



**/