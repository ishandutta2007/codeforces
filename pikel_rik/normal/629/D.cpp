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
const double pi = acos(-1.0);
const int N = 1e5 + 5;

int n, tsize;
ll v[N], temp[N], seg[2*N], dp[N];

inline ll combine(ll a, ll b) {
    return max(a, b);
}

ll query(int l, int r) {
    ll ans = 0;
    for (l += tsize, r += tsize; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ans = combine(ans, seg[l++]);
        if (r & 1) ans = combine(ans, seg[--r]);
    }
    return ans;
}

void update (int i, ll val) {
    for (seg[i += tsize] = val; i > 1; i >>= 1)
        seg[i >> 1] = combine(seg[i], seg[i ^ 1]);
}

map<ll, int> m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int r, h; cin >> r >> h;
        v[i] = r * (ll) r * h;
        temp[i] = v[i];
    }

    sort(temp, temp + n);
    tsize = unique(temp, temp + n) - temp;

    for (int i = 0; i < tsize; i++)
        m[temp[i]] = i + 1;

    for (int i = 0; i < n; i++) {
        ll mx = query(1, m[v[i]]);
        update(m[v[i]], mx + v[i]);
        dp[i] = mx + v[i];
    }

    cout << fixed << setprecision(12);
    cout << pi * query(1, tsize + 1) << "\n";
    return 0;
}