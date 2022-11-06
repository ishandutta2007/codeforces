#include <bits/stdc++.h>

using namespace std;

const int MAX = 30;
const int MAXN = 5000;
int a[MAXN];

int main()
{
    int n, m;
    cin >> n >> m;
    int cur = 1;
    int ind = 0;
    while (ind < n && m - (cur - 1) / 2 >= 0)
    {
        m -= (cur - 1) / 2;
        a[ind++] = cur++;
    }
    int big = 0;
    if (ind < n)
    {
        int extra = (cur - 1) / 2 - m;
        cur += 2 * extra;
        a[ind++] = cur;
        m = 0;
        big = cur * 3;
    }
    cur = big + 1;
    while (ind < n)
    {
        a[ind++] = cur;
        cur += big;
    }
    if (m == 0)
    {
        for (int i = 0; i < n; i++)
            cout << a[i] << " \n"[i == n - 1];
    }
    else
        cout << -1 << endl;
    return 0;
}