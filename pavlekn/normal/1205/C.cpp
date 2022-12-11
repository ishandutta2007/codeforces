#include<bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e9;

const int MAXN = 103;

int a[MAXN][MAXN];

void check(int x1, int y1, int x2, int y2)
{
    cout << "? " << x2 + 1 << " " << y2 + 1 << " " << x1 + 1 << " " << y1 + 1 << endl;
    bool fl;
    cin >> fl;
    if (fl)
    {
        a[x1][y1] = a[x2][y2];
    }
    else
    {
        a[x1][y1] = a[x2][y2] ^ 1ll;
    }
}

void query(vector<pair<int, int>> q, int ind)
{
    cout << "? " << q[3].first + 1 << " " << q[3].second + 1 << " " << q[0].first + 1 << " " << q[0].second + 1 << endl;
    bool fl;
    cin >> fl;
    if (fl != (a[q[ind].first][q[ind].second] == a[q[3 - ind].first][q[3 - ind].second]))
    {
        int k = q[ind].first;
        int l = q[ind].second;
        for (int i = 0; i < MAXN; ++i)
        {
            for (int j = 0; j < MAXN; ++j)
            {
                if (i % 2 == k % 2 && j % 2 == l % 2)
                {
                    a[i][j] ^= 1;
                }
            }
        }
    }
}

void f(int i, int j)
{
    if (a[i + 1][j + 1] == 1)
    {
        if (a[i + 1][j] == a[i + 1][j + 2])
        {
            query({{i + 1, j + 2}, {i + 1, j + 1}, {i + 1, j}, {i, j}}, 0);
        }
        else
        {
            query({{i + 2, j + 2}, {i + 1, j + 2}, {i + 1, j + 1}, {i + 1, j}}, 1);
        }
        if (a[i][j + 1] == a[i + 2][j + 1])
        {
            query({{i + 2, j + 1}, {i + 1, j + 1}, {i, j + 1}, {i, j}}, 0);
        }
        else
        {
            query({{i + 2, j + 2}, {i + 2, j + 1}, {i + 1, j + 1}, {i, j + 1}}, 1);
        }
    }
    else
    {
        if (a[i + 1][j] != a[i + 1][j + 2])
        {
            query({{i + 1, j + 2}, {i + 1, j + 1}, {i + 1, j}, {i, j}}, 0);
        }
        else
        {
            query({{i + 2, j + 2}, {i + 1, j + 2}, {i + 1, j + 1}, {i + 1, j}}, 1);
        }
        if (a[i][j + 1] != a[i + 2][j + 1])
        {
            query({{i + 2, j + 1}, {i + 1, j + 1}, {i, j + 1}, {i, j}}, 0);
        }
        else
        {
            query({{i + 2, j + 2}, {i + 2, j + 1}, {i + 1, j + 1}, {i, j + 1}}, 1);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    a[0][0] = 1;
    a[n - 1][n - 1] = 0;
    a[0][1] = 0;
    a[1][0] = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i + j > 1 && i + j < 2 * n - 2)
            {
                if (i > 1)
                {
                    check(i, j, i - 2, j);
                }
                else if (j > 1)
                {
                    check(i, j, i, j - 2);
                }
                else
                {
                    check(i, j, i - 1, j - 1);
                }
            }
        }
    }
    for (int i = 0; i < n - 2; i += 2)
    {
        for (int j = 0; j < n - 2; j += 2)
        {
            if (a[i][j] == 1 && a[i + 2][j + 2] == 0)
            {
                f(i, j);
                cout << "!" << endl;
                for (int i = 0; i < n; ++i)
                {
                    for (int j = 0; j < n; ++j)
                    {
                        cout << a[i][j];
                    }
                    cout << endl;
                }
                return 0;
            }
        }
    }
    return 0;
}