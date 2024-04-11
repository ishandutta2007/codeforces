#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

int n, x, y;

pair<int, int> solve(int sum) {
    int lo = 1, hi = n;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (sum - mid <= n)
            hi = mid;
        else lo = mid + 1;
    }
    return make_pair(lo, sum - lo);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> x >> y;

        auto [l, r] = solve(x + y + 1);
        int ans = r - l + 1;

        if (l <= x and x <= r and l <= y and y <= r)
            ans--;
        else {
            if (l <= x and x <= r)
                ans--;
            if (l <= y and y <= r)
                ans--;
        }
        ans += n - r;

        cout << n - ans << ' ';

        tie(l, r) = solve(x + y);
        ans = r - l + 1;

        if (l <= x and x <= r and l <= y and y <= r)
            ans--;
        else {
            if (l <= x and x <= r)
                ans--;
            if (l <= y and y <= r)
                ans--;
        }
        ans += l - 1;
        cout << ans + 1 << '\n';
    }
    return 0;
}