#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) for (int i = 0; i < a; i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define eps 0.00000001
#define sqr(x) (x) * (x)
#define pb push_back

long long n, k, d, dp[2][111];

long long get(int st, int x) {
    // cout << st << ' ' << x << endl;
    if (dp[st][x] != -1) return dp[st][x];
    dp[st][x] = 0;
    if (st) {
        FOR (i, 1, k) if (i <= x) {
            if (i >= d) dp[st][x] += get(1, x - i) + get(0, x - i);
            else dp[st][x] += get(1, x - i);
        }
    } else  {
        FOR (i, 1, k) if (i <= x) {
            if(i < d) dp[st][x] += get(0, x - i);
        }
    }
    // BUG(dp[st][x]);
    // cout << st << ' ' << x << ' ' << dp[st][x] << endl;
    dp[st][x] %= mod;
    return dp[st][x];
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> k >> d;
    reset(dp, -1);
    dp[0][0] = 1;
    dp[1][0] = 0;
    cout << get(1, n);
}