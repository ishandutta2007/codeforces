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

int n, m, a, b[N], p[N], dp[N];

int f(int k) {
    int temp = a;

    for (int i = 0; i < k && temp >= 0; i++) {
        int j = n - k + i;
        if (b[j] < p[i])
            temp -= p[i] - b[j];
    }
    return temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> a;
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < m; i++) cin >> p[i];

    sort(b, b + n);
    sort(p, p + m);

    int lo = 0, hi = min(n, m);

    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if (f(mid) < 0)
            hi = mid - 1;
        else lo = mid;
    }

    int c = lo;

    ll cost = 0, temp = a;

    for (int i = 0; i < c; i++) {
        int j = n - c + i;
        if (b[j] + temp >= p[i]) {
            cost += min(b[j], p[i]);
            temp -= max(0, p[i] - b[j]);
        }
    }

    cout << c << " " << max(0ll, cost - temp) << "\n";

    return 0;
}