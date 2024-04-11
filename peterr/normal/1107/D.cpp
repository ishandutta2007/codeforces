#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5200;
string mat[MAXN];
bool isOne[MAXN][MAXN];

int convert(char c)
{
    if (c <= '9' && c >= '0')
        return c - '0';
    return c - 'A' + 10;
}

int rep(int r, int c, int x)
{
    return isOne[r / x * x][c / x * x];
}

bool check(int x, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isOne[i][j] != rep(i, j, x))
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> mat[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j * 4 < n; j++)
        {
            int x = convert(mat[i][j]);
            for (int k = 0; k < 4; k++)
            {
                isOne[i][j * 4 + k] = x & (1 << (3 - k));
                //cout << isOne[i][j * 4 + k];
            }
        }
        //cout << endl;
    }

    int comp = n;
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        while (j < n)
        {
            int k = j;
            int countt = 0;
            while (k < n && isOne[i][k] == isOne[i][j])
            {
                countt++;
                k++;
            }
            j = k;
            comp = __gcd(comp, countt);
        }
        while (j < n)
        {
            int k = j;
            int countt = 0;
            while (k < n && isOne[k][i] == isOne[j][i])
            {
                countt++;
                k++;
            }
            j = k;
            comp = __gcd(comp, countt);
        }
    }
    int ans = 1;
    for (int i = comp; i >= 1; i--)
    {
        if (n % i == 0 && check(i, n))
        {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}