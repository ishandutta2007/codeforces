#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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
typedef long double ld;
typedef pair<int,int> pll;
const long long int N = 2e5+20,mod = 1e9+7,inf = 1e9+10,sq = 300;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int a,int k){
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k >>= 1;
    }
    return z;
}
bool vis[N];
void solve(){
    int n,k;
    cin >> n >> k;
    if (k < n-1){
        cout << n-1 << ' ' << k << endl;
        vis[k] = 1;
        vis[n-1] = 1;
        if (k != 0 && n-k-1 != k){
            cout << 0 << ' ' << n-k-1 << endl;
            vis[0] = 1;
            vis[n-1-k] = 1;
        }
        rep(i,0,n){
            if (vis[i] || i >= n-1-i) continue;
            cout << i << ' ' << n-1-i << endl;
            vis[i] = 1;
            vis[n-i-1] = 1;
        }
        rep(i,0,n) vis[i] = 0;
        return;
    }
    if (n == 4){
        cout << -1 << endl;
        return;
    }
    cout << n-1 << ' ' << n-2 << endl;
    cout << n-3 << ' ' << 1 << endl;
    cout << 2 << ' '<< 0 << endl;
    vis[n-1] = 1;
    vis[n-2] = 1;
    vis[n-3] = 1;
    vis[1] = 1;
    rep(i,3,n){
        if (i >= n-1-i) break;
        if (vis[i]) continue;
        cout << i << ' ' << n-i-1 << endl;
        vis[i] = 1;
        vis[n-i-1] = 1;
    }
    rep(i,0,n) vis[i] = 0;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}