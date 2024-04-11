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
constexpr int N = 2e5+20,mod = 998244353 ,inf = 1e9+10;

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
vector<int> taj;
multiset<ll> pq;
int a[N];
ll sum[100][N/2];
bool pr[N];
inline void solve(){
    taj.clear();
    int n,q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        if (pr[i]) continue;
        if (n%i == 0){
            taj.pb(n/i);
        }
    }
    pq.clear();
    sort(all(taj));
    int sz = taj.size();
    rep(i,0,sz){
        int u = taj[i];
        rep(j,0,u) sum[i][j] = 0;
    }
    rep(i,1,n+1){
        cin >> a[i];
    }
    rep(i,0,sz){
        int u = taj[i];
        int pr = 0;
        rep(j,1,n+1){
            pr++;
            if (pr == u) pr = 0;
            sum[i][pr] += a[j];
        }
    }
    rep(i,0,sz){ 
        int u = taj[i];
        rep(j,0,u){
            sum[i][j] *= u;
            pq.insert(sum[i][j]);
        }
    }
    cout << *(pq.rbegin()) << endl;
    while (q--){
        int p,x;
        cin >> p >> x;
        int dlt = x-a[p];
        a[p] = x;
        rep(j,0,sz){
            int ba = p%taj[j];
            pq.erase(pq.find(sum[j][ba]));
            sum[j][ba] += 1ll*dlt*taj[j];
            pq.insert(sum[j][ba]);
        }
        cout << *(pq.rbegin()) << endl;
    }
}
int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    pr[1] = 1;
    rep(i,2,N){
        if (pr[i]) continue;
        for (int j = 2; j*i < N; j++)
            pr[j*i] = 1;
    }
    int T = 1;
    cin >> T;
    while (T--){
        solve();
    }
}