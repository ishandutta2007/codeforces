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
const int N = 1e6 + 5;

int n, a[N];

int highbit(int x) {
    while (x & (x - 1)) {
        x -= x & -x;
    }
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;

    for (int i = n; i >= 1; i--) {
        if (a[i]) continue;
        int num = highbit(i) << 1;
        num--;

        num = (~i) & num;
        a[i] = num;
        a[num] = i;
    }

    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += (i ^ a[i]);
    }

    cout << ans << "\n";
    for (int i = 0; i <= n; i++) {
        cout << a[i] << " ";
    } cout << "\n";

    return 0;
}