#include <bits/stdc++.h>
#pragma GCC target("sse,sse2")
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
constexpr int N = 5e5+20,mod = 1e9+7,inf = 1e9+10,sq = 340;
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
        k /= 2;
    } 
    return z; 
}
int a[N];
inline void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    if (n > m) swap(n,m);
    ll s = 0;
    rep(i,0,k)
        cin >> a[i];
    sort(a,a+k);
    rep(i,0,k){
        if (a[i] < 2*n) continue;
        s += a[i]-a[i]%n;
    }
    if (!(a[k-1]/n == 2 && (m&1)) && s >= 1ll*n*m){
        cout << "Yes" << endl;
        return;
    }
    s = 0;
    rep(i,0,k){
        if (a[i] < 2*m) continue;
        s += a[i]-a[i]%m;
    }
    if (!(a[k-1]/m == 2 && (n&1)) && s >= 1ll*m*n){
        cout << "Yes" << endl;
        return;
    }
    cout << "No" << endl;

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