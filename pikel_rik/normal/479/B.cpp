#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 100 + 5;

int n, k, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<pair<int, int>> ans;
    while (k--) {
        int mx = max_element(a, a + n) - a, mn = min_element(a, a + n) - a;
        if (a[mx] == a[mn] or a[mx] == a[mn] + 1)
            break;
        a[mx]--;
        a[mn]++;
        ans.emplace_back(mx + 1, mn + 1);
    }

    cout << *max_element(a, a + n) - *min_element(a, a + n) << ' ' << ans.size() << '\n';
    for (auto& [i, j] : ans) cout << i << ' ' << j << '\n';
    return 0;
}