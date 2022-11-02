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
constexpr int N = 2e5+20,mod = 1e9+7,inf = 1e9+10;
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
vector<vector<int> > a;
pair<ll,int> s[N];
void solve(){
    a.clear();
    int n,m;
    cin >> n >> m;
    a.resize(n);
    rep(i,0,n){
        s[i].X = 0;
        a[i].resize(m);
        rep(j,0,m){
            cin >> a[i][j];
            s[i].X += 1ll*a[i][j]*(j+1);
        }
        s[i].Y = i;
    }
    sort(s,s+n);
    cout << s[n-1].Y+1 << ' ' << s[n-1].X-s[0].X << endl;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        solve();
    }
}