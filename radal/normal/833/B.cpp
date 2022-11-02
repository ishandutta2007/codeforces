#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC target("avx2,fma")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const int N = 1e5+20,mod = 1e9+7,inf = 2e9,sq = 400;
int poww(int n,ll k){
    if (!k) return 1;
    if (k == 1) return n;
    int r = poww(n,k/2);
    return 1ll*r*r%mod*poww(n,k&1)%mod;
}
inline int mkay(int x,int y){
    if (x+y < mod) return x+y;
    return x+y-mod;
}
int dp[N][60];
vector<int> ind[N];
int seg[4*N][2],a[N],lz[4*N][2];
void upd(int l,int r,int s,int e,int v,int x,bool f){
    if (l >= e || s >= r) return;
    if (s <= l && r <= e){
        lz[v][f] += x;
        seg[v][f] += x;
        return;
    }
    int u = (v << 1), m = (l+r) >> 1;
    if (lz[v][f]){
        lz[u][f] += lz[v][f];
        lz[u|1][f] += lz[v][f];
        seg[u][f] += lz[v][f];
        seg[u|1][f] += lz[v][f];
        lz[v][f] = 0;
    }
    upd(l,m,s,e,u,x,f);
    upd(m,r,s,e,u|1,x,f);
    seg[v][f] = max(seg[u][f],seg[u|1][f]);
}
void rst(int l,int r,int v,bool f){
    lz[v][f] = 0;
    seg[v][f] = 0;
    if (r-l == 1) return;
    int m = (l+r)/2,u = (v << 1);
    rst(l,m,u,f);
    rst(m,r,u|1,f);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin >> n >> k;
    rep(i,0,n){
        cin >> a[i];
        ind[a[i]].pb(i);
    }
    rep(i,1,k+1){
        bool f = (i&1);
        rst(0,n,1,f);
        rep(j,0,n){
            if (ind[a[j]][0] == j)
                upd(0,n,0,j+1,1,1,f);
            else{
                int l = lower_bound(ind[a[j]].begin(),ind[a[j]].end(),j)-ind[a[j]].begin();
                upd(0,n,ind[a[j]][l-1]+1,j+1,1,1,f);
            }
            if (j) upd(0,n,j,j+1,1,dp[j-1][i-1],f);
            dp[j][i] = seg[1][f];
        }
    }
    cout << dp[n-1][k];
}