#include<bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(), a.end()
using ll = long long;
using ld = long double;
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const int mod = 998244353;
const ll inf = 1e15;
int n, m;

char dch[]{'L', 'R', 'D', 'U'};
map<char, int> fuck{{'L', 0}, {'R', 1}, {'D', 2}, {'U', 3}};
int dx[]{0, 0, 1, -1};
int dy[]{-1, 1, 0, 0};


bool check(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

void run() {
    int rot, sheesh;
    cin >> n >> m >> rot >> sheesh;
    vector<string> s(n);
    
    vector dp(n, vector<ll>(m, inf));
    queue<pair<int, int>> bfs;

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '.') {
                bfs.emplace(i, j);
                dp[i][j] = 0;
            }
        }
    }
    while (!bfs.empty()) {
        auto [x, y] = bfs.front();
        bfs.pop();
        for (int d = 0; d < 4; ++d) {
            int tox = x + dx[d];
            int toy = y + dy[d];
            if (!check(tox, toy) || s[tox][toy] == '#' || s[tox][toy] == '.')
                continue;
            if (s[tox][toy] == dch[d]) continue;

            int ttx, tty, ext;
            if (s[tox][toy] == dch[d ^ 1]) {
                ttx = tox + dx[d], tty = toy + dy[d];
                ext = sheesh;
            } else {
                int dir = fuck[s[tox][toy]] ^ 1;
                ttx = tox + dx[dir], tty = toy + dy[dir];
                ext = rot;
            }

            // cout << tox << " " << toy << " " << ttx << " " << tty << endl;

            if (chmin(dp[ttx][tty], dp[x][y] + ext)) {
                bfs.emplace(ttx, tty);
            }
        }
    }
    ll res = inf;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i < n-1) chmin(res, dp[i][j] + dp[i+1][j]);
            if (j < m-1) chmin(res, dp[i][j] + dp[i][j+1]);
        }
    }
    cout << (res >= inf ? -1ll : res) << '\n';
}


signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}