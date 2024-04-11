#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int height[MAXN][MAXN];
int f[MAXN];
int l[MAXN];
int t[MAXN][MAXN];

int main()
{
    int n, m, h;
    cin >> n >> m >> h;
    for (int i = 0; i < m; i++)
        cin >> f[i];
    for (int i = 0; i < n; i++)
        cin >> l[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> t[i][j];
            if (t[i][j] == 1)
                height[i][j] = MAXN;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            height[j][i] = min(height[j][i], f[i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            height[i][j] = min(height[i][j], l[i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << height[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}