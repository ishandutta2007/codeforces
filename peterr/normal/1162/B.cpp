#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50;
int m1[MAXN][MAXN];
int m2[MAXN][MAXN];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> m1[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> m2[i][j];
    bool good = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j < m - 1)
            {
                if (min(m1[i][j+1], m2[i][j+1]) <= min(m1[i][j], m2[i][j]))
                    good = false;
                if (max(m1[i][j+1], m2[i][j+1]) <= max(m1[i][j], m2[i][j]))
                    good = false;
            }
            if (i < n - 1)
            {
                if (min(m1[i+1][j], m2[i+1][j]) <= min(m1[i][j], m2[i][j]))
                    good = false;
                if (max(m1[i+1][j], m2[i+1][j]) <= max(m1[i][j], m2[i][j]))
                    good = false;
            }
        }
    }
    if (good)
        cout << "Possible";
    else
        cout << "Impossible";
    return 0;
}