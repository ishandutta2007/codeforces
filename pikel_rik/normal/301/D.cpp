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

template <typename T> class FenwickTree {
public:
    #define F function<T(const T&, const T&)>

    int n;
    vector<T> bit;
    F f;

    FenwickTree(): n(), bit(), f() {}
    explicit FenwickTree(int n, F func = plus<T>()): n(n), bit(n + 1, 0), f(func) {}

    void add(int i, int val) {
        while (i <= n) {
            bit[i] = f(bit[i], val);
            i += i & -i;
        }
    }
    T query(int i) {
        T ans = T();
        while (i > 0) {
            ans = f(ans, bit[i]);
            i -= i & -i;
        }
        return ans;
    }
};

int n, m, a[N], pos[N], ans[N];
vector<int> q1[N];
vector<pair<int, int>> q2[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i], pos[a[i]] = i;

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            q1[max(pos[j], pos[i])].push_back(min(pos[j], pos[i]));
        }
    }

    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        q2[r].emplace_back(l, i);
    }

    FenwickTree<int> ft(n);
    for (int i = 1; i <= n; i++) {
        for (int j : q1[i]) {
            ft.add(j, 1);
        }
        for (auto &[l, id]: q2[i]) {
            ans[id] += ft.query(i) - ft.query(l - 1);
        }
    }

    for (int i = 0; i < m; i++)
        cout << ans[i] << "\n";
    return 0;
}