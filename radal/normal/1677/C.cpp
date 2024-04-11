#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse4,avx2")
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
        k >>= 1;
    } 
    return z; 
}
int b[N],c[N],a[N];
int tmp[N];
bool vis[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        rep(i,1,n+1) cin >> b[i];
        rep(i,1,n+1){
            int x;
            cin >> x;
            c[x] = i;
        }
        rep(i,1,n+1){
            a[i] = c[b[i]];
            vis[i] = 0;
        }
        vector<int> ve;
        deque<int> dq;
        rep(i,1,n+1){
            dq.pb(i);
            if (vis[i]) continue;
            int t = 0;
            int cur = i;
            while (1){
                vis[cur] = 1;
                t++;
                if (vis[a[cur]] == 1) break;
                cur = a[cur];
            }
            if (t&1) t--;
            if (t) ve.pb(t);
        }
        ll ans = 0;
        for (int u : ve){
            bool f = 0;
            rep(i,0,u){
                int x;
                if (f){
                    x = dq.front(); 
                    dq.pop_front();
                }
                else{
                    x = dq.back();
                    dq.pop_back();
                }
                tmp[i] = x;
                f = !f;
                if (i) ans += abs(x-tmp[i-1]);
                if (i == u-1) ans += abs(x-tmp[0]);
            }
        }
        cout << ans << endl;
    }

}