#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1e5 + 1;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    sort(rall(a));
    int l = 0, r = n;
    auto check = [&a, &n,  &m] (int d) {
        int ans = m;
        range(i, n) {
            ans -= max(0, a[i] - i / d);
        }
        return ans <= 0;
    };

    while(r - l > 1) {
        int mid = (r + l) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    if (check(r)) cout << r;
    else cout << -1;
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