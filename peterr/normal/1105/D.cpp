#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
const int MAXP = 9;
int board[MAXN * MAXN];
int speed[MAXP + 1];
queue<pair<int, int>> q[MAXP + 1];
int dx[4];
int ans[MAXP + 1];

int getIndex(int r, int c, int m)
{
    return r * m + c;
}

bool isDone(int p)
{
    for (int i = 1; i <= p; i++)
    {
        if (!q[i].empty())
            return false;
    }
    return true;
}

void doTurn(int player, int n, int m)
{
    if (q[player].empty())
        return;
    int start = q[player].front().second;
    int stop = start + speed[player];
    while (!q[player].empty() && q[player].front().second < stop)
    {
        int curIndex = q[player].front().first;
        for (int i = 0; i < 4; i++)
        {
            int newIndex = curIndex + dx[i];
            if (dx[i] == 1 && newIndex % m == 0 || dx[i] == -1 && newIndex % m == m - 1)
                continue;
            if (newIndex >= 0 && newIndex < n * m)
            {
                if (board[newIndex] == 0)
                {
                    board[newIndex] = player;
                    q[player].push({newIndex, q[player].front().second + 1});
                }
            }
        }
        q[player].pop();
        ans[player]++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, p;
    cin >> n >> m >> p;
    dx[0] = 1, dx[1] = -1, dx[2] = m, dx[3] = -m;
    for (int i = 1; i <= p; i++)
        cin >> speed[i];
    for (int i = 0; i < n * m; i++)
    {
            char c;
            cin >> c;
            if (c == '.')
                board[i] = 0;
            else if (c == '#')
                board[i] = -1;
            else
                board[i] = c - '0';
            if (board[i] > 0)
            {
                q[board[i]].push({i, 0});
            }
    }
    while (!isDone(p))
    {
        for (int i = 1; i <= p; i++)
        {
            doTurn(i, n, m);
        }
    }
    /*
    cout << "test" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << board[i * m + j];
        }
        cout << endl;
    }
    */
    for (int i = 1; i <= p; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}