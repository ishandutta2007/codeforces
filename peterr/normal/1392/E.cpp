#include <bits/stdc++.h>

using namespace std;

const int MAXN = 25;
long long board[MAXN + 1][MAXN + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 2; i <= 2 * n; i++)
    {
        for (int row = 1; row <= n; row++)
        {
            int col = i - row;
            if (col < 1 || col > n)
                continue;
            if (row & 1)
            {
                board[row][col] = 1LL << (i - 2);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << board[i][j];
            if (j < n)
                cout << " ";
        }
        cout << "\n";
    }
    cout.flush();
    int q;
    cin >> q;
    while (q--)
    {
        long long k;
        cin >> k;
        vector<pair<int, int>> ans;
        ans.push_back(make_pair(1, 1));
        int r = 1;
        int c = 1;
        for (int i = 1; i <= 2 * n - 2; i++)
        {
            if (c == n)
            {
                r++;
            }
            else if (r == n)
            {
                c++;
            }
            else
            {
                bool has = k & (1LL << i);
                if (has ^ (board[r][c + 1] > 0))
                {
                    r++;
                }
                else
                {
                    c++;
                }
            }
            ans.push_back(make_pair(r, c));
        }
        cout << "\n";
        for (pair<int, int> pr : ans)
        {
            cout << pr.first << " " << pr.second << "\n";
        }
        cout.flush();
    }
    return 0;
}