#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const int inf = 1e9 + 7;
const int N = 55;

int used[N][N];
int n, m;
string s[N];

void run() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        fill(used[i], used[i] + m, 0);
    }

    int dx[]{-1, 0, 1, 0, -1, -1, -1, 1, 1};
    int dy[]{0, -1, 0, 1, 0, -1, 1, -1, 1};

    auto f = [](int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < m && !used[x][y] && s[x][y] == '*';
    };
    int cnt = 1;
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            if (used[x][y] || s[x][y] != '*') continue;
            for (int d = 0; d < 4; ++d) {
                if (f(x+dx[d], y+dy[d]) && f(x+dx[d+1], y+dy[d+1])) {
                    used[x][y] = used[x+dx[d]][y+dy[d]] = used[x+dx[d+1]][y+dy[d+1]] = cnt++;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int d = 0; d < 9; ++d) {
                if (!used[i][j] && s[i][j] == '*') {
                    cout << "NO\n";
                    return;
                }
                int x = i+dx[d], y = j+dy[d];
                if (x >= 0 && y >= 0 && x < n && y < m && used[x][y] && used[i][j] && used[x][y] != used[i][j]) {
                    cout << "NO" << '\n';
                    return;
                }
            }
        }
    }
    cout << "YES\n";
}
signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}