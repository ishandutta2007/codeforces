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
constexpr int N = 3e5+20,mod = 998244353 ,inf = 1e9+10;

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
int a[N],b[N];
ll fib[N];
bool vis[60];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline void solve(){
    int k;
    cin >> k;
    ll s = 0;
    rep(i,0,k){
        cin >> a[i];
        s += a[i];
    }
    int t = -1;
    sort(a,a+k);
    if (k >= 46 || a[k-1] < fib[k-1]){
        cout << "NO" << endl;
        return;
    }
    rep(i,k-1,58){
        if (s == fib[i+2]-1){
            t = i;
            break;
        }
        if (s < fib[i+2]-1) break;
    }
    if (t == -1){
        cout << "NO" << endl;
        return;
    }
    vector<int> ve;
    rep(i,0,k) ve.pb(i);
    rep(x,0,20){
        memset(vis,0,sizeof vis);
        rep(i,0,k) b[i] = a[i];
        bool fl = 1;
        for(int i : ve){
            repr(j,t,0){
                if (vis[j] || fib[j] > a[i]) continue;
                vis[j] = 1;
                a[i] -= fib[j];
                j--;
                if (!a[i]) break;
            }
            if (a[i]){
                fl = 0;
                break;
            }
        }
        if (fl){
            cout << "YES" << endl;
            return;
        }
        rep(i,0,k) a[i] = b[i];
        shuffle(all(ve),rng);
    }
    cout << "NO" << endl;
}
int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    fib[0] = fib[1] = 1;
    rep(i,2,60){
        fib[i] = fib[i-2]+fib[i-1];
    }
    while (T--){
        solve();
    }
}