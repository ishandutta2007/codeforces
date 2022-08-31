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
    vector<vector<int>> a(200, vector<int> (n));
    vector<int> s(n);
    range(i, n) cin >> s[i];
    range(i, n) {
        a[s[i]-1][i]++;
        s[i]--;
    }
    for(int i = 1; i < n; ++i) {
        range(j, 200) a[j][i] += a[j][i-1];
    }
    int ans = 1;
    vector<int> cur(200, 0);
    for(int i = n - 1; i >= 1; --i) {
        cur[s[i]]++;
        int j = lower_bound(all(a[s[i]]), cur[s[i]]) - a[s[i]].begin();
        if (j >= i) continue;
        vector<int> cur2(200, 0);
        range(e, 200) cur2[e] = a[e][i-1] - a[e][j];
        range(e, 200) {
            ans = max(ans, cur[s[i]] * 2 + cur2[e]);
        }
    }
    cout << ans << "\n";
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