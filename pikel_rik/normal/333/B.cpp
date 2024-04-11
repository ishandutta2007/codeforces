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

const int M = 1e5 + 5;
const int N = 1e3 + 5;

struct point {
    int r, c;
    point(): r(), c() {}
    point(int _r, int _c): r(_r), c(_c) {}
};

int n, m;
point a[M];
bool badr[N], badc[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i].r >> a[i].c;
        a[i].r--; a[i].c--;
    }

    for (int i = 0; i < m; i++) {
        badr[a[i].r] = true;
        badc[a[i].c] = true;
    }

    int c = 0;
    vector<int> ori(n);

    for (int i = 1; i < n - 1; i++) {
        if (badc[i]) continue;
        ori[i] = 1;
        c++;
    }

    for (int i = 1; i < n - 1; i++) {
        if (badr[i])
            continue;

        if (i == n - i - 1) {
            if (ori[i] == 0)
                c++;
            continue;
        }

        if ((ori[i] == 0 or ori[n - i - 1] == 0) or (ori[i] != ori[n - i - 1])) {
            c++;
            continue;
        }

        if (ori[i] == 1 and ori[n - i - 1] == 1) {
            ori[i] = -1;
            c++;
        }
    }

    cout << c << "\n";
    return 0;
}