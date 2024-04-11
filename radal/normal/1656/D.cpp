#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;

constexpr int N = 4e5+20,mod = 1e9+7,inf = 1e9+10,maxm = (1 << 18)+10;
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
    ll n;
    cin >> n;
    if (__builtin_popcountll(n) == 1){
        cout << -1 << endl;
        return;
    }
    int z = 1;
    while (z < 2*inf){
        if (n%z) break;
        z *= 2;
        if (2*n < 1ll*z*(z+1)) break;
        if ((n/(z/2))&1){
            cout << z << endl;
            return;
        }
    }
    ll za = 1;
    int Ctz = __builtin_ctzll(n);
    ll x = (1 << Ctz)-1;
    if (x > 1 && x*(x+1) <= 2*n && n%x == 0){
        cout << x << endl;
        return;
    }
    while (n%2 == 0){
        n /= 2; 
        za *= 2;
    }
    if (n*(n+1) <= 2*n*za){
        cout << n << endl;
        return;
    }
    for (int i = 3; i < 9; i += 2){
        if (i*(i+1) > 2*n*za) break;
        if (n%i == 0){
            cout << i << endl;
            return;
        }
    }
    vector<int> incre = {4, 2, 4, 2, 4, 6, 2, 6};
    int i = 0;
    for (int d = 7; 1ll*(d+1)*d <= 2*n*za; d += incre[i++]) {
        while (n % d == 0) {
            cout << d << endl;
            return;
        }
        if (i == 8)
            i = 0;
    }
    cout << -1 << endl;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin  >> T;
    while (T--) solve();
}