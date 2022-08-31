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
const int MAXN = 7e1+10, MAXQ = 3e5+10, MAXL = 18, ALP = 26, MOD = 998244353, MAXK = 17,  MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const int INF = 1e9+10;

int n, m, k;
vector<int> g[MAXN];
int dp[MAXN][MAXN];

vector<int> solve_row(vector<int> val) {
    for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) dp[i][j] = -INF;
    dp[0][0] = 0;

    for (auto it : val) {
        for (int i = m/2; i > 0; i--) {
            for (int j = 0; j < k; j++) {
                int pr = ((j-it)%k+k)%k;
                if (dp[i-1][pr] <= -INF) continue;
                dp[i][j] = max(dp[i][j], dp[i-1][pr]+it);
            } 
        }
    }
    vector<int> ret(k, -INF);
    for (int j = 0; j < k; j++) {
        for (int i = 0; i <= m/2; i++) ret[j] = max(ret[j], dp[i][j]);
    }
    return ret;
}
void solve(){
    cin >> n >> m >> k;
    vector<int> pdp(k, -INF), cdp(k, -INF);
    pdp[0] = 0;

    for (int i = 0; i < n; i++) {
        g[i].resize(m);
        for (auto& c : g[i]) cin >> c;

        vector<int> curdp = solve_row(g[i]);
        for (int j = 0; j < k; j++) {
            for (int l = 0; l < k; l++) if (curdp[l] > -INF) {
                cdp[j] = max(cdp[j], curdp[l]+pdp[((j-l)%k+k)%k]);
            }
        }
        swap(pdp, cdp), fill(cdp.begin(), cdp.end(), -INF), cdp[0] = 0;
    }
    assert(pdp[0]%k == 0);
    cout << pdp[0] << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}