#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
typedef long long ll;
const int mod = 1e9 + 7;
const int INF = 0x7f7f7f7f;
const double eps = 1e-6;

const int maxn = 1010;

vector<string> s;
int dist[maxn][maxn];
int x[maxn * maxn], y[maxn * maxn];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n, m;

bool isvalid(int i, int j)
{
    return i >= 0 and i < n and j >= 0 and j < m;
}

int main()
{
    cin >> n >> m;

    pii tar, pos;
    for (int i = 0; i < n; i++)
    {
        string ss;
        cin >> ss;
        for (int ii = 0; ii < m; ii++)
        {
            if (ss[ii] == 'E')
                tar = mp(i, ii);
            if (ss[ii] == 'S')
                pos = mp(i, ii);
        }
        s.pb(ss);
    }

    memset(dist, INF, sizeof dist);

    int e = 0, b = 0;
    x[e] = tar.first;
    y[e] = tar.second;
    dist[x[e]][y[e]] = 0;
    while (b <= e)
    {
        for (int i = 0; i < 4; i++)
        {
            int xx = x[b] + dx[i];
            int yy = y[b] + dy[i];
            if (isvalid(xx, yy) and s[xx][yy] != 'T' and dist[xx][yy] > dist[x[b]][y[b]] + 1)
            {
                dist[xx][yy] = dist[x[b]][y[b]] + 1;
                e++;
                x[e] = xx;
                y[e] = yy;
            }
        }
        b++;
    }

    int cmp = dist[pos.first][pos.second];
    int ans = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (dist[i][j] <= cmp and s[i][j] != 'E' and s[i][j] != 'S')
                ans += s[i][j] - '0';

    cout << ans << endl;
    return 0;
}