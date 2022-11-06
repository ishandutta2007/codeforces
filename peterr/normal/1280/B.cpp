#include <bits/stdc++.h>

using namespace std;

const int MAXN = 60;
string board[MAXN];
int rowcnt[MAXN];
int colcnt[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        for (int i = 0; i < r; i++)
            cin >> board[i];
        int a, p;
        a = p = 0;
        fill(rowcnt, rowcnt + r, 0);
        fill(colcnt, colcnt + c, 0);
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (board[i][j] == 'A')
                    a++;
                else
                    p++;
                if (board[i][j] == 'A')
                {
                    rowcnt[i]++;
                    colcnt[j]++;
                }
            }
        }
        if (p == 0)
        {
            cout << "0\n";
            continue;
        }
        if (a == 0)
        {
            cout << "MORTAL\n";
            continue;
        }
        if (rowcnt[0] == c || rowcnt[r - 1] == c || colcnt[0] == r || colcnt[c - 1] == r)
        {
            cout << "1\n";
            continue;
        }
        if (rowcnt[0] == 0 && rowcnt[r - 1] == 0 && colcnt[0] == 0 && colcnt[c - 1] == 0)
        {
            cout << "4\n";
            continue;
        }
        if (board[0][0] == 'A' || board[r - 1][0] == 'A' || board[0][c - 1] == 'A' || board[r - 1][c - 1] == 'A')
        {
            cout << "2\n";
            continue;
        }
        bool flag = false;
        for (int i = 0; i < r; i++)
            if (rowcnt[i] == c)
                flag = true;
        for (int i = 0; i < c; i++)
            if (colcnt[i] == r)
                flag = true;
        if (flag)
        {
            cout << "2\n";
            continue;
        }
        cout << "3\n";
    }
    return 0;
}