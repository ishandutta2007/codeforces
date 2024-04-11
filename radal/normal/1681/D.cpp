#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse4")
//#pragma GCC optimize("unroll-loops")
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
constexpr int N = 3e5+20,mod = 1e9+7 ,inf = 1e9+10;
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
map<ll,int> mp;
int n,ans;
ll l;
void f(ll x,int d){
    if (mp.find(x) != mp.end()) return;
    mp[x] = 100;
  //  if (d > ans) return;
    ll y = x;
    int t = 0;
    vector<int> ve;
    while (y){
        if (y%10 > 1){
            ve.pb(y%10);
        }
        y /= 10;
        t++;
    }
    if (t == n){
        mp[x] = 0;
        ans = min(ans,d);
        return;
    }
    if(t > n) return;
    int sz = ve.size();
    if (!sz) return;
    sort(all(ve));
    rep(i,0,sz){
        if (i && ve[i] == ve[i-1]) continue;
        if (x >= (l+ve[i]-1)/ve[i]){
            ans = min(ans,d+1);
            mp[x] = 1;
            return;
        }
        f(x*ve[i],d+1);
        mp[x] = min(mp[x],mp[x*ve[i]]+1);
    }
    ans = min(ans,mp[x]+d);
}
void solve(){
    ll x;
    ans = 100;
    cin >> n >> x;
    l = 1;
    rep(i,1,n) l *= 10;
    f(x,0);
    if (ans != 100) cout << ans;
    else cout << -1;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
   // int T;
  //  cin >> T;
    //while (T--)
        solve();
}