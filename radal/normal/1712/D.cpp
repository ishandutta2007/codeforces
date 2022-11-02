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
constexpr int N = 1e5+20,mod = 1e9+7 ,inf = 1e9+10;
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

int a[N];
inline void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> ve;
    rep(i,0,n){
        cin >> a[i];
        ve.pb(a[i]);
    }
    ve.pb(inf-10);
    sort(all(ve));
    if (k > (n+1)/2){
        cout << min(inf-10,2*ve[k]) << endl;
        return;
    }
    int ans = ve[k];
    if (k > 1){
        ans = max(ans,min(inf-10,2*ve[k-1]));
    }
    rep(i,1,n){
        int mx = max(a[i],a[i-1]),mi = min(a[i],a[i-1]);
        if (k == 1){
            if (mi == ve[0]){
                ans = max(ans,min(mx,2*ve[1]));
                continue;
            }
            ans = max(ans,min(mx,2*ve[0]));
            ans = max(ans,min(mi,2*ve[1]));
            continue;
        }
        if (mx <= ve[k-1] && mi <= ve[k-2]){
            ans = min(inf-10,2*ve[k]);
            break;
        }
        if (mi <= ve[k-1])
            ans = max(ans,min(mx,2*ve[k]));
        ans = max(ans,min(mi,2*ve[k]));
    }

    cout << ans << endl;

}
int main(){
    ios:: sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}