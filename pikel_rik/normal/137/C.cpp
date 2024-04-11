#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 9;
const int inf = 2e9 + 5;
const int N = 1e5 + 5;

int n;
pair<int, int> a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

    sort(a, a + n);
    pair<int, int> cur(0, 0);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].second > cur.second)
            cur = a[i];
        else if (a[i].second < cur.second and a[i].first > cur.first)
            ans += 1;
    }

    cout << ans << "\n";
    return 0;
}