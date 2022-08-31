#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 2e5 + 1;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n; cin >> n;
    bool ans = true;
    pair<int, int> prev = {0, 0};
    range(i, n) {
        pair<int, int> cur; cin >> cur.first >> cur.second;
        if (cur.first - prev.first < 0 || cur.second - prev.second < 0) ans = false;
        if (cur.first - prev.first < cur.second - prev.second) ans = false;
        prev = cur;
    }
    cout << (ans ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}