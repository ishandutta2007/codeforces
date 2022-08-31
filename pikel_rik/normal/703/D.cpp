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
const int N = 1e6 + 5;

int n, a[N], b[N], last[N];
int bit[N], pref[N], ans[N], l[N], r[N];
vector<int> v, q[N];

void add(int i, int x) {
    while (i <= n) {
        bit[i] ^= x;
        i += i & -i;
    }
}

int query(int i) {
    int ans = 0;
    while (i > 0) {
        ans ^= bit[i];
        i -= i & -i;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], v.push_back(a[i]);

    sort(all(v));
    v.erase(unique(all(v)), v.end());

    for (int i = 1; i <= n; i++)
        b[i] = lower_bound(all(v), a[i]) - v.begin() + 1;

    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] ^ a[i];

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> l[i] >> r[i];
        q[r[i]].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        if (last[b[i]]) add(last[b[i]], a[i]);
        last[b[i]] = i;
        add(last[b[i]], a[i]);

        for (int j = 0; j < q[i].size(); j++) {
            int k = q[i][j];
            ans[k] = query(r[k]) ^ query(l[k] - 1) ^ pref[r[k]] ^ pref[l[k] - 1];
        }
    }

    for (int i = 0; i < m; i++) cout << ans[i] << "\n";

    return 0;
}