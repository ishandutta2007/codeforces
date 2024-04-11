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
void solve(){
    string s;
    vector<ll> sz;
    vector<pair<ll,ll> > ve;
    int n,c,q;
    cin >> n >> c >> q >> s;
    sz.pb(n);
    rep(i,0,c){
        ll l,r;
        cin >> l >> r;
        l--;
        sz.pb(sz.back()+r-l);
        ve.pb({l,r});
    }
    while (q--){
        ll k;
        cin >> k;
        k--;
        int po = c;
        while (1){
            if (k < n){
                cout << s[k] << endl;
                break;
            }
            if (sz[po-1] > k){
                po--;
                continue;
            }
            k = ve[po-1].X+k-sz[po-1];
            po--;
        }
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}