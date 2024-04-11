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
const int N = 1e5 + 1;

int n, w, a[2*N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> w;
    for (int i = 0; i < 2*n; i++) cin >> a[i];

    sort(a, a + 2*n);
    double x = min({(double)a[n], (double)2 * a[0], (2 * w) / (double)(3 * n)});

    cout << fixed << setprecision(10);
    cout << (3 * n * x) / (double)2;
    return 0;
}