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
constexpr int N = 1e5+20,mod = 998244353 ,inf = 1e9+10;

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
    int n,a,b;
    cin >> n >> a >> b;
    if (a+b > n-2 || max(a,b) > (n-1)/2 || abs(a-b) > 1){
        cout << -1 << endl;
        return;
    }
    vector<int> ve;
    if (a > b){
        ve.pb(1);
        int i = 2;
        while (a > 1){
            a--;
            ve.pb(n-i+2);
            ve.pb(i);
            i++;
        }
        repr(j,n-i+2,i) ve.pb(j);
    }
    else if (b > a){
        ve.pb(n);
        int i = 1;
        while (b > 1){
            b--;
            ve.pb(i);
            ve.pb(n-i);
            i++;
        }
        rep(j,i,n-i+1) ve.pb(j);
    }
    else{
        ve.pb(n);
        int i = 1;
        while (b){
            b--;
            ve.pb(i);
            ve.pb(n-i);
            i++;
        }
        repr(j,n-i,i) ve.pb(j);
    }
    for (auto u : ve) cout << u << ' ';
    cout << endl;
}
int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
}