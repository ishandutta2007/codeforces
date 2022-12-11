#include<bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 107;

const int INF = 2e9 + 7;

char g[MAXN][MAXN];
int dist[MAXN][MAXN];

int32_t main()
{
    cin.tie(0); ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            dist[i][j] = INF;
            cin >> g[i][j];
            if (i == j)
            {
                dist[i][j] == 0;
            }
            if (g[i][j] == '1')
            {
                dist[i][j] = 1;
            }
        }
    }
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int m;
    cin >> m;
    vector<int> p(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> p[i];
        p[i]--;
    }
    vector<int> ans;
    ans.push_back(p[0]);
    int i = 0;
    while (i < m - 1)
    {
        for (int j = min(m - 1, i + n + 7); j > i; --j)
        {
            if (dist[p[i]][p[j]] == j - i && p[i] != p[j])
            {
                i = j;
                ans.push_back(p[i]);
                break;
            }
        }
    }
    cout << ans.size() << endl;
    for (auto el : ans)
    {
        cout << el + 1 << " ";
    }
    return 0;
}