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
const int N = 100 + 5;

int n, a[2*N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < 2*n - 1; i++) cin >> a[i];

    int sum = 0;
    for (int i = 0; i < 2*n - 1; i++)
        sum += abs(a[i]);

    int c = 0;
    for (int i = 0; i < 2*n - 1; i++) {
        if (a[i] < 0)
            c++;
    }

    if ((n & 1) or c % 2 == 0) {
        cout << sum << "\n";
        return 0;
    }

    sort(a, a + 2*n - 1, [&] (int x, int y) {
        return abs(x) < abs(y);
    });
    sum -= 2 * abs(a[0]);
    cout << sum << "\n";
    return 0;
}