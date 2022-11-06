#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
const int LOGN = 25;
const int MAXM = 10;
const int MOD = 2520;
int val[MAXN + 1];
int lift[LOGN][MAXN * MOD + 1];
int nxt[MAXN + 1][MOD];
int m[MAXN + 1];
int e[MAXN + 1][MAXM];
vector<int> memo;
int comp[MAXN * MOD + 1];
int id[MAXN * MOD + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fill(comp + 1, comp + MAXN * MOD + 1, -1);
    int n;
    cin >> n;
    for (int i = 0; i < MOD; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            id[i * n + j] = j;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
        val[i] %= MOD;
        if (val[i] < 0)
            val[i] += MOD;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> m[i];
        for (int j = 0; j < m[i]; j++)
        {
            cin >> e[i][j];
        }
        for (int j = 0; j < m[i]; j++)
        {
            for (int k = 0; j + k < MOD; k += m[i])
                nxt[i][j + k] = e[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < MOD; j++)
        {
            int nxtNode = nxt[i][j % m[i]];
            int newSum = (j + val[nxtNode]) % MOD;
            lift[0][j * n + i] = newSum * n + nxtNode;
        }
    }
    for (int i = 1; i < LOGN; i++)
    {
        for (int node = 1; node <= n * MOD; node++)
        {
            lift[i][node] = lift[i - 1][lift[i - 1][node]];
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        y += val[x];
        y %= MOD;
        if (y < 0)
            y += MOD;
        x = lift[LOGN - 1][y * n + x];
        if (comp[x] == -1)
        {
            set<int> seen;
            int ans = 0;
            while (comp[x] == -1)
            {
                comp[x] = (int) memo.size();
                if (!seen.count(id[x]))
                {
                    ans++;
                    seen.insert(id[x]);
                }
                x = lift[0][x];
            }
            memo.push_back(ans);
        }
        cout << memo[comp[x]] << "\n";
    }
    return 0;
}