#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ordered_set = tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e3 + 4;

int n, k, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    int best = inf, best_c = 1000;
    for (int i = 1; i <= 1000; i++) {
        int c = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] != i + k * j)
                c += 1;
        }
        if (c < best_c) {
            best_c = c;
            best = i;
        }
    }

    cout << best_c << "\n";
    for (int i = 0; i < n; i++) {
        if (a[i] < best + k * i) {
            cout << "+ " << i + 1 << " " << best + k * i - a[i] << "\n";
        }
        else if (a[i] > best + k * i) {
            cout << "- " << i + 1 << " " << a[i] - (best + k * i) << "\n";
        }
    }
    return 0;
}