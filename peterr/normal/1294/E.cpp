#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int best[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n);
    for (int i = 0; i < n; i++)
    {
        mat[i] = vector<int>(m);
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];
    }
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        vector<int> save(n);
        int mod = i + 1;
        if (mod == m)
            mod = 0;
        for (int j = 0; j < n; j++)
        {
            if (mat[j][i] <= n * m && mat[j][i] % m == mod)
            {
                int pos = mat[j][i] / m;
                if (i == m - 1)
                    pos--;
                save[(j - pos + n) % n]++;
            }
        }
        best[i] = 1E9;
        for (int j = 0; j < n; j++)
        {
            best[i] = min(best[i], n - save[j] + j);
        }
        ans += best[i];
    }
    cout << ans << endl;
    return 0;
}