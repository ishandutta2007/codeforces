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
using ul = unsigned long long;
using ld = long double;

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int t, n, m;
    cin >> t;
    rep(z, t) {
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        vector<pair<int, int>> b(m);
        rep(i, m)
            b[i].second = i;
        rep(i, n)
            rep(j, m) {
                cin >> a[i][j];
                b[j].first = max(b[j].first, a[i][j]);
            }
        sort(rall(b));
        int pw = 1 << n;
        vector<int> dp(pw), nd(pw), bd(pw), cs(pw);
        rep(i, min(n, m)) {
            bd = dp;
            rep(j, n) {
                nd = dp;
                rep(k, n)
                    rep(l, pw) {
                        if (l & (1 << k))
                            continue;
                        int pos = j + k;
                        if (pos >= n)
                            pos -= n;
                        nd[l | (1 << k)] = max(nd[l | (1 << k)], nd[l] + a[pos][b[i].second]);
                    }
                rep(k, pw)
                    bd[k] = max(bd[k], nd[k]);
            }
            dp = bd;
        }
        cout << dp[pw - 1] << '\n';
    }
}