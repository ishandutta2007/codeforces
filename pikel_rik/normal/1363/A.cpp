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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> cnt(2);
        for (int i : a) cnt[i % 2] += 1;

        while (cnt[0] and cnt[1]) {
            if (x % 2 != 0 and cnt[1] >= x)
                break;
            x -= 1;
            cnt[0] -= 1;
        }

        if (x % 2 != 0 and cnt[1] >= x) {
            cout << "Yes\n";
        } else cout << "No\n";
    }
    return 0;
}