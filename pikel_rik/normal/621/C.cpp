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

int n, prime, l[N], r[N];
long double p[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> prime;
    for (int i = 0; i < n; i++) cin >> l[i] >> r[i];

    for (int i = 0; i < n; i++) {
        int l1 = l[i], r1 = r[i];
        if (l1 % prime != 0)
            l1 += prime - l1 % prime;

        p[i] = (l1 > r1 ? 0 : (r1 - l1) / prime + 1);
        p[i] /= (r[i] - l[i] + 1);
    }

    p[n] = p[0];

    long double e1 = 0, e2 = 0;
    for (int i = 1; i < n; i++) {
        e1 += p[i - 1] * (1 - p[i]) * (1 - p[i + 1]) + (1 - p[i - 1]) * (1 - p[i]) * p[i + 1];
        e2 += p[i - 1] * p[i + 1] * (1 - p[i]) + p[i];
    }

    e1 += p[n - 1] * (1 - p[0]) * (1 - p[1]) + (1 - p[n - 1]) * (1 - p[0]) * p[1];
    e2 += p[n - 1] * p[1] * (1 - p[0]) + p[0];

    cout << fixed << setprecision(12);
    cout << 1000 * e1 + 2000 * e2 << "\n";
    return 0;
}