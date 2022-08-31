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
const int N = 1e5 + 5;

int n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    multiset<int> s;
    for (int i = 0; i < n; i++) s.insert(a[i]);

    int ans = 1, cur = 0;
    for (int i = 0; i < n; i++) {
        s.erase(s.find(a[i]));
        cur = max(cur, a[i]);
        if (!s.empty() and *s.begin() >= cur) {
            ans++;
        }
    }

    cout << ans << "\n";
    return 0;
}