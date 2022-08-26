#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 4e18;
const int INFi = 2e9;
const int maxN = 2e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    vector<int> b(n);
    range(i, n) cin >> a[i];
    range(i, n) cin >> b[i];
    int ans = 0;
    int cur = 0;
    range(i, n) cur += a[i];
    ans = max(ans, cur);
    range(_, k) {
        int min_el = 0;
        range(i, n) if (a[i] < a[min_el]) min_el = i;
        int max_el = 0;
        range(i, n) if (b[i] > b[max_el]) max_el = i;
        swap(a[min_el], b[max_el]);
        cur = 0;
        range(i, n) cur += a[i];
        ans = max(ans, cur);
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