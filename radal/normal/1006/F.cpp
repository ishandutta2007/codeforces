#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
typedef pair<int,ll> pll;
constexpr ll N = 1e1+20,mod = 1e9+7,inf = 1e9+10,maxm = 1e6;
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
map<ll,int> st[N][N];
ll a[N][N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n,m;
    ll k;
    cin >> n >> m >> k;
    rep(i,0,n)
        rep(j,0,m)
        cin >> a[i][j];
    int g = (1 << (n-1)),n2 = n-1;
    rep(i,0,g){
        int x = 0,y = 0;
        ll s = a[0][0];
        rep(j,0,n2){
            if (i&(1 << j)){
                x++;
                s ^= a[x][y];
            }
            else{
                y++;
                if (y >= m) break;
                s ^= a[x][y];
            }
        }
        if (x < n && y < m) st[x][y][s]++;
    }
    g = (1 << (m-1));
    ll ans = 0;
    n2 = m-1;
    rep(i,0,g){
        int x = n-1,y = m-1;
        ll s = a[n-1][m-1];
        rep(j,0,n2){
            if (i&(1 << j)){
                x--;
                if (x < 0) break;
                s ^= a[x][y];
            }
            else{
                y--;
                s ^= a[x][y];
            }
        }
        if (x >= 0){
            ans += st[x][y][s^k^a[x][y]];
        }
    }
    cout << ans;
}