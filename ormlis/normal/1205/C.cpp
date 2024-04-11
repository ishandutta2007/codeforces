#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

// using namespace __gnu_pbds;
/*
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
*/

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const int INFi = 1e9 + 5;
const int maxN = 3e5 + 5;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n;
    cin >> n;
    auto ask = [&](int x1, int y1, int x2, int y2) {
        cout << "? " << x1 + 1 << ' ' << y1 + 1 << ' ' << x2 + 1 << ' ' << y2 + 1 << endl;
        int t;
        cin >> t;
        assert(t != -1);
        return t ^ 1;
    };
    vector<vector<int>> a(n, vector<int>(n, -1));
    a[0][0] = 1;
    a[n - 1][n - 1] = 0;
    range(i, n) {
        range(j, n) {
            if ((i + j) % 2) continue;
            if (a[i][j] != -1) continue;
            if (i >= 2) {
                a[i][j] = ask(i - 2, j, i, j) ^ a[i - 2][j];
            } else if (j >= 2) {
                a[i][j] = ask(i, j - 2, i, j) ^ a[i][j - 2];
            } else {
                a[i][j] = ask(i - 1, j - 1, i, j) ^ a[i - 1][j - 1];
            }
        }
    }
    int l, r = -1;
    int to;
    for (int i = 1; i < n - 1; ++i) {
        if (a[i - 1][i - 1] != a[i + 1][i + 1]) {
            l = i - 1;
            r = i + 1;
            break;
        }
    }
    assert(r != -1);
    queue<pair<int, int>> q;
    if (ask(l, l, r - 1, r) == 0) {
        a[r - 1][r] = a[l][l];
        q.push({r - 1, r});
    } else if (ask(l + 1, l, r, r) == 0) {
        a[l + 1][l] = a[r][r];
        q.push({l + 1, l});
    } else {
        if (a[l + 1][l + 1] == a[r][r]) {
            a[l + 1][l] = a[r][r] ^ 1;
            q.push({l + 1, l});
        } else {
            a[l + 1][r] = a[l][l] ^ 1;
            q.push({l + 1, r});
        }
    }
    while(!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        for(int di = -2; di <= 2; ++di) {
            for(int dj = -2; dj <= 2; ++dj) {
                if (abs(di) + abs(dj) != 2) continue;
                if (i + di < 0 || i + di >= n) continue;
                if (j + dj < 0 || j + dj >= n) continue;
                if (di < 0 && dj > 0) continue;
                if (di > 0 && dj < 0) continue;
                int i2 = i + di;
                int j2 = j + dj;
                if (a[i2][j2] != -1) continue;
                if (di + dj < 0) {
                    a[i2][j2] = ask(i2, j2, i, j) ^ a[i][j];
                } else {
                    a[i2][j2] = ask(i, j, i2, j2) ^ a[i][j];
                }
                q.push({i2, j2});
            }
        }
    }
    cout << "!" << endl;
    range(i, n) {
        range(j, n) cout << a[i][j];
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}