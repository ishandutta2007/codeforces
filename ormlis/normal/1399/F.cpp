#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <map>
#include <unordered_set>
#include <tuple>
#include <queue>
#include <set>
#include <cstring>
#include <functional>
#include <random>
#include <chrono>
#include <cassert>
#include <iomanip>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 2e5+5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

int ind[maxN];

void solve() {
    int n; cin >> n;
    vector<int> l(n), r(n);
    vector<int> x;
    range(i, n) {
        cin >> l[i] >> r[i];
        x.push_back(l[i]);
        x.push_back(r[i]);
    }
    sort(all(x));
    x.resize(unique(all(x)) - x.begin());
    int cnt = x.size();
    range(i, cnt) ind[x[i]] = i;
    vector<vector<int>> sl(cnt+5);
    range(i, n) l[i] = ind[l[i]];
    range(i, n) r[i] = ind[r[i]];
    range(i, n) sl[l[i]].push_back(r[i]);
    range(i, cnt) sort(all(sl[i]));
    cnt++;
    vector<vector<int>> dp(cnt+3, vector<int> (cnt+3, 0));
    for(int len = 1; len <= cnt; ++len) {
        for(int j = 0; j <= cnt - len + 1; ++j) {
            dp[j][len] = dp[j+1][len-1];
            for(auto &rr: sl[j]) {
                if (rr > j + len - 1) break;
                if (rr == j + len - 1) {
                    dp[j][len]++;
                    continue;
                }
                dp[j][len] = max(dp[j][len], dp[j][rr-j+1] + dp[rr+1][len-(rr-j+1)]);
            }
        }
    }
    cout << dp[0][cnt] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}