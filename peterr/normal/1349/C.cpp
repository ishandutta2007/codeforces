#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
string board[MAXN];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool visited[MAXN][MAXN];
queue<pair<int, int>> q;
pair<int, int> comp[MAXN][MAXN];
int dist[MAXN][MAXN];

bool isValid(int r, int c, int n, int m)
{
    return r >= 0 && r < n && c >= 0 && c < m;
}

void dfs(int r, int c, int n, int m)
{
    dist[r][c] = 0;
    q.push(make_pair(r, c));
    visited[r][c] = true;
    comp[r][c] = make_pair(r, c);
    for (int i = 0; i < 4; i++)
    {
        int newr = r + dx[i];
        int newc = c + dy[i];
        if (isValid(newr, newc, n, m) && !visited[newr][newc] && board[r][c] == board[newr][newc])
        {
            dfs(newr, newc, n, m);
        }
    }
}

bool solve(int i, int j, long long p)
{
    pair<int, int> pr = comp[i][j];
    if (pr.first == i && pr.second == j)
        return (board[i][j] == '1') ^ (p & 1);
    if (p < dist[i][j])
        return board[i][j] == '1';
    return solve(pr.first, pr.second, p);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, t;
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++)
        cin >> board[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j])
                continue;
            for (int k = 0; k < 4; k++)
            {
                int newr = i + dx[k];
                int newc = j + dy[k];
                if (isValid(newr, newc, n, m) && board[i][j] == board[newr][newc])
                {
                    dfs(i, j, n, m);
                    break;
                }
            }
        }
    }
    bool fixed = q.empty();
    while (!q.empty())
    {
        pair<int, int> pr = q.front();
        q.pop();
        int r = pr.first;
        int c = pr.second;
        for (int i = 0; i < 4; i++)
        {
            int newr = r + dx[i];
            int newc = c + dy[i];
            if (isValid(newr, newc, n, m) && !visited[newr][newc])
            {
                visited[newr][newc] = true;
                dist[newr][newc] = dist[r][c] + 1;
                comp[newr][newc] = comp[r][c];
                q.push(make_pair(newr, newc));
            }
        }
    }
    while (t--)
    {
        int i, j;
        long long p;
        cin >> i >> j >> p;
        i--;
        j--;
        if (fixed)
            cout << board[i][j] << "\n";
        else
        {
            cout << solve(i, j, p) << "\n";
        }
    }
    return 0;
}