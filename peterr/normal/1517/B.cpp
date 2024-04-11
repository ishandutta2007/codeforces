#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
const int INF = 1E9 + 5;
int ans[MAXN][MAXN];
pair<int, int> dist[MAXN];
int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; i++)
            dist[i] = {INF, i};
        for (int i = 0; i < n; i++)
        {
            fill(ans[i], ans[i] + m, 0);
            for (int j = 0; j < m; j++)
            {
                cin >> a[j];
            }
            sort(dist, dist + m);
            reverse(dist, dist + m);
            for (int j = 0; j < m; j++)
            {
                auto it = min_element(a, a + m);
                dist[j].first = min(dist[j].first, *it);
                ans[i][dist[j].second] = *it;
                *it = INF;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << ans[i][j] << " \n"[j == m - 1];
            }
        }
    }
    return 0;
}