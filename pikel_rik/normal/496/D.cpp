#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n, a[N], pref[N];

int f(int x, int i, int t) {
    if (pref[x] - pref[i - 1] >= t)
        return 1;
    if (x - i + 1 - (pref[x] - pref[i - 1]) >= t)
        return 2;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i], --a[i];

    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i - 1];
    }

    vector<pair<int, int>> ans;
    for (int t = 1; t <= n; t++) {
        bool bad = false;
        int c1 = 0, c2 = 0;

        int lo, hi, last;
        for (int i = 1; i <= n; i = lo + 1) {
            lo = i, hi = n;
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (f(mid, i, t))
                    hi = mid;
                else lo = mid + 1;
            }

            if (!f(lo, i, t)) {
                bad = true;
                break;
            } else {
                if (f(lo, i, t) == 1)
                    c1++, last = 1;
                else c2++, last = 2;
            }
        }
        if (!bad and c1 != c2) {
            if (c1 > c2 and last == 1)
                ans.emplace_back(c1, t);
            else if (c2 > c1 and last == 2)
                ans.emplace_back(c2, t);
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';

    for (auto& [s, t] : ans) {
        cout << s << ' ' << t << '\n';
    }
    return 0;
}