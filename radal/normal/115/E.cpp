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
const int N = 2e5+20,mod = 1e9+7,inf = 2e9,sq = 400;
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
ll a[N],dp[N],seg[4*N],pre[N],lz[4*N];
pair<pll,ll> r[N];
vector<int> ve[N];
void upd(int l,int r,int s,int e,ll x,int v){
    if (s <= l && r <= e){
        seg[v] += x;
        lz[v] += x;
        return;
    }
    if (s >= r || l >= e) return;
    int m = (l+r) >> 1,u = (v << 1);
    if (lz[v]){
        lz[u] += lz[v];
        seg[u] += lz[v];
        lz[u|1] += lz[v];
        seg[u|1] += lz[v];
        lz[v] = 0;
    }
    upd(l,m,s,e,x,u);
    upd(m,r,s,e,x,u|1);
    seg[v] = max(seg[u],seg[u|1]);

}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin >> n >> m;
    rep(i,0,n){
        cin >> a[i];
        pre[i] = a[i];
        if (i) pre[i] += pre[i-1];
    }
    rep(i,0,m){
        cin >> r[i].X.X >> r[i].X.Y >> r[i].Y;
        r[i].X.X--;
        r[i].X.Y--;
        ve[r[i].X.Y].pb(i);
    }
    rep(i,0,n){
        for (int u : ve[i])
            upd(0,n,0,r[u].X.X+1,r[u].Y,1);
        if(i){
            upd(0,n,i,i+1,pre[i-1]+dp[i-1],1);
            dp[i] = dp[i-1];
        }
        dp[i] = max(dp[i],seg[1]-pre[i]);
    }
    cout << dp[n-1];
}