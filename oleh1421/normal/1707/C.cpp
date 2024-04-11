//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#define y2 y_2
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
//#define int ll
typedef long long ll;
typedef long double ld;
const int N=553010;
const ll mod=998244353;
const int inf=2e9;
const int Lg=30;
mt19937_64 rnd(time(NULL));
int a[N],b[N];
vector<int>g[N];
bool mst[N];
int dsu[N];
int get(int x){
    if (x==dsu[x]) return x;
    return dsu[x]=get(dsu[x]);
}
int up[N][Lg];
int tin[N],tout[N];
int timer=0;
void dfs(int v,int pr){
    up[v][0]=pr;
    for (int i=1;i<Lg;i++){
        up[v][i]=up[up[v][i-1]][i-1];
    }
    tin[v]=++timer;
    for (int to:g[v]){
        if (to==pr) continue;
        dfs(to,v);
    }
    tout[v]=timer;
}
bool upper(int a,int b){
    return (tin[a]<=tin[b] && tin[b]<=tout[a]);
}
int lca(int a,int b){
    if (upper(a,b)) return a;
    if (upper(b,a)) return b;
    for (int i=Lg-1;i>=0;i--){
        if (!upper(up[a][i],b)) a=up[a][i];
    }
    return up[a][0];
}

int t[N];
void upd(int pos,int x){
    for (;pos<N;pos|=pos+1) t[pos]+=x;
}
int G(int pos){
    int sum=0;
    for (;pos>=0;pos&=pos+1,pos--) sum+=t[pos];
    return sum;
}
void add(int l,int r,int x){
    upd(l,x);
    upd(r+1,-x);
}
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++) dsu[i]=i;
    for (int i=1;i<=m;i++){
        cin>>a[i]>>b[i];
        int x=get(a[i]);
        int y=get(b[i]);
        if (x!=y){
            dsu[x]=y;
            mst[i]=true;
        } else mst[i]=false;
        if (mst[i]){
            g[a[i]].push_back(b[i]);
            g[b[i]].push_back(a[i]);
        }
    }
    tin[0]=timer;
    dfs(1,0);
    tout[0]=timer;
    for (int i=1;i<=m;i++){
        if (mst[i]) continue;
        if (tin[a[i]]>tin[b[i]]) swap(a[i],b[i]);
        if (upper(a[i],b[i])){
            int last=b[i];
            for (int j=Lg-1;j>=0;j--){
                if (!upper(up[last][j],a[i])) last=up[last][j];
            }
            add(tin[last],tout[last],1);
            add(tin[b[i]],tout[b[i]],-1);
        } else {
            add(tin[1],tout[1],1);
            add(tin[a[i]],tout[a[i]],-1);
            add(tin[b[i]],tout[b[i]],-1);
        }
    }
    for (int i=1;i<=n;i++){
        cout<<(G(tin[i])==0);
    }
    cout<<endl;





}
int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
//    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}

/**
13 4
5 6 7 8 9 10 11 12 13 1 2 3 4
5 6 7 8 1 10 11 12 13 2 3 4 9

**/