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
const int MAXN = 1e2+10, MAXM = 40, MAXL = 20, ALP = 20, MOD = 998244353, MAXK = 17, INF = 1e9+10, MAXA = 1e2+10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int c[MAXA], dp[2][MAXA*MAXN][MAXN];

void solve(){
    int n; cin >> n;
    memset(c, 0, sizeof(c)); memset(dp, 0, sizeof(dp));

    vector<int> a(n); for (auto& it : a) cin >> it, c[it]++;
    int cnt=0;
    for (int i = 0; i < MAXA; i++) cnt += bool(c[i]);
    if (cnt <= 2){ cout << n; return; }

    dp[0][0][0] = dp[1][0][0] = 1;
    for (int _i = 1; _i < MAXA; _i++){
        assert(dp[_i&1][0][0] == 1);
        for (int i = c[_i]*_i; i >= _i; i-=_i){
            for (int j = n*MAXA-1; j >= i; j--) {
                for (int k = i/_i; k <= n; k++){
                    dp[_i&1][j][k] = min(2, dp[_i&1][j][k]+dp[_i&1^1][j-i][k-i/_i]);
                }
            }
            
        }
        memcpy(dp[_i&1^1], dp[_i&1], sizeof(dp[_i&1^1]));
    }

    int ans=0;
    for (int i = 0; i < MAXA; i++){
        for (int j = 1; j <= c[i]; j++) if (dp[MAXA&1^1][i*j][j] == 1) ans = max(ans, j);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while (t--) solve();
}