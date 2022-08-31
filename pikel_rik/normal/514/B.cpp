#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e3 + 5;

int n, x, y;
pair<int, int> a[N];

ll area(int x1, int y1, int x2, int y2, int x3, int y3) {
    return x1 * (ll)(y2 - y3) + x2 * (ll)(y3 - y1) + x3 * (ll)(y1 - y2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> x >> y;
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

    set<pair<int, int>> used;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (used.find(a[i]) != used.end()) continue;
        used.insert(a[i]);
        ans++;

        for (int j = i + 1; j < n; j++) {
            if (used.find(a[j]) != used.end()) continue;
            if (area(a[i].first, a[i].second, a[j].first, a[j].second, x, y) == 0)
                used.insert(a[j]);
        }
    }

    cout << ans << "\n";
    return 0;
}