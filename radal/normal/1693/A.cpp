#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse4,avx2")
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
constexpr int N = 3e5+20,mod = 998244353,inf = 1e9+10;
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
ll a[N],l[N],r[N];
inline void solve(){
    int n;
    ll sum = 0;
    cin >> n;
    rep(i,0,n){
        cin >> a[i];
        sum += a[i];
        l[i] = r[i] = 0;
    }
    if (n == 1){
        cout << ((a[0]) ? "NO" : "YES") << endl;
        return;
    }
    if (sum){
        cout << "NO" << endl;
        return;
    }
    r[0] = a[0];
    l[1] = r[0];
    rep(i,1,n-1){
        r[i] = a[i]+l[i];
        l[i+1] = r[i];
    }
    rep(i,0,n){
        if (min(l[i],r[i]) < 0 || r[i]-l[i] != a[i] || (i && !r[i-1] && r[i])){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" <<endl;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}