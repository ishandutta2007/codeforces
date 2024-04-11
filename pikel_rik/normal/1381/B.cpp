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

int n, a[2*N], pos[2*N];
bitset<2*N> b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        n *= 2;
        for (int i = 0; i < n; i++) cin >> a[i], pos[a[i]] = i;

        vector<int> lens;
        int cur = n;

        for (int i = n; i >= 1; i--) {
            if (cur > pos[i]) {
                lens.push_back(cur - pos[i]);
                cur = pos[i];
            }
        }

        for (int i = 1; i <= n; i++) b[i] = false;
        b[0] = true;

        for (int i : lens) {
            b |= (b << i);
        }

        cout << (b[n / 2] ? "YES\n" : "NO\n");
    }
    return 0;
}