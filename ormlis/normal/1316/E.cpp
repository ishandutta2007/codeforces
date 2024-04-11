#include <iostream>
#include <random>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <queue>
#include <cmath>
#include <chrono>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 1001;
ll md = 1000000007;

//double getTime() { return clock() / (double) CLOCKS_PER_SEC;};

struct Player {
    ll a=0;
    vector<ll> s={};
};
bool operator < (Player &a, Player &b) {
    return a.a > b.a;
}

void solve() {
    int n, p, k; cin >> n >> p >> k;
    vector<Player> ps(n);
    range(i, n) cin >> ps[i].a;
    range(i, n) {
        ps[i].s.resize(p);
        range(j, p) cin >> ps[i].s[j];
    }
    sort(all(ps));
    int w = 1 << p;
    vector<ll> dp(w, -INF);
    dp[0] = 0;
    range(i, n) {
        vector<ll> new_dp = dp;
        range(j, w) {
            int c = p;
            range(t, p) {
                int l = 1 << t;
                if (!(l & j)) {
                    c--;
                    new_dp[(j|l)] = max(new_dp[(j|l)], dp[j] + ps[i].s[t]);
                }
            }
            if (i - c < k) new_dp[j] = max(new_dp[j], dp[j] + ps[i].a);
        }
        dp = new_dp;
    }
    cout << dp.back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}