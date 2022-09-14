#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=2000100;
const ll mod=998244353;
int x[N],y[N],z[N];
vector<pair<int,int> >g[N];
int a[N],b[N],p[N];
bool OK=true;
int c[N];
void dfs(int v){
    for (auto cur:g[v]){
        int to=cur.first;
        int w=cur.second;
        if (c[to]==0){
            c[to]=(c[v]^w);
            dfs(to);
        } else if (c[to]!=(c[v]^w)){
            OK=false;
        }
    }
}
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<n;i++){
        cin>>x[i]>>y[i]>>z[i];
        if (z[i]!=-1){
            g[x[i]].push_back({y[i],__builtin_popcount(z[i])%2});
            g[y[i]].push_back({x[i],__builtin_popcount(z[i])%2});
        }
    }
    for (int i=1;i<=m;i++){
        cin>>a[i]>>b[i]>>p[i];
        g[a[i]].push_back({b[i],p[i]});
        g[b[i]].push_back({a[i],p[i]});
    }
    for (int i=1;i<=n;i++){
        if (c[i]==0){
            c[i]=2;
            dfs(i);
        }
    }
    if (!OK){
        cout<<"NO\n";
    } else {
        cout<<"YES\n";
        for (int i=1;i<n;i++){
            if (z[i]==-1) z[i]=(c[x[i]]^c[y[i]]);
//            else if (__builtin_popcount(z[i])%2!=(c[x[i]]^c[y[i]])) exit(1);
            cout<<x[i]<<" "<<y[i]<<" "<<z[i]<<endl;
        }
    }
    for (int i=1;i<=n;i++) g[i].clear(),c[i]=0;
    OK=true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**

4
3 3
1 2 -1
1 3 -1
1 2 0
1 3 1
2 3 0
2 1
1 2 1
1 2 0
6 5
1 2 -1
1 3 1
4 2 7
6 3 0
2 5 -1
2 3 1
2 5 0
5 6 1
6 1 1
4 5 1
5 3
1 2 -1
1 3 -1
1 4 1
4 5 -1
2 4 0
3 4 1
2 3 1


**/