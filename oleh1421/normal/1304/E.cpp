#include<bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=100010;
const int L=17;
int up[N][L+3];
int tin[N];
int tout[N];
vector<int>g[N];
int timer=0;
int h[N];
void dfs(int v,int pr){
    up[v][0]=pr;
    h[v]=h[pr]+1;
    for (int i=1;i<=L;i++){
        up[v][i]=up[up[v][i-1]][i-1];
    }
    tin[v]=++timer;
    for (auto to:g[v]){
        if (to!=pr) dfs(to,v);
    }

    tout[v]=timer;
}
bool upper(int a,int b){
    return (tin[a]<=tin[b] && tout[a]>=tout[b]);
}
int lca(int a,int b){
    if (upper(a,b)) return a;
    if (upper(b,a)) return b;
    for (int i=L;i>=0;i--){
        if (!upper(up[a][i],b)) a=up[a][i];
    }
    return up[a][0];
}
int dist(int x,int y){
    int lc=lca(x,y);
    return (h[x]+h[y]-2*h[lc]);
}
void solve(){
    int x,y,a,b,k;cin>>x>>y>>a>>b>>k;
    int dist1=dist(a,b);
    if (dist1<=k && dist1%2==k%2){
        cout<<"YES\n";
        return;
    }
    int dist2=min(dist(a,x)+dist(b,y),dist(a,y)+dist(b,x))+1;
    if (dist2<=k && dist2%2==k%2){
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    tin[0]=timer;
    dfs(1,0);
    tout[0]=timer;
    int q;cin>>q;
    while (q--){
        solve();
    }

    return 0;
}