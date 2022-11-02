#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,avx2")
#pragma GCC optimize("unroll-loops,O3")
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
constexpr int N = 5e5+10,mod = 1e9+7,inf = 1e9+10;
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
int fen[N],a[N],ans[N];
int n;
vector<pll> ve;
vector<pair<pll,int> > Q;
void upd(int r){
    for (; r < n; r |= (r+1))
        fen[r]++;
}
int que(int l){
    int ans = 0;
    for (; l >= 0; l = (l&(l+1))-1)
        ans += fen[l];
    return ans;
}
void solve(){
    cin >> n;
    rep(i,0,n){
        int x;
        cin >> x;
        a[i] = x;
        ve.pb({-x,i});
    }
    sort(all(ve));
    int m;
    cin >> m;
    rep(i,0,m){
        int k,j;
        cin >> k >> j;
        Q.pb({{k,j},i});
    }
    sort(all(Q));
    int po = 0;
    rep(i,0,m){
        int k = Q[i].X.X,j = Q[i].X.Y,ind = Q[i].Y;
        while (po < k){
            upd(ve[po].Y);
            po++;
        }
        int l = -1,r = n,mid;
        while (r-l > 1){
            mid = (l+r) >> 1;
            if (que(mid) >= j) r = mid;
            else l = mid;
        }
        ans[ind] = a[r];
    }
    rep(i,0,m) cout << ans[i] << endl;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    //cin >> T;
    while (T--){
        solve();
    }
    return 0;
}