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
constexpr int N = 1e5+20,mod = 1e9+7,inf = 1e9+10;
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
vector<int> ve[N][2];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    rep(i,0,n){
        rep(j,0,m){
            int x;
            cin >> x;
            ve[x][0].pb(i);
            ve[x][1].pb(j);
        }
    }
    ll ans = 0;
    rep(i,1,N) if (ve[i][0].size() > 1){
        sort(all(ve[i][0]));
        sort(all(ve[i][1]));
        int sz = ve[i][0].size();
        rep(j,0,sz){
            ans += 1ll*(2*j-sz+1)*ve[i][0][j];
            ans += 1ll*(2*j-sz+1)*ve[i][1][j];
        }
    }
    cout << ans;
    return 0;
}