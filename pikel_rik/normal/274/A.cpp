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

int n, k, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    if (k == 1) {
        cout << n << "\n";
        return 0;
    }

    set<int> ans, bad;
    sort(a, a + n);

    for (int i = 0; i < n; i++) {
        if (ans.find(a[i]) != ans.end() or bad.find(a[i]) != bad.end())
            continue;

        ll last = a[i];
        ans.insert(a[i]);

//        cout << a[i] << " ";
        for (ll j = a[i] * (ll)k; j <= 1e9; j *= k) {
//            cout << j << " ";
            if (binary_search(a, a + n, j)) {
                if (j == last * k)
                    bad.insert(j);
                else {
                    last = j;
                    ans.insert(j);
                }
            }
        }
//        cout << "\n";
    }

    cout << ans.size() << "\n";
//    for (int i : ans) cout << i << " ";
    return 0;
}