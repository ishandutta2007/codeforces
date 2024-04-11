#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse4,avx2")
//#pragma GCC optimize("unroll-loops,O2")
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
constexpr int N = 2e5+10,mod = 1e9+7,inf = 1e9+10;
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
int fen[N],n,nn,a[N],b[N],c[N],d[N];
inline void upd(int r){
    for (; r <= nn; r |= (r+1))
        fen[r]++;
}
inline int que(int r){
    r--;
    int ans = 0;
    for (; r >= 0; r = (r&(r+1))-1)
        ans += fen[r];
    return ans;
}
inline bool cmp(pair<pll,int> i,pair<pll,int> j){
    if (i.X.Y != j.X.Y) return (j.X.Y < i.X.Y);
    return (j < i);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n;
    nn = 2*n;
    vector<pll> ve;
    rep(i,0,n){
        pll p;
        cin >> p.X >> p.Y;
        if (p.X > p.Y) swap(p.X,p.Y);
        ve.pb(p);
    }
    sort(all(ve));
    rep(i,0,n){
        pll p = ve[i];
        a[i] = que(nn-p.Y);
        upd(nn-p.Y);
    }
    memset(fen,0,sizeof fen);
    repr(i,n-1,0){
        pll p = ve[i];
        b[i] = que(p.Y);
        upd(p.Y);
    }
    memset(fen,0,sizeof fen);
    vector<pair<pll,int> > ve2;
    rep(i,0,n){
        pll p = ve[i];
        ve2.pb({p,i});
        d[i] = que(p.X);
        upd(p.Y);
    }
    memset(fen,0,sizeof fen);
    sort(all(ve2),cmp);
    rep(i,0,n){
        auto p = ve2[i];
        d[p.Y] += que(nn-p.X.Y);
        c[p.Y] = n-a[p.Y]-b[p.Y]-d[p.Y]-1;
        upd(nn-p.X.X);
    }
    ll ans = 1ll*n*(n-1)*(n-2)/6,s = 0;
    rep(i,0,n){
        ans -= 1ll*b[i]*(a[i]+d[i]);
        s += 1ll*c[i]*(n-1-c[i]);
    }
    ans -= s/2;
    cout << ans;
}