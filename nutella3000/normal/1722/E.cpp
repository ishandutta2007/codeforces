#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const int inf = 1e9 + 7;
const int N = 1005;
ll p[N][N];

void run() {
    int n, q; cin >> n >> q;
    for (int i = 0; i <= 1000; ++i)
        fill(p[i], p[i] + N, 0);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        p[x][y] += x*y;
    }
    for (int i = 1; i <= 1000; ++i) {
        for (int j = 1; j <= 1000; ++j) {
            p[i][j] += p[i-1][j] + p[i][j-1] - p[i-1][j-1];
        }
    }
    while (q--) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2; --x2, --y2;
        cout << p[x2][y2] - p[x1][y2] - p[x2][y1] + p[x1][y1] << '\n';
    }
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}