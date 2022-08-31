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

int n, m, a[N], p[N];
vector<int> v[N];

int find(int x) {
    if (x == p[x])
        return x;
    return p[x] = find(p[x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    iota(p, p + N, 0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        v[a[i]].push_back(i);
    }

    int c = n - 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] == a[i - 1])
            c--;
    }

    cout << c << "\n";

    int q = m - 1;
    while (q--) {
        int x, y;
        cin >> x >> y;

        x = find(x);
        y = find(y);

        if (v[x].size() >= v[y].size()) {
            for (int i : v[y]) {
                if (find(a[i - 1]) == x)
                    c--;
                if (find(a[i + 1]) == x)
                    c--;
                v[x].push_back(i);
            }
            p[y] = x;
            v[y].clear();
        }
        else {
            for (int i : v[x]) {
                if (find(a[i - 1]) == y)
                    c--;
                if (find(a[i + 1]) == y)
                    c--;
                v[y].push_back(i);
            }
            p[x] = y;
            v[x].clear();
        }

        cout << c << "\n";
    }
    return 0;
}