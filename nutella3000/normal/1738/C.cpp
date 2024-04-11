#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const int inf = 1e9 + 7;
const int N = 102;

bool dp[N][N][2];

pair<int, int> fuck(int x, int y, int k) {
    x -= 1 - k;
    y -= k;
    return {x, y};
}

void run() {
    int n;
    cin >> n;
    array<int, 2> a = {0, 0};
    for (int i = 0; i < n; ++i) {
        int v; cin >> v;
        ++a[v & 1];
    }

    for (int i = 0; i <= a[0]; ++i) {
        for (int j = 0; j <= a[1]; ++j) {
            for (int k = 0; k < 2; ++k) {
                dp[i][j][k] = false;
            }
        }
    }
    dp[0][0][0] = true;

    for (int i = 0; i <= a[0]; ++i) {
        for (int j = 0; j <= a[1]; ++j) {
            for (int k = 0; k < 2; ++k) {
                for (int my = 0; my < 2; ++my) {
                    auto [i1, j1] = fuck(i, j, my);
                    if (i1 < 0 || j1 < 0) continue;
                    if (i1 == 0 && j1 == 0) {
                        dp[i][j][k] |= dp[0][0][k^my];
                        continue;
                    }

                    bool good = true;
                    for (int him = 0; him < 2; ++him) {
                        auto [i2, j2] = fuck(i1, j1, him);
                        if (i2 < 0 || j2 < 0) continue;
                        good &= dp[i2][j2][k^my];
                    }
                    dp[i][j][k] |= good;
                }
            }
        }
    }
    cout << (dp[a[0]][a[1]][0] ? "Alice" : "Bob") << '\n';
}


signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}