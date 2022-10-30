#include<iostream>
#include<memory.h>

using namespace std;

int g[30][30];

int main()
{
    ios_base::sync_with_stdio(0);
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; t++)
    {
        int n, p;
        cin >> n >> p;
        memset(g, 0, sizeof(g));
        int all = 2 * n + p;
        for (int i = 1; i <= n; i++)
        {
            int j = i + 1;
            if (j > n) j = 1;
            g[i][j] = g[j][i] = 1;
            all--;
            j = i + 2;
            if (j > n) j = j - n;
            g[i][j] = g[j][i] = 1;
            all--;
        }
        for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++)
        {
            if (all == 0) break;
            if (g[i][j] == 0) all--;
            g[i][j] = g[j][i] = 1;
        }
        for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) if (g[i][j] == 1) cout << i << " " << j << endl;
    }
    return 0;
}