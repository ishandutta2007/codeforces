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

int n, cur[3*N], last[3*N];
pair<pair<int, int>, pair<int, int>> a[N];

vector<int> v1[3*N], v2[3*N];
map<int, int> mp[3*N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<int> coord; coord.reserve(4*n);

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (x1 > x2)
            swap(x1, x2);
        if (y1 > y2)
            swap(y1, y2);
        a[i] = {{x1, y1}, {x2, y2}};

        coord.push_back(x1);
        coord.push_back(x2);
        coord.push_back(y1);
        coord.push_back(y2);
    }

    sort(all(coord));
    coord.resize(unique(all(coord)) - coord.begin());

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        tie(x1, y1) = a[i].first;
        tie(x2, y2) = a[i].second;

        x1 = lower_bound(all(coord), x1) - coord.begin() + 1;
        y1 = lower_bound(all(coord), y1) - coord.begin() + 1;
        x2 = lower_bound(all(coord), x2) - coord.begin() + 1;
        y2 = lower_bound(all(coord), y2) - coord.begin() + 1;

        if (x1 == x2) {
            mp[x1][y1]++;
            mp[x1][y2]--;
        }
        else {
            v1[x1].push_back(y1);
            v2[x2].push_back(y1);
        }
    }

    ll ans = 0;
    FenwickTree<int> ft(coord.size());

    for (int x = 1; x <= coord.size(); x++) {
        for (int y : v1[x]) {
            cur[y]++;
            if (cur[y] == 1) {
                last[y] = x;
                ft.add(y, 1);
            }
        }

        int lst = 0, cr = 0;
        for (auto &[y, c] : mp[x]) {
            if (!cr)
                lst = y;
            cr += c;
            if (!cr) {
                ans += coord[y - 1] - coord[lst - 1] + 1 - (ft.query(y) - ft.query(lst - 1));
            }
        }

        for (int y : v2[x]) {
            cur[y]--;
            if (!cur[y]) {
                ft.add(y, -1);
                ans += coord[x - 1] - coord[last[y] - 1] + 1;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}