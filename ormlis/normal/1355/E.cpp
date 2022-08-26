#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 4e18;
const int INFi = 2e9;
const int maxN = 3e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n, a, r, m; cin >> n >> a >> r >> m;
    vector<int> h(n);
    range(i, n) cin >> h[i];
    sort(all(h));

    auto check = [&] (int x) {
        ll up = 0, down = 0;
        range(i, n) {
            if (h[i] < x) down += x - h[i];
            if (h[i] > x) up += h[i] - x;
        }
        ll res = 0;
        if (m < a + r) {
            ll used = min(down, up);
            res += 1ll * m * used;
            down -= used;
            up -= used;
        }
        res += 1ll * r * up;
        res += 1ll * a * down;
        return res;
    };

    int left = 0, right = 1e9;
    while(right - left > 1) {
        int mid = (right + left) / 2;
        if (check(mid) < check(mid + 1)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << min(check(left), check(right));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}