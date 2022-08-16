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
const int N = 1e3 + 5;

int n, a[N], cnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> temp(a, a + n);
    sort(all(temp));

    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(all(temp), a[i]) - temp.begin() + 1;
        tie(a[i], cnt[a[i]]) = make_tuple(a[i] + cnt[a[i]], cnt[a[i]] + 1);
    }

    vector<pair<int, int>> inv;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[i])
                inv.emplace_back(i, j);
        }
    }

    sort(all(inv), [&] (pair<int, int>& x, pair<int, int>& y) {
       if (x.second != y.second)
            return x.second > y.second;
       return a[x.first] < a[y.first];
    });

    cout << inv.size() << "\n";
    for (auto &[i, j]: inv) cout << i + 1 << " " << j + 1 << "\n";
    return 0;
}