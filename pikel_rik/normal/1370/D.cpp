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
const int N = 2e5 + 5;

int n, k, a[N];

bool f(int x) {
    int target = (k + 1) / 2, cur = 0;
    for (int i = 0; i < (k % 2 != 0 ? n : n - 1); i++) {
        if (a[i] <= x) {
            cur++;
            i++;
        }
    }

    if (cur >= target)
        return true;

    target = k / 2;
    cur = 0;

    for (int i = 1; i < (k % 2 == 0 ? n : n - 1); i++) {
        if (a[i] <= x) {
            cur++;
            i++;
        }
    }

    return cur >= target;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    int lo = 1, hi = 1e9;

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (f(mid))
            hi = mid;
        else lo = mid + 1;
    }

    cout << lo << "\n";
    return 0;
}