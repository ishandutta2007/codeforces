#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse4,avx2")
//#pragma GCC optimize("unroll-loops,O2")
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
constexpr int N = 4e5+20,mod = 1e9+7,inf = 1e9+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k,int p){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%p;
        a = 1ll*a*a%p;
        k >>= 1;
    } 
    return z; 
}
int a[N],cnt[N];
inline void solve(){
    int n;
    cin >> n;
    rep(i,1,n+1) cnt[i] = 0;
    rep(i,0,n){
        cin >> a[i];
        cnt[a[i]]++;
    }
    rep(i,1,n+1){
        if (cnt[i] > (n+1)/2){
            cout << -1 << endl;
            return;
        }
        cnt[i] = 0;
    }
    int po = 0;
    int co = 0,mx = 0;
    vector<pll> ve;
    while (po < n){
        co++;
        int x = a[po];
        while (po < n-1 && a[po] != a[po+1]) po++;
        cnt[x]++;
        cnt[a[po]]++;
        mx = max({mx,cnt[x],cnt[a[po]]});
        po++;
    }
    if (mx <= co+1){
        cout << co-1 << endl;
        return;
    }
    cout << co-1+mx-(co+1) << endl;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}