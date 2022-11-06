#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5E5;
const int LOGN = 19;
pair<int, int> table[LOGN + 1][MAXN];
int best[MAXN];

pair<int, int> query(int a, int b)
{
    int len = b - a + 1;
    int two = 1 << (31 - __builtin_clz(len));
    return min(table[__builtin_ctz(two)][a], table[__builtin_ctz(two)][b - two + 1]);
}

long long solve(int a, int b)
{
    if (a > b)
        return 0;
    pair<int, int> pr = query(a, b);
    long long x = (long long) pr.first * (pr.second - a + 1) + solve(pr.second + 1, b);
    long long y = (long long) pr.first * (b - pr.second + 1) + solve(a, pr.second - 1);
    if (x > y)
    {
        for (int i = a; i <= pr.second; i++)
            best[i] = pr.first;
    }
    else
    {
        for (int i = pr.second; i <= b; i++)
            best[i] = pr.first;
    }
    return max(x, y);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> table[0][i].first;
        table[0][i].second = i;
    }
    for (int i = 1; i <= LOGN; i++)
    {
        for (int j = 0; j < n; j++)
        {
            table[i][j] = table[i - 1][j];
            if (j + (1 << (i - 1)) < n)
                table[i][j] = min(table[i][j], table[i - 1][j + (1 << (i - 1))]);
        }
    }
    solve(0, n - 1);
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            cout << " ";
        cout << best[i];
    }
    cout << endl;
    return 0;
}