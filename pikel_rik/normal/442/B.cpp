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
const int N = 100 + 5;

int n;
double a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);
    double best = 0;

    for (int i = 0; i < n; i++) {
        double p = 0, running = 1;
        for (int j = i; j < n; j++) {
            p = (1 - a[j]) * p + running * a[j];
            running *= (1 - a[j]);
            best = max(best, p);
        }
    }

    cout << fixed << setprecision(12);
    cout << best << "\n";
    return 0;
}