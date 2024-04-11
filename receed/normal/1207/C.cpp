#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;

const int N = 200002;
ll dp[N][2];

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	ll t, n, a, b, inf = 1e17;
    string s;
    cin >> t;
    dp[0][0] = 0;
    dp[0][1] = inf;
    rep(z, t) {
        cin >> n >> a >> b >> s;
        for (int i = 1; i < n; i++) {
            if (s[i] == '1')
                dp[i][0] = inf;
            else
                dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + b + a);
            dp[i][1] = min(dp[i - 1][0] + a, dp[i - 1][1]) + b;
        }
        cout << dp[n - 1][0] + n * a + (n + 1) * b << '\n';
    }

}