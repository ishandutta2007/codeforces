#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
bool matrix[MAXN + 1][MAXN + 1];
int matSum[MAXN + 1][MAXN + 1];

bool isInvert(int x, int y)
{
    if (x == 0 && y == 0)
        return false;
    int sze = 1 << (32 - __builtin_clz(max(x, y)));
    if (x >= sze / 2 && y >= sze / 2)
        return isInvert(x - sze / 2, y - sze / 2);
    else if (x >= sze / 2)
        return !isInvert(x - sze / 2, y);
    else
        return !isInvert(x, y - sze / 2);
}

long long query(int x, int y, int n, int m)
{
    if (x < 1 || y < 1)
        return 0;
    int height = y / n;
    int width = x / m;
    long long ans = (long long) height * width / 2 * n * m;
    if (height % 2 == 1 && width % 2 == 1)
    {
        if (isInvert(width - 1, height - 1))
            ans += (long long) n * m - matSum[n][m];
        else
            ans += matSum[n][m];
    }
    int extraRow = y % n;
    int extraCol = x % m;
    bool cornerInv = isInvert(width, height);
    ans += (long long) width / 2 * (extraRow * m);
    ans += (long long) height / 2 * (extraCol * n);
    if (height % 2 == 1)
    {
        if (isInvert(width, height - 1))
        {
            ans += (long long) extraCol * n - matSum[n][extraCol];
        }
        else
        {
            ans += (long long) matSum[n][extraCol];
        }
    }
    if (width % 2 == 1)
    {
        if (isInvert(width - 1, height))
        {
            ans += (long long) extraRow * m - matSum[extraRow][m];
        }
        else
        {
            ans += (long long) matSum[extraRow][m];
        }
    }
    if (cornerInv)
        ans += extraRow * extraCol - matSum[extraRow][extraCol];
    else
        ans += matSum[extraRow][extraCol];

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char c;
            cin >> c;
            if (c == '1')
            {
                matrix[i][j] = true;
            }
        }
    }
    matSum[1][1] = matrix[1][1];
    for (int i = 2; i <= m; i++)
    {
        matSum[1][i] = matSum[1][i - 1] + matrix[1][i];
    }
    for (int i = 2; i <= n; i++)
    {
        matSum[i][1] = matSum[i - 1][1] + matrix[i][1];
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= m; j++)
        {
            matSum[i][j] = matSum[i - 1][j] + matSum[i][j - 1] - matSum[i - 1][j - 1] + matrix[i][j];
        }
    }
    stringstream ss;
    for (int i = 0; i < q; i++)
    {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        ss << query(x2, y2, n, m) - query(x2, y1 - 1, n, m) - query(x1 - 1, y2, n, m) + query(x1 - 1, y1 - 1, n, m) << endl;
    }
    cout << ss.str();
    return 0;
}