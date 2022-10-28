#include "bits/stdc++.h"
using namespace std;

template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 18, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

const int I2 = (MOD+1)/2;
int n, m, dp[1<<MAXN];
bool c[MAXN][MAXN], take[1<<MAXN];

ll add_self(ll& a, ll b){
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}
void solve(){
    cin >> n >> m;
    memset(c, 0, sizeof(c));
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b, --a, --b;
        c[a][b] = 1, c[b][a] = 1;
    }
    for (int i = 0; i < (1<<n); i++){
        bool bad=0;
        for (int j = 0; j < n; j++) if ((i>>j)&1) for (int k = 0; k < n; k++) if ((i>>k)&1) if (c[j][k]){
            bad=1; break;
        }
        take[i] = bad?0:1;
    }
    memset(dp, 0, sizeof(dp));
    dp[0]=1;
    for (int i = 1; i < (1<<n); i++){
        ll c=0;
        for (int s=i; s; s=(s-1)&i) if (take[s]) {
            int sgn = (__builtin_popcount(s)&1?1:-1);
            add_self(c, (MOD+sgn*dp[i^s])%MOD);
        }
        dp[i] = c;

    }
    cout << ll(m)*ll(I2)%MOD*dp[(1<<n)-1]%MOD << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}