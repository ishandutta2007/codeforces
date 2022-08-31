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
const int N = 2e3 + 5;

int n, p, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> p;
    for (int i = 0; i < n; i++) cin >> a[i];

    int mx = *max_element(a, a + n), mn = *min_element(a, a + n);
    vector<int> ans;

    sort(a, a + n);

    for (int j = mn; j <= mx - 1; j++) {
        int val = 1;
        int x = j;

        for (int i = 0; i < n; i++) {
            int c = upper_bound(a, a + n, x) - a;
            val = val * (c - i) % p;
            if (val == 0)
                break;
            x++;
        }

        if (val != 0)
            ans.push_back(j);
    }

    cout << ans.size() << "\n";
    for (int i : ans) cout << i << " "; cout << "\n";
    return 0;
}