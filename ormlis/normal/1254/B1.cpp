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
int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    int s = 0;
    range(i, n) {cin >> a[i]; s += a[i];}

    ll ans = INF;
    vector<int> divs;
    for(int i = 1; i * i <= s; ++i) {
        if (s % i == 0 && i != 1) divs.push_back(i);
        if (s % i == 0 && i != s / i) divs.push_back(s/i);
    }
    for(auto &x: divs) {
        int j = 0;
        ll res = 0;
        range(i, s / x) {
            vector<int> cur;
            for(; cur.size() < x; ++j) {
                if (a[j]) cur.push_back(j);
            }
            int mid = cur[x/2];
            for(auto &e: cur) res += abs(e - mid);
        }
        ans = min(ans, res);
    }
    if (ans == INF) cout << -1;
    else cout << ans;
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