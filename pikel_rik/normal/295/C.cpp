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
const int N = 50 + 5;

bool computed;
int c[N + 1][N + 1];

int choose(int n, int k) {
    if (!computed) {
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0 or j == i)
                    c[i][j] = 1;
                else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
            }
        }
        computed = true;
    }
    return c[n][k];
}

struct item {
    int i, j, f;
    item(int i, int j, int f) : i(i), j(j), f(f) {}
};

int n, k, a[N], c1, c2, lvl[N][N][2], ways[N][N][2];
bool visited[N][N][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    choose(0, 0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] /= 50;
    }

    k /= 50;

    for (int i = 0; i < n; i++) {
        if (a[i] == 1)
            c1++;
        else c2++;
    }

    queue<item> q;
    q.emplace(0, 0, 0);

    lvl[0][0][0] = 0;
    ways[0][0][0] = 1;
    visited[0][0][0] = true;

    while (!q.empty()) {
        item x = q.front();
        q.pop();

        if (x.f) {
            for (int k1 = 0; k1 <= x.i; k1++) {
                for (int k2 = 0; k2 <= x.j; k2++) {
                    if (k1 + 2 * k2 <= 0 or k1 + 2 * k2 > k) continue;
                    if (!visited[x.i - k1][x.j - k2][0]) {
                        q.emplace(x.i - k1, x.j - k2, 0);
                        visited[x.i - k1][x.j - k2][0] = true;
                        lvl[x.i - k1][x.j - k2][0] = lvl[x.i][x.j][x.f] + 1;
                    }
                    if (lvl[x.i - k1][x.j - k2][0] == lvl[x.i][x.j][x.f] + 1)
                        ways[x.i - k1][x.j - k2][0] = (ways[x.i - k1][x.j - k2][0] + c[x.i][k1] * (ll)c[x.j][k2] % mod * (ll)ways[x.i][x.j][x.f] % mod) % mod;
                }
            }
        }
        else {
            for (int k1 = 0; k1 <= c1 - x.i; k1++) {
                for (int k2 = 0; k2 <= c2 - x.j; k2++) {
                    if (k1 + 2 * k2 <= 0 or k1 + 2 * k2 > k) continue;
                    if (!visited[x.i + k1][x.j + k2][1]) {
                        q.emplace(x.i + k1, x.j + k2, 1);
                        visited[x.i + k1][x.j + k2][1] = true;
                        lvl[x.i + k1][x.j + k2][1] = lvl[x.i][x.j][x.f] + 1;
                    }

                    if (lvl[x.i + k1][x.j + k2][1] == lvl[x.i][x.j][x.f] + 1)
                        ways[x.i + k1][x.j + k2][1] = (ways[x.i + k1][x.j + k2][1] + c[c1 - x.i][k1] * (ll)c[c2 - x.j][k2] % mod * (ll)ways[x.i][x.j][x.f] % mod) % mod;
                }
            }
        }
    }

    if (!ways[c1][c2][1]) {
        cout << "-1\n0\n";
        return 0;
    }

    cout << lvl[c1][c2][1] << "\n" << ways[c1][c2][1] << "\n";
    return 0;
}