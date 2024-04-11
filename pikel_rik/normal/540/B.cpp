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

    int n, k, p, x, y;
    cin >> n >> k >> p >> x >> y;

    vector<int> a(k);
    for (int i = 0; i < k; i++) cin >> a[i];

    int sum = accumulate(all(a), 0) + n - k;

    vector<int> temp(n, 1);
    for (int i = 0; i < k; i++) temp[i] = a[i];

    sort(all(temp));
    int c = 0;

    while (c < n - k and temp[(temp.size() - 1) / 2] < y) {
        temp[0] = y;
        sum += y - 1;
        c += 1;
        sort(all(temp));
    }

    if (sum <= x and temp[(temp.size() / 2)] >= y) {
        for (int i = 0; i < c; i++) cout << y << " ";
        for (int i = 0; i < n - k - c; i++) cout << 1 << " ";
    }
    else cout << "-1\n";
    return 0;
}