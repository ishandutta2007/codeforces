#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME aplusb

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int MAXN = 1005;

int n, m, k;
int field[MAXN][MAXN];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char s[MAXN];

vector<pii> there;
int cnt = 0;
bool used[MAXN][MAXN];

int dfs(int x, int y) {
    there.puba({x, y});
    used[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < m) {
            if (field[nx][ny]) {
                ++cnt;
                //cerr << nx << " " << ny << endl;
            } else if (!used[nx][ny]) {
                dfs(nx, ny);
            }
        }
    }
    return 0;
}

int ans[MAXN][MAXN];

int main() {        
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        for (int j = 0; j < m; ++j) {
            if (s[j] == '*') {
                field[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!used[i][j] && !field[i][j]) {
                there.clear();
                cnt = 0;
                dfs(i, j);
                //cerr << "@" << endl;
                for (auto p: there) {
                    //cerr << p.ff << " " << p.ss << endl;
                    ans[p.ff][p.ss] = cnt;
                }
            }
        }
    }

    for (int i = 0; i < k; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x; --y;
        cout << ans[x][y] << "\n";
    }

    return 0;
}