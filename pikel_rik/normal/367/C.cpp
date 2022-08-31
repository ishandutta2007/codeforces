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

bool f(int n, int c) {
    if (c % 2 != 0)
        return n - 1 >= c * (ll)(c - 1) / 2;
    else return n - 1 >= (c - 1) * (ll)c / 2 + (c - 2) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    int m; cin >> m;
    vector<int> w(m);

    int lo = 1, hi = min(m, n);
    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if (f(n, mid))
            lo = mid;
        else hi = mid - 1;
    }

    for (int i = 0; i < m; i++) {
        int q;
        cin >> q >> w[i];
    }

    sort(all(w), greater<>());
    cout << accumulate(w.begin(), w.begin() + lo, 0ll) << "\n";
    return 0;
}