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

int n, k;
string s;

bool ok(int l) {
    int c1 = 0, c2 = 0;
    for (int i = 0; i < l; i++) {
        if (s[i] == 'a') c1 += 1;
        else c2 += 1;
    }

    bool flag = (c1 <= k or c2 <= k);
    for (int i = 1; i + l - 1 < n; i++) {
        if (s[i-1] == 'a') c1 -= 1;
        else c2 -= 1;

        if (s[i + l - 1] == 'a') c1 += 1;
        else c2 += 1;

        flag |= (c1 <= k or c2 <= k);
    }
    return flag;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> k;
    cin >> s;

    int lo = 1, hi = n;

    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if (ok(mid))
            lo = mid;
        else hi = mid - 1;
    }

    cout << lo << "\n";
    return 0;
}