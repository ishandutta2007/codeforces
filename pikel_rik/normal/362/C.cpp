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
const int N = 5000 + 5;

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

int n, a[N], smaller[N][N];
bool visited[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    int swaps = 0, best = 0, c = 1; {
        FenwickTree<int> ft(n);
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                smaller[j][i] = j - ft.query(j);
            }
            ft.add(a[i] + 1, 1);
            swaps += smaller[a[i]][i];
        }
    }

    best = swaps;
    for (int i = 0; i < n; i++) {
        FenwickTree<int> ft(n);
        ft.add(a[i] + 1, 1);

        for (int j = i + 1; j < n; j++) {
            ft.add(a[j] + 1, 1);
            if (a[i] < a[j]) continue;

            int temp = swaps;
            temp -= smaller[a[i]][i] + smaller[a[j]][j];
            temp += smaller[a[i]][j] + smaller[a[j]][i] - 1;
            temp -= ft.query(a[i]) - ft.query(a[j] + 1);

            if (temp < best) {
                best = temp;
                c = 1;
            }
            else if (temp == best) {
                c++;
            }
        }
    }

    cout << best << " " << c << "\n";
    return 0;
}