#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 2000 + 5;

int n, a[N], b[N], pos[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i], pos[b[i]] = i;

    int cost = 0;
    vector<pair<int, int>> ans;

    for (int i = 1; i <= n; i++) {
        if (a[i] == b[i]) continue;

        int cur = 0;
        for (int j = i + 1; j <= n; j++) {
            if (a[j] == b[i])
                cur = j;
        }

        for (int j = cur - 1; j >= i; j--) {
            if (pos[a[j]] >= cur) {
                swap(a[j], a[cur]);
                ans.emplace_back(j, cur);
                cost += abs(j - cur);
                cur = j;
            }
        }
    }

    cout << cost << "\n";
    cout << ans.size() << "\n";
    for (auto &[i, j] : ans) cout << i << " " << j << "\n";
    return 0;
}