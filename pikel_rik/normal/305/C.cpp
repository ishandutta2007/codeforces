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

    int n, tcnt = 0, tmax = 0;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[n - i - 1];

    while (n > 0) {
        int j = n - 1, cnt;
        while (j > 0 and a[j - 1] == a[n - 1]) --j;

        cnt = n - j;
        if (cnt % 2 == 1) {
            tcnt++; n--;
            if (a[n] > tmax) tmax = a[n];
        }

        cnt /= 2;
        n -= cnt;
        for (int i = 0; i < cnt; i++) a[n - i - 1]++;
    }

    cout << tmax - tcnt + 1 << "\n";
    return 0;
}