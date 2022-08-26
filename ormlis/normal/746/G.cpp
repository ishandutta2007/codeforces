#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1e6 + 1;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n, t, k;
    cin >> n >> t >> k;
    vector<int> a(t + 1, 1);
    range(i, t) cin >> a[i + 1];
    if (a.back() > k) {
        cout << -1;
        return;;
    }
    vector<vector<int>> levels(t + 1);
    int curv = 1;
    range(i, t + 1) {
        range(j, a[i]) levels[i].push_back(curv + j);
        curv += a[i];
    }
    vector<pair<int, int>> answer;
    int prev = 0;
    for (int i = t; ~i; --i) {
        if (a[i] > prev) {
            k -= a[i] - prev;
        }
        prev = a[i];
    }
    if (k < 0) {
        cout << -1;
        return;
    }

    for(int i = t - 1; ~i; --i) {
        int listov = min(min(a[i], a[i+1]) - 1, k);
        int nolist = min(a[i], a[i+1]) - listov;
        for(int j = 0; j < a[i+1]; ++j) {
            if (j >= nolist) {
                answer.emplace_back(levels[i+1][j], levels[i][nolist-1]);
            } else {
                answer.emplace_back(levels[i+1][j], levels[i][j]);
            }
        }
        k -= listov;
    }

    if (k) {
        cout << -1;
        return;
    }
    cout << n << "\n";
    range(i, n - 1) {
        cout << answer[i].first << " " << answer[i].second << "\n";
    }
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