#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
pair<int, int> a[MAXN + 1];
int deg[MAXN + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].first;
            a[i].second = i;
            ans += a[i].first;
        }
        sort(a + 1, a + n + 1);
        reverse(a + 1, a + n + 1);
        fill(deg + 1, deg + n + 1, -1);
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            deg[u]++;
            deg[v]++;
        }
        cout << ans << " ";
        int ptr = 0;
        for (int i = 0; i < n - 2; i++)
        {
            while (deg[a[ptr].second] == 0)
                ptr++;
            ans += a[ptr].first;
            deg[a[ptr].second]--;
            cout << ans << " ";
        }
        cout << "\n";
    }
    return 0;
}