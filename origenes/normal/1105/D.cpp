#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 1123;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

char mat[maxn][maxn];
int s[10], n, m, p, cnt[10];
queue<pii> q;

int main() {
    scanf("%d%d%d", &n, &m, &p);
    FOR(i, 1, p) scanf("%d", s + i);
    FOR(i, 1, n) scanf("%s", mat[i] + 1);
    vector<pair<char, pii>> vec;
    FOR(i, 1, n) FOR(j, 1, m) if (mat[i][j] != '.' && mat[i][j] != '#')
                vec.eb(mat[i][j], mp(i, j));
    sort(all(vec));
    for (const auto &it : vec) q.push(it._2);
    while (!q.empty()) {
        auto u = q.front();
        char now = mat[u._1][u._2];
        queue<pair<int, pii>> tmp;
        while (!q.empty() && mat[q.front()._1][q.front()._2] == now) {
            tmp.push(mp(s[now - '0'], q.front()));
            q.pop();
        }
        while (!tmp.empty() && tmp.front()._1) {
            int k = tmp.front()._1, x = tmp.front()._2._1, y = tmp.front()._2._2;
            tmp.pop();
            REP(i, 4) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 1 || nx > n || ny < 1 || ny > m || mat[nx][ny] != '.') continue;
                mat[nx][ny] = now;
                tmp.push(mp(k - 1, mp(nx, ny)));
            }
        }
        while (!tmp.empty()) q.push(tmp.front()._2), tmp.pop();
    }
    FOR(i, 1, n) FOR(j, 1, m) if (mat[i][j] != '#' && mat[i][j] != '.') cnt[mat[i][j] - '0']++;
    FOR(i, 1, p) printf("%d ", cnt[i]);
}