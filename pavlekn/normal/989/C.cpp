#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int n = 50;
    char ans[50][50];
    for (int i = 0; i < n; ++i)
    {
        if (a > 1 && i % 2 == 0)
            {ans[0][i] = 'a'; --a;}
        else
        {
            ans[0][i] = 'b';
        }
    }
    for (int i = 0; i < n; ++i)
    {
        ans[1][i] = 'b';
    }
    for (int i = 0; i < n; ++i)
    {
        if (a > 1 && i % 2 == 0)
            {ans[2][i] = 'a'; --a;}
        else
        {
            ans[2][i] = 'b';
        }
    }
    for (int i = 0; i < n; ++i)
    {
        ans[3][i] = 'b';
    }
    for (int i = 0; i < n; ++i)
    {
        if (a > 1 && i % 2 == 0)
            {ans[4][i] = 'a'; --a;}
        else
        {
            ans[4][i] = 'b';
        }
    }
    for (int i = 0; i < n; ++i)
    {
        ans[5][i] = 'b';
    }
    for (int i = 0; i < n; ++i)
    {
        if (a > 1 && i % 2 == 0)
            {ans[6][i] = 'a'; --a;}
        else
        {
            ans[6][i] = 'b';
        }
    }
    for (int i = 0; i < n; ++i)
    {
        ans[7][i] = 'b';
    }
    --b;
    for (int i = 0; i < n; ++i)
    {
        if (b > 0 && i % 2 == 0)
            {ans[9][i] = 'b'; --b;}
        else
        {
            ans[9][i] = 'a';
        }
    }
    for (int i = 0; i < n; ++i)
    {
        ans[10][i] = 'a';
    }
    for (int i = 0; i < n; ++i)
    {
        if (b > 0 && i % 2 == 0)
            {ans[11][i] = 'b'; --b;}
        else
        {
            ans[11][i] = 'a';
        }
    }
    for (int i = 0; i < n; ++i)
    {
        ans[8][i] = 'a';
    }
    for (int i = 0; i < n; ++i)
    {
        if (b > 0 && i % 2 == 0)
            {ans[13][i] = 'b'; --b;}
        else
        {
            ans[13][i] = 'a';
        }
    }
    for (int i = 0; i < n; ++i)
    {
        ans[14][i] = 'a';
    }
    for (int i = 0; i < n; ++i)
    {
        if (b > 0 && i % 2 == 0)
            {ans[15][i] = 'b'; --b;}
        else
        {
            ans[15][i] = 'a';
        }
    }
    for (int i = 0; i < n; ++i)
    {
        ans[12][i] = 'a';
    }


    for (int i = 0; i < n; ++i)
    {
        if (c > 1 && i % 2 == 0)
            {ans[16][i] = 'c'; --c;}
        else
        {
            ans[16][i] = 'd';
        }
    }
    for (int i = 0; i < n; ++i)
    {
        ans[17][i] = 'd';
    }
    for (int i = 0; i < n; ++i)
    {
        if (c > 1 && i % 2 == 0)
            {ans[18][i] = 'c'; --c;}
        else
        {
            ans[18][i] = 'd';
        }
    }
    for (int i = 0; i < n; ++i)
    {
        ans[19][i] = 'd';
    }
    for (int i = 0; i < n; ++i)
    {
        if (c > 1 && i % 2 == 0)
            {ans[20][i] = 'c'; --c;}
        else
        {
            ans[20][i] = 'd';
        }
    }
    for (int i = 0; i < n; ++i)
    {
        ans[21][i] = 'd';
    }
    for (int i = 0; i < n; ++i)
    {
        if (c > 1 && i % 2 == 0)
            {ans[22][i] = 'c'; --c;}
        else
        {
            ans[22][i] = 'd';
        }
    }
    for (int i = 0; i < n; ++i)
    {
        ans[23][i] = 'd';
    }
    --d;
    for (int i = 0; i < n; ++i)
    {
        if (d > 0 && i % 2 == 0)
            {ans[25][i] = 'd'; --d;}
        else
        {
            ans[25][i] = 'c';
        }
    }
    for (int i = 0; i < n; ++i)
    {
        ans[26][i] = 'c';
    }
    for (int i = 0; i < n; ++i)
    {
        if (d > 0 && i % 2 == 0)
            {ans[27][i] = 'd'; --d;}
        else
        {
            ans[27][i] = 'c';
        }
    }
    for (int i = 0; i < n; ++i)
    {
        ans[24][i] = 'c';
    }
    for (int i = 0; i < n; ++i)
    {
        if (d > 0 && i % 2 == 0)
            {ans[29][i] = 'd'; --d;}
        else
        {
            ans[29][i] = 'c';
        }
    }
    for (int i = 0; i < n; ++i)
    {
        ans[30][i] = 'c';
    }
    for (int i = 0; i < n; ++i)
    {
        if (d > 0 && i % 2 == 0)
            {ans[31][i] = 'd'; --d;}
        else
        {
            ans[31][i] = 'c';
        }
    }
    for (int i = 0; i < n; ++i)
    {
        ans[28][i] = 'c';
    }
    cout << 32 << " " << 50 << endl;
    for (int i = 0; i < 32; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << ans[i][j];
        }
        cout << endl;
    }
}