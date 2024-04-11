#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2")
//#pragma GCC optimize("unroll-loops,O3")
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
constexpr int N = 1e5+5,mod = 1e9+7,inf = 1e9+10;
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
int l[N],r[N],m[N],cnt[N];
bool mark[N];
vector<int> ask[N],taj[N],ve,pr[N];
int za[N][64];
inline void ad(int x){
    int sz = pr[x].size();
    int y = (1 << sz);
    rep(i,0,y)
        cnt[za[x][i]]++;
}
inline void rem(int x){
    int sz = pr[x].size();
    int y = (1 << sz);
    rep(i,0,y)
        cnt[za[x][i]]--;
}
inline int calc(int x){
    int ans = 0;
    int sz = pr[x].size();
    int y = (1 << sz);
    rep(i,0,y){
        if (__builtin_popcount(i)%2)
            ans -= cnt[za[x][i]];
        else
            ans += cnt[za[x][i]];
    }
    return ans;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    rep(i,2,N){
        for(int j = 1; j * i < N; j++){
            taj[j*i].pb(i);
            if (j > 1) mark[j*i] = 1;
            if (!mark[i]) pr[j*i].pb(i);
        }
        za[i][0] = 1;
        int sz = pr[i].size();
        int y = (1 << sz);
        rep(j,1,y){
            int ct = __builtin_ctz(j);
            za[i][j] = za[i][j^(1 << ct)]*pr[i][ct];
        }
    }
    int n;
    cin >> n;
    rep(i,0,n){
        int x;
        cin >> x;
        ve.pb(x);
    }
    sort(all(ve));
    ve.resize(unique(all(ve))-ve.begin());
    n = ve.size();
    ll ans = ve[n-1];
    rep(i,0,n){
        for (int u : taj[ve[i]]){
            if (u == ve[i]) continue;
            ve.pb(u);
        }
    }
    ve.pb(1);
    sort(all(ve));
    ve.resize(unique(all(ve))-ve.begin());
    n = ve.size();
    rep(i,0,n)
        r[i] = n;
    while (1){
        bool fl = 0;
        rep(i,0,n){
            if (r[i]-l[i] > 1){
                m[i] = (l[i]+r[i]) >> 1;
                ask[m[i]].pb(i);
                fl = 1;
            }
        }
        if (!fl) break;
        repr(i,n-1,0){
            ad(ve[i]);
            for (int j : ask[i]){
                if (calc(ve[j]) == 0)
                    r[j] = m[j];
                else
                    l[j] = m[j];
            }
            ask[i].clear();
        }
        rep(i,0,n)
            rem(ve[i]);
    }
    rep(i,0,n) ans = max(ans,1ll*ve[i]*ve[l[i]]);
    cout << ans;
    return 0;
}