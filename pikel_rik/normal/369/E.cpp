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

vector<int> q[N], segs[N];
vector<pair<int, int>> qq[N];
int ans[N];

template <typename T> class FenwickTree {
public:
    int n;
    vector<T> bit;
    function<T(const T&, const T&)> f;

    FenwickTree(): n(), bit(), f() {}
    explicit FenwickTree(int n, function<T(const T&, const T&)> func = plus<T>()): n(n + 1), bit(n + 1, 0), f(move(func)) {}

    void add(int i, int val) {
        while (i < n) {
            bit[i] = f(bit[i], val);
            i += i & -i;
        }
    }
    T query(int i) {
        T sum = T();
        while (i > 0) {
            sum = f(sum, bit[i]);
            i -= i & -i;
        }
        return sum;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        segs[r].push_back(l);
    }

    for (int i = 0; i < m; i++) {
        int cnt;
        cin >> cnt;

        q[i] = {0};
        for (int j = 0, x; j < cnt; j++) {
            cin >> x;
            q[i].push_back(x);
        }
        q[i].push_back((int)1e6 + 1);
    }

    for (int i = 0; i < m; i++) {
        for (int j = 1; j < q[i].size(); j++) {
            qq[q[i][j] - 1].emplace_back(q[i][j - 1] + 1, i);
        }
    }

    FenwickTree<int> ft((int)1e6);
    for (int i = 0; i <= (int)1e6; i++) {
        for (int y : segs[i]) {
            ft.add(y, 1);
        }
        for (auto &[x, id]: qq[i]) {
            if (i >= x)
                ans[id] += ft.query(i) - ft.query(x - 1);
        }
    }

    for (int i = 0; i < m; i++)
        cout << n - ans[i] << "\n";
    return 0;
}