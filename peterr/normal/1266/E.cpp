#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int a[MAXN + 1];
int extra[MAXN + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ans += a[i];
    }
    int q;
    cin >> q;
    map<pair<int, int>, int> m;
    while (q--)
    {
        int s, t, u;
        cin >> s >> t >> u;
        if (m.find({s, t}) != m.end())
        {
            int old = m[{s, t}];
            if (extra[old] <= a[old])
                ans++;
            extra[old]--;
            m.erase({s, t});
        }
        if (u != 0)
        {
            extra[u]++;
            if (extra[u] <= a[u])
                ans--;
            m[{s, t}] = u;
        }
        cout << ans << "\n";
    }
    return 0;
}