#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
const int MAXK = 40;
int color[MAXN + 1][MAXN + 1];
bool visited[MAXN + 1][MAXN + 1];
int dp[MAXK + 1][MAXN + 1][MAXN + 1];
int colorDist[MAXK + 1][MAXK + 1];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1 , 0, 0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> color[i][j];
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
            fill(visited[j] + 1, visited[j] + m + 1, false);
        queue<tuple<int, int, int>> q;
        for (int r = 1; r <= n; r++)
            for(int c = 1; c <= m; c++)
                if (color[r][c] == i)
                {
                    visited[r][c] = true;
                    q.push(make_tuple(r, c, 1));
                }
        while (!q.empty())
        {
            tuple<int, int, int> t = q.front();
            q.pop();
            int r = get<0>(t);
            int c = get<1>(t);
            int dist = get<2>(t);
            dp[i][r][c] = dist;
            for (int x = 0; x < 4; x++)
            {
                int newr = r + dx[x];
                int newc = c + dy[x];
                if (newr >= 1 && newr <= n && newc >= 1 && newc <= m && !visited[newr][newc])
                {
                    visited[newr][newc] = true;
                    q.push(make_tuple(newr, newc, dist + 2));
                }
            }
        }
    }
    for (int i = 1; i <= k; i++)
    {
        fill(colorDist[i] + 1, colorDist[i] + 1 + k, 5 * MAXN);
        colorDist[i][i] = 0;
    }

    for (int r = 1; r <= n; r++)
    {
        for (int c = 1; c <= m; c++)
        {
            for (int a = 1; a <= k; a++)
            {
                for (int b = a + 1; b <= k; b++)
                {
                    colorDist[a][b] = colorDist[b][a] = min(colorDist[a][b], dp[a][r][c] + dp[b][r][c]);
                }
            }
        }

    }
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            for (int z = 1; z <= k; z++)
            {
                colorDist[j][z] = min(colorDist[j][z], colorDist[j][i] + colorDist[i][z]);
            }
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        int ans = 2 * (abs(r2 - r1) + abs(c2 - c1));
        for (int a = 1; a <= k; a++)
        {
            for (int b = 1; b <= k; b++)
            {
                ans = min(ans, dp[a][r1][c1] + colorDist[a][b] + dp[b][r2][c2]);
            }
        }
        cout << ans / 2 << "\n";
    }
    return 0;
}