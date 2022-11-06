#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E3;
pair<int, int> board[MAXN + 1][MAXN + 1];
char ans[MAXN + 1][MAXN + 1];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char mapp[4] = {'D', 'U', 'R', 'L'};
char mapp2[4] = {'U', 'D', 'L', 'R'};

bool isValid(int r, int c, int n)
{
    return r >= 1 && r <= n && c >= 1 && c <= n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> board[i][j].first >> board[i][j].second;
        }
    }
    for (int i = 1; i <= n; i++)
        fill(ans[i] + 1, ans[i] + n + 1, (char) 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (board[i][j] == make_pair(i, j))
            {
                ans[i][j] = 'X';
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                while (!q.empty())
                {
                    pair<int, int> pr = q.front();
                    q.pop();
                    int r = pr.first;
                    int c = pr.second;
                    for (int k = 0; k < 4; k++)
                    {
                        int newr = r + dx[k];
                        int newc = c + dy[k];
                        if (isValid(newr, newc, n) && ans[newr][newc] == (char) 0 && board[newr][newc] == make_pair(i, j))
                        {
                            ans[newr][newc] = mapp2[k];
                            q.push(make_pair(newr, newc));
                        }
                    }
                }
            }
            else if (board[i][j] == make_pair(-1, -1))
            {
                for (int k = 0; k < 4; k++)
                {
                    int newi = i + dx[k];
                    int newj = j + dy[k];
                    if (isValid(newi, newj, n) && board[newi][newj] == make_pair(-1, -1))
                    {
                        ans[i][j] = mapp[k];
                        break;
                    }
                }
            }
        }
    }
    bool valid = true;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (ans[i][j] == (char) 0)
                valid = false;
    if (valid)
    {
        cout << "VALID" << "\n";
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << ans[i][j];
            }
            cout << "\n";
        }
    }
    else
        cout << "INVALID" << "\n";
    return 0;
}