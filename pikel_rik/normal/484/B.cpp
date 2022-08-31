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
const int N = 2e5 + 5;
const int A = 1e6;

int n, a[N], cnt[2*A];

bool f(int x) {
    for (int i = upper_bound(a, a + n, x) - a; i < n; i++) {
        for (int j = a[i]; j <= A; j += a[i]) {
            if (cnt[j + a[i] - 1] - cnt[j + x - 1] > 0)
                return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);
    n = unique(a, a + n) - a;

    for (int i = 0; i < n; i++) cnt[a[i]]++;
    for (int i = 1; i < (int)2e6; i++) cnt[i] += cnt[i - 1];

    int lo = 0, hi = (int)1e6;

    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if (f(mid))
            lo = mid;
        else hi = mid - 1;
    }
    cout << lo << "\n";
    return 0;
}