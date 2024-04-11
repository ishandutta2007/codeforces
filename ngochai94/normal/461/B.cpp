#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) for (int i = 0; i < a; i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define MAXN 30005

long long n, par[100005], color[100005], dp[2][100005];
vector<long long> adj[100005];

long long inv(long long x) {
    long long res = 1;
    FORD (i, 30, 0) {
        res *= res;
        res %= mod;
        if ((1 << i) & (mod - 2)) {
            res *= x;
            res %= mod;
        }
    }
    return res;
}

int main(){
    // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    // cout << inv(2);return 0;
    cin >> n;
    FOR (i, 1, n - 1) {
        cin >> par[i];
        adj[par[i]].pb(i);
    }
    REP (i, n) cin >> color[i];
    FORD (i, n - 1, 0) {
        dp[0][i] = 1;
        if (color[i]) {
            for (int nex: adj[i]) {
                dp[0][i] *= dp[0][nex];
                dp[0][i] %= mod;
            }
            dp[1][i] = dp[0][i];
        } else {
            for (int j: adj[i]) {
                dp[1][i] += dp[1][j] * inv(dp[0][j]);
                dp[1][i] %= mod;
            }
            for (int j: adj[i]) {
                dp[1][i] *= dp[0][j];
                dp[1][i] %= mod;
                dp[0][i] *= dp[0][j];
                dp[0][i] %= mod;
            }
            dp[0][i] += dp[1][i];
            dp[0][i] %= mod;
        }
        // cout << i << ' ' << dp[0][i] << ' ' << dp[1][i] << endl;
    }
    cout << dp[1][0];
}