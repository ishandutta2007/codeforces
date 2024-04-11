#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse4,avx2")
#pragma GCC optimize("unroll-loops,O2")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define all(x) (x).begin() , (x).end()
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
constexpr int N = 2e5+20,mod = 1e9+7 ,inf = 1e9+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}

inline int poww(int a,int k){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k >>= 1;
    }
    return z;
}

int cnt[N];
ll ans[N];
ll seg[N*4];
vector<pair<pll,int> > q;

void build(int l,int r,int v = 1){
    if (r-l == 1){
        seg[v] = 1ll*cnt[l]*(cnt[l]-1)/2;
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    build(l,m,u);
    build(m,r,u|1);
    seg[v] = seg[u]+seg[u|1];
}

void upd(int l,int r,int p,int v = 1){
    if (r-l == 1){
        cnt[l]--;
        seg[v] = 1ll*cnt[l]*(cnt[l]-1)/2;
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    if (p < m) upd(l,m,p,u);
    else  upd(m,r,p,u|1);
    seg[v] = seg[u]+seg[u|1];
}

ll que(int l,int r,int s,int e,int v = 1){
    if (s <= l && r <= e) return seg[v];
    if (s >= r || l >= e) return 0;
    int m = (l+r) >> 1,u = (v << 1);
    return que(l,m,s,e,u)+que(m,r,s,e,u|1);
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    rep(i,1,N){
        for (int j = 1; j*i < N; j++)
            cnt[j*i]++;
    }
    rep(i,1,N) cnt[i]--;
    build(0,N);
    rep(i,0,T){
        int l,r;
        cin >> l >> r;
        q.pb({{l,r},i});
        ans[i] = 1ll*(r-l+1)*(r-l)*(r-l-1)/6;
        if (2*l > r) continue;
        int lw = (2*l+5)/6,hi = r/6;
        ans[i] -= (hi-lw+1);
        lw = (5*l/2+14)/15,hi = r/15;
        if (lw > hi) continue;
        ans[i] -= (hi-lw+1);
    }
    sort(all(q));
    int po = 0;
    rep(i,1,N){
        while (po < T && q[po].X.X == i){
            ans[q[po].Y] -= que(0,N,i,q[po].X.Y+1);
            po++;
        }
        if (po == T) break;
        for (int j = 1; j*i < N; j++){
            upd(0,N,j*i);
        }
    }
    rep(i,0,T) cout << ans[i] << endl;
}