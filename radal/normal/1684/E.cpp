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
int a[N];
map<int,int> cnt;
bitset<inf> vis;
void solve(){
    int n,k;
    cin >> n >> k;
    cnt.clear();
    rep(i,0,n){
        cin >> a[i];
        cnt[a[i]]++;
        vis[a[i]] = 0;
    }
    if (k >= n){
        cout << 0 << endl;
        return;
    }
    vector<pll> ve;
    int t = 0,lst= -1;
    rep(i,0,n){
        int d = cnt[a[i]];
        if(!vis[a[i]]){
            ve.pb({d,a[i]});
            vis[a[i]] = 1;
        }
        if (!cnt[i]){
            t++;
            if (t == k+1) lst = i;
        }
    }
    if (t <= k){
        cout << 0 << endl;
        return;
    }
    sort(all(ve));
    int ans = ve.size()-lst,cur = k;
    for (pll u : ve){
        if (u.Y < lst) continue;
        if (u.X <= cur){
            cur -= u.X;
            ans += u.X-1;
        }
        else{
            ans += cur;
            cur = 0;
            break;
        }
    }
    if (cur){
        cout << 0 << endl;
        return;
    }
    cout << ans << endl;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
}