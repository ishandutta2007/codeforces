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
bool mark[maxn][maxn];
int n, m;

int dx[] = {-1, -0, +0, +1};
int dy[] = {-0, -1, +1, +0};

inline bool is_valid(int x, int y) {
    return 0 <= x and x < n and 0 <= y and y < m;
}

void dfs(int x, int y) {
    mark[x][y] = true;
    for (int d = 0; d < 4; d++) {
        int xx = x + dx[d];
        int yy = y + dy[d];
        if (is_valid(xx, yy) and !mark[xx][yy] and s[xx][yy] == '#')
            dfs(xx, yy);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        string tmp = s[i];
        tmp.resize(unique(all(tmp)) - tmp.begin());
        if (sz(tmp) >= 4 or (sz(tmp) == 3 and tmp[0] == '#'))
            return cout << -1 << endl, 0;
    }
    for (int j = 0; j < m; j++) {
        string tmp;
        for (int i = 0; i < n; i++)
            tmp += s[i][j];
        tmp.resize(unique(all(tmp)) - tmp.begin());
        if (sz(tmp) >= 4 or (sz(tmp) == 3 and tmp[0] == '#'))
            return cout << -1 << endl, 0;
    }
    bool rmark[n] = {false};
    bool cmark[m] = {false};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] == '#')
                rmark[i] = cmark[j] = true;
    bool rfound = count(rmark, rmark + n, false),
         cfound = count(cmark, cmark + m, false);
    if (rfound ^ cfound)
        return cout << -1 << endl, 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!mark[i][j] and s[i][j] == '#')
                dfs(i, j), ans++;
    cout << ans << endl;
	return 0;
}