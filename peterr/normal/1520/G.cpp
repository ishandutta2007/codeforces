#include <bits/stdc++.h>

using namespace std;

const long long INFINF = 1E18;
const int INF = 1E9;
const int MAXN = 2E3;
int board[MAXN][MAXN];
int dist1[MAXN][MAXN];
int dist2[MAXN][MAXN];
int dr[4] = {0, -1, 0, 1};
int dc[4] = {1, 0, -1, 0};

void bfs(int startRow, int startCol, int dist[MAXN][MAXN], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        fill(dist[i], dist[i] + m, INF);
    }
    queue<pair<int, int>> q;
    q.push({startRow, startCol});
    dist[startRow][startCol] = 0;
    while (!q.empty())
    {
        pair<int, int> pr = q.front();
        q.pop();
        int r = pr.first;
        int c = pr.second;
        for (int i = 0; i < 4; i++)
        {
            int newr = r + dr[i];
            int newc = c + dc[i];
            if (newr < 0 || newc < 0 || newr >= n || newc >= m || dist[newr][newc] != INF || board[newr][newc] == -1)
                continue;
            dist[newr][newc] = dist[r][c] + 1;
            q.push({newr, newc});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, w;
    cin >> n >> m >> w;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    bfs(0, 0, dist1, n, m);
    bfs(n - 1, m - 1, dist2, n, m);
    /*
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "dist1 " << i << " " << j << " " << dist2[i][j] << endl;
        }
    }
    */
    long long d1 = INFINF;
    long long d2 = INFINF;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] <= 0)
                continue;
            if (dist1[i][j] != INF)
                d1 = min(d1, (long long) dist1[i][j] * w + board[i][j]);
            if (dist2[i][j] != INF)
                d2 = min(d2, (long long) dist2[i][j] * w + board[i][j]);
        }
    }
    long long ans = INFINF;
    if (d1 != INFINF && d2 != INFINF)
    {
        ans = min(ans, d1 + d2);
    }
    if (dist1[n - 1][m - 1] != INF)
    {
        ans = min(ans, (long long) dist1[n - 1][m - 1] * w);
    }
    if (ans == INFINF)
        ans = -1;
    cout << ans << "\n";
    return 0;
}