#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
int grid[MAXN][MAXN];

/*
void solve(int r1, int c1, int r2, int c2, bool horz, int k)
{
    if (k < 0)
        return;
    int midCol = (c1 + c2) / 2;
    int midRow = (r1 + r2) / 2;
    if (horz)
    {
        for (int i = r1; i <= r2; i++)
        {
            for (int j = c1; j <= midCol; j++)
            {
                grid[i][j] ^= (1 << k);
            }
        }
        solve(r1, c1, r2, midCol, false, k - 1);
        solve(r1, midCol + 1, r2, c2, false, k - 1);
    }
    else
    {
        for (int i = r1; i <= midRow; i++)
        {
            for (int j = c1; j <= c2; j++)
            {
                grid[i][j] ^= (1 << k);
            }
        }
        solve(r1, c1, midRow, c2, true, k - 1);
        solve(midRow + 1, c1, r2, c2, true, k - 1);
    }
}
*/

void add(int r1, int c1, int r2, int c2, int x)
{
    for (int i = r1; i <= r2; i++)
    {
        for (int j = c1; j <= c2; j++)
        {
            grid[i][j] = x;
        }
    }
}

void counting(int r1, int c1, int r2, int c2)
{
    int num = 0;
    for (int i = r1; i <= r2; i++)
    {
        for (int j = c1; j <= c2; j++)
        {
            grid[i][j] |= num << 4;
            num++;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int k = n / 4;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            add(i * k, j * k, i * k + k - 1, j * k + k - 1, i * 4 + j);
            counting(i * k, j * k, i * k + k - 1, j * k + k - 1);
        }
    }
    stringstream ss;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ss << grid[i][j] << " ";
        }
        ss << endl;
    }
    cout << ss.str();
    return 0;
}