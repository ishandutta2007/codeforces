#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e5 + 5;

int n, a[N], ans[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    reverse(a, a + n);
    set<pair<int, int>, greater<>> s;

    for (int i = 0; i < n; i++) {
        auto it = s.upper_bound({a[i], 0});

        if (it == s.end())
            ans[i] = -1;
        else ans[i] = (i - (*it).second) + ans[(*it).second];

        it = s.lower_bound({a[i], inf});

        if (it == s.end() or (*it).first != a[i])
            s.insert({a[i], i});
    }

    for (int i = n - 1; i >= 0; i--) cout << ans[i] << " ";
    return 0;
}