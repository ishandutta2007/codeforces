#include <bits/stdc++.h>
 
using namespace std;
 
#define aidar asadulin
 
//#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld long double
 
const int inf = 1e9;
const int max_n = 2001;

int n, m;
string a[max_n];
bool used[max_n][max_n];

bool check(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

bool bad(int x, int y) {
    if (!check(x, y) || a[x][y] == '.') return false;

    for(int xs = -1;xs <= 1;xs += 2) {
        for(int ys = -1;ys <= 1;ys += 2) {
            int cnt = 0;
            for(int dx = 0;dx <= 1;dx++) {
                for(int dy = 0;dy <= 1;dy++) {
                    int to_x = xs * dx + x;
                    int to_y = ys * dy + y;
                    if (!check(to_x, to_y) || a[to_x][to_y] == '*') cnt++;
                }
            }
            if (cnt == 1) return true;
        }
    }
    return false;
}

void bfs() {
    deque<pii> bfs;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            if (bad(i, j)) {
                used[i][j] = true;
                bfs.emplace_back(i, j);
            }
        }
    }

    while(sz(bfs)) {
        pii v = bfs.front();
        bfs.pop_front();

        a[v.fi][v.se] = '.';

        for(int i = v.fi - 1;i <= v.fi + 1;i++) {
            for(int j = v.se - 1;j <= v.se + 1;j++) {
                if (!used[i][j] && bad(i, j)) {
                    used[i][j] = true;
                    bfs.emplace_back(i, j);
                }
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for(int i = 0;i < n;i++)
        cin >> a[i];

    bfs();

    for(int i = 0;i < n;i++)
        cout << a[i] << endl;
}


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}