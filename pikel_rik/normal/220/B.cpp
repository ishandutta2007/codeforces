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
const int N = 1e5 + 5;
const int B = 318;

struct query {
    int l, r, id;
}q[N];

bool comp (query x, query y) {
    if (x.l/B != y.l/B)
        return x.l/B < y.l/B;
    return x.r < y.r;
}

int n, a[N], ans[N], cnt[N], cur = 0;

void add (int x) {
    if (cnt[a[x]] == a[x])
        cur--;
    cnt[a[x]]++;
    if (cnt[a[x]] == a[x])
        cur++;
}

void remove (int x) {
    if (cnt[a[x]] == a[x])
        cur--;
    cnt[a[x]]--;
    if (cnt[a[x]] == a[x])
        cur++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i], a[i] > n ? a[i] = n + 1 : a[i] = a[i];

    for (int i = 0; i < m; i++) {
        cin >> q[i].l >> q[i].r;  --q[i].l; --q[i].r;
        q[i].id = i;
    }

    sort(q, q + m, comp);

    int cur_l = 0, cur_r = 0;
    add(0);

    for (int i = 0; i < m; i++) {
        while (q[i].l < cur_l) {
            add(cur_l - 1);
            cur_l -= 1;
        }

        while (q[i].l > cur_l) {
            remove(cur_l);
            cur_l += 1;
        }

        while (q[i].r < cur_r) {
            remove(cur_r);
            cur_r -= 1;
        }

        while (q[i].r > cur_r) {
            add(cur_r + 1);
            cur_r += 1;
        }

        ans[q[i].id] = cur;
    }

    for (int i = 0; i < m; i++) cout << ans[i] << "\n";
    return 0;
}