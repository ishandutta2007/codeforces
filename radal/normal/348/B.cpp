#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)

using namespace std;

typedef long long  int ll;
typedef pair<ll,ll> pll;

const long long int N=1e5+30,mod = 1e9+7,inf=1e18;
const long double eps = 0.0001;

int n;
vector <int> adj[N];
ll a[N],d[N],sum;
void dfs(int v,int p){
    for (int u : adj[v]){
        if (u != p){
            dfs(u,v);
            d[v] = lcm(d[v],d[u]);
            if (d[v] > 1e16){
                cout << sum;
                exit(0);
            }
        }
    }
    int c = adj[v].size();
    if (p != -1) c--;
    if (c) d[v] *= c;
    if (d[v] > 1e16){
        cout << sum; 
        exit(0);
    }
    return;
}
void dfs2(int v,int p){
    int c = adj[v].size();
    if (p != -1) c--;
    if (c){
        for (int u : adj[v]){
            if (u != p){
                d[u] = d[v]/c;
                dfs2(u,v);
            }
        }
    }
    return;

}
int main(){
    ios :: sync_with_stdio(0); cout.tie(0);
    cin >> n;
    rep(i,1,n+1){
        cin >> a[i];
        sum += a[i];
        d[i] = 1;
    }
    rep(i,0,n-1){
        int x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    ll mi = inf;
    dfs(1,-1);
    dfs2(1,-1);
    rep (i,2,n+1) if (adj[i].size() == 1) mi = min(mi,a[i]/d[i]);
    cout << sum-mi*d[1]-a[1] << endl;
    return 0;
}