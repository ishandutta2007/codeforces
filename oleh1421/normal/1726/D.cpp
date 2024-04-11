//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,sse")
#include <bits/stdc++.h>
#define y1 y_1
//#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
//#define prev aboba
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<vector<char> >frame;
const int N=600010;
const ll mod=998244353;
const ll inf=1e18;
int a[N],b[N];
vector<pair<int,int> >g[N];
bool used[N];
bool st[N];
void dfs(int v){
    used[v]=true;
    for (auto [to,ind]:g[v]){
        if (!used[to]){
            dfs(to);
            st[ind]=true;
        }
    }
}
int deg[N];
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++){
        g[i].clear();
        deg[i]=0;
    }
    for (int i=1;i<=m;i++){
        used[i]=false;
        st[i]=false;
        cin>>a[i]>>b[i];
        g[a[i]].push_back({b[i],i});
        g[b[i]].push_back({a[i],i});
    }
    dfs(1);
    vector<int>cyc;
    for (int i=1;i<=m;i++){
        if (!st[i]){
            cyc.push_back(i);
            deg[a[i]]++;
            deg[b[i]]++;
        }
    }
    int cnt=0;
    for (int i=1;i<=n;i++) cnt+=(deg[i]==2);
    if (cnt<3){
        for (int i=1;i<=m;i++) cout<<st[i];
        cout<<'\n';
        return;
    }

//    exit(1);
    for (int i=1;i<=n;i++) {
        g[i].clear();
        used[i]=false;
    }
    g[a[cyc[0]]].push_back({b[cyc[0]],cyc[0]});
    g[b[cyc[0]]].push_back({a[cyc[0]],cyc[0]});
    for (int i=1;i<=m;i++){
        if (st[i]){
            g[a[i]].push_back({b[i],i});
            g[b[i]].push_back({a[i],i});
            st[i]=false;
        }
    }
    dfs(a[cyc[0]]);
    for (int i=1;i<=m;i++) cout<<st[i];
    cout<<'\n';



}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;

    while (tt--){
        solve();
    }
    return 0;

}
///WRONG CYCLE
//124x
//xx3_
//xxxx



/*
5 7
1 2
2 3
3 4
4 5
5 1
1 3
3 5
*/