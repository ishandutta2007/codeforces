//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 1000 + 10;
string s[maxn];
bool isol[maxn][maxn];
int dis[maxn][maxn];
pii root[maxn][maxn];
int n, m, qq;
vector<pii> q;

int dx[] = {-1, -0, +0, +1},
    dy[] = {-0, -1, +1, +0};

inline bool is_valid(int x, int y) {
    return 0 <= x and x < n and 0 <= y and y < m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    cin >> n >> m >> qq;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    memset(isol, true, sizeof isol);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int d = 0; d < 4; d++) {
                int ii = i + dx[d];
                int jj = j + dy[d];
                if (is_valid(ii, jj) and s[i][j] == s[ii][jj])
                    isol[i][j] = false;
            }
    memset(dis, 63, sizeof dis);
    memset(root, -1, sizeof root);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!isol[i][j]) {
                dis[i][j] = 0;
                root[i][j] = MP(i, j);
                q.PB(MP(i, j));
            }
    for (int i = 0; i < sz(q); i++) {
        int x = q[i].L, y = q[i].R;
        for (int d = 0; d < 4; d++) {
            int xx = x + dx[d];
            int yy = y + dy[d];
            if (is_valid(xx, yy)
                    and isol[xx][yy]
                    and dis[x][y] + 1 < dis[xx][yy]) {
                dis[xx][yy] = dis[x][y] + 1;
                root[xx][yy] = root[x][y];
                q.PB(MP(xx, yy));
            }
        }
    }
    while (qq--) {
        int fi, se;
        LL th;
        cin >> fi >> se >> th;
        fi--, se--;
        smin(th, 1000 * 1000 * 1000LL + (th & 1));
        if (th < dis[fi][se])
            cout << s[fi][se] << '\n';
        else {
            int x = root[fi][se].L,
                y = root[fi][se].R;
            cout << ((s[x][y] - '0') ^ (th & 1)) << '\n';
        }
    }
	return 0;
}