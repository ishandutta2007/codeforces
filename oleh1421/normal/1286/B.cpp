//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
///use char if you want a naive algorithm to pass
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
const int N=2003;
int a[N];
int c[N];
int p[N];
vector<pair<int,int> >u[N];
vector<int>g[N];
vector<int>x[N];
void dfs(int v){
    for (auto to:g[v]) {
        dfs(to);
        for (auto x:u[to]) u[v].push_back(x);
    }
    sort(u[v].begin(),u[v].end());
    if (u[v].size()<c[v]){
        cout<<"NO";
        exit(0);
    }
    if (c[v]==0) a[v]=1;
    else a[v]=u[v][c[v]-1].first+1;
    for (int i=c[v];i<u[v].size();i++){
        u[v][i].first+=2;
        a[u[v][i].second]+=2;
    }
    u[v].push_back({a[v],v});
    sort(u[v].begin(),u[v].end());
}
void dfs1(int v){
    x[v]={a[v]};
    for (auto to:g[v]) {
        dfs1(to);
        for (auto i:x[to]) x[v].push_back(i);
    }
    sort(x[v].begin(),x[v].end());
    int cur=lower_bound(x[v].begin(),x[v].end(),a[v])-x[v].begin();
    if (cur!=c[v]){
        cout<<"NO";
        exit(0);
    }

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    int root=-1;
    for (int i=1;i<=n;i++){
        cin>>p[i]>>c[i];
        if (!p[i]) root=i;
        else g[p[i]].push_back(i);
    }
    dfs(root);
    //dfs1(root);

    cout<<"YES\n";
    for (int i=1;i<=n;i++) cout<<a[i]<<" ";
    return 0;
}