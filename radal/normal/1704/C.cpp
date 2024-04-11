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
int n,m;
vector<pll> ve;
int a[N];
int len(pll x){
    if (x.Y > x.X) return x.Y-x.X-1;
    else return n-x.X+x.Y-1;
}
bool cmp(pll x,pll y){
    int len1 = len(x),len2 = len(y);;
    return (len1 > len2);
}
void solve(){
    ve.clear();
    cin >> n >> m;
    rep(i,0,m) cin >> a[i];
    sort(a,a+m);
    rep(i,1,m) ve.pb({a[i-1],a[i]});
    ve.pb({a[m-1],a[0]});
    sort(all(ve),cmp);
    int ans = 0,ti = 0;
    for (pll p : ve){
        if (len(p) <= ti*2) break;
        if (len(p) == ti*2+1){
            ans++;
            break;
        }
        ans += len(p)-ti*2-1;
        ti += 2;
    }
    cout << n-ans << endl;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        solve();
    }
}