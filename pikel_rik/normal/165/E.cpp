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

const int N = 1e6 + 5;
const int num = (1 << 22) - 1;

int n, a[N], ans[num + 1];

void setto(int x, int y) {
    if (ans[x] != -1)
        return;

    ans[x] = y;
    for (int j = 0; j < 22; j++) {
        if (x & (1 << j))
            setto(x ^ (1 << j), y);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    memset(ans, -1, sizeof(ans));

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        int now = (~a[i]) & num;
        setto(now, a[i]);
    }

    for (int i = 0; i < n; i++)
        cout << ans[a[i]] << " "; cout << "\n";
    return 0;
}