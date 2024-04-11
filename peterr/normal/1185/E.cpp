#include <bits/stdc++.h>

using namespace std;

const int MAXS = 26;
const int MAXN = 2000;
int board[MAXN][MAXN];
int sim[MAXN][MAXN];
int maxRow[MAXS + 1];
int minRow[MAXS + 1];
int maxCol[MAXS + 1];
int minCol[MAXS + 1];
int snakes;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        snakes = 0;
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                char c;
                cin >> c;
                if (c == '.')
                    board[i][j] = 0;
                else
                    board[i][j] = c - 'a' + 1;
                snakes = max(snakes, board[i][j]);
            }
        }
        fill(maxRow, maxRow + snakes + 1, -1);
        fill(minRow, minRow + snakes + 1, MAXN + 5);
        fill(maxCol, maxCol + snakes + 1, -1);
        fill(minCol, minCol + snakes + 1, MAXN + 5);
        bool possible = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j])
                {
                    int type = board[i][j];
                    if (maxRow[type] == -1)
                    {
                        maxRow[type] = i;
                        minRow[type] = i;
                        maxCol[type] = j;
                        minCol[type] = j;
                    }
                    else if (i != maxRow[type] && j != maxCol[type])
                    {
                        possible = false;
                    }
                    else if (maxCol[type] != minCol[type])
                    {
                        if (i != maxRow[type])
                            possible = false;
                        else
                        {
                            maxCol[type] = max(maxCol[type], j);
                            minCol[type] = min(minCol[type], j);
                        }
                    }
                    else if (maxRow[type] != minRow[type])
                    {
                        if (j != maxCol[type])
                            possible = false;
                        else
                        {
                            maxRow[type] = max(maxRow[type], i);
                            minRow[type] = min(minRow[type], i);
                        }
                    }
                    else
                    {
                        maxCol[type] = max(maxCol[type], j);
                        minCol[type] = min(minCol[type], j);
                        maxRow[type] = max(maxRow[type], i);
                        minRow[type] = min(minRow[type], i);
                    }
                }
            }
        }
        if (!possible)
        {
            cout << "NO" << endl;
            continue;
        }
        for (int i = 0; i < n; i++)
            fill(sim[i], sim[i] + m, 0);
        int filledRow = -1;
        int filledCol = -1;
        for (int i = 1; i <= snakes; i++)
        {
            if (maxRow[i] != -1)
            {
                if (maxRow[i] != minRow[i])
                {
                    int c = maxCol[i];
                    for (int j = minRow[i]; j <= maxRow[i]; j++)
                    {
                        sim[j][c] = i;
                        filledRow = j;
                        filledCol = c;
                    }
                }
                else
                {
                    int r = maxRow[i];
                    for (int j = minCol[i]; j <= maxCol[i]; j++)
                    {
                        sim[r][j] = i;
                        filledRow = r;
                        filledCol = j;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] != sim[i][j])
                    possible = false;
            }
        }
        if (!possible)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            cout << snakes << endl;
            for (int i = 1; i <= snakes; i++)
            {
                if (maxRow[i] == -1)
                {
                    cout << filledRow+1 << " " << filledCol+1 << " ";
                    cout << filledRow+1 << " " << filledCol+1 << endl;
                }
                else
                {
                    cout << minRow[i] + 1 << " " << minCol[i] + 1 << " ";
                    cout << maxRow[i] + 1 << " " << maxCol[i] + 1 << endl;
                }
            }
        }
    }
    return 0;
}