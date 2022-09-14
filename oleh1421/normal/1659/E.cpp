//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
typedef long double ld;
//#define int ll
using namespace std;
mt19937 rnd(time(NULL));
typedef long long ll;
const int N=200010;
const int K=155;
const ll inf=1000000000000000001;
const ll mod=998244353;
vector<pair<int,int> >g[N];
bool used[N];
bool good[32][N];
int cnt=0;
int cmp[32][N];
void dfs(int v,int bt,int ind){
    cmp[bt][v]=ind;
    used[v]=true;
    for (auto cur:g[v]){
        int to=cur.first;
        int w=cur.second;
        if (w&(1<<bt)){
            if (!used[to]){
                dfs(to,bt,ind);
            }
        }
        if (!(w&1)) good[bt][ind]=true;
    }
}
int get(int u,int v){
    for (int i=0;i<30;i++){
        if (cmp[i][u]==cmp[i][v]) return 0;
    }
    for (int i=1;i<30;i++){
        if (good[i][cmp[i][u]]) return 1;
    }
    return 2;
}
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=m;i++){
        int a,b,c;cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    for (int bt=0;bt<30;bt++){
        cnt=0;
        for (int i=1;i<=n;i++){
            if (!used[i]){
                cnt++;
                dfs(i,bt,cnt);
            }
        }
        for (int i=1;i<=n;i++) used[i]=false;
        cnt=0;
    }
    int q;cin>>q;
    for (int it=1;it<=q;it++){
        int u,v;cin>>u>>v;
        cout<<get(u,v)<<endl;
    }





}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }

    return 0;
}
/**
6 7
1 2 1
2 3 3
3 1 5
4 5 2
5 6 4
6 4 6
3 4 1
1
5 1

**/