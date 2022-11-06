#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i + 1 < m - i; i++)
    {
        int c1 = i + 1;
        int c2 = m - i;
        for (int j = 0; j + 1 <= n; j++)
        {
            int r1 = j + 1;
            int r2 = n - j;
            printf("%d %d\n", r1, c1);
            printf("%d %d\n", r2, c2);
        }
    }
    if (m % 2 == 1)
    {
        int col = m / 2 + 1;
        for (int i = 0; i + 1 < n - i; i++)
        {
            int r1 = i + 1;
            int r2 = n - i;
            printf("%d %d\n", r1, col);
            printf("%d %d\n", r2, col);
        }
        if (n % 2 == 1)
            printf("%d %d\n", (n / 2 + 1), col);
    }

    return 0;
}