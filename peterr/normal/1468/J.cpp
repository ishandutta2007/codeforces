#include <bits/stdc++.h>

using namespace std;

const long long INF = 1E16;
const int MAXN = 2E5;
int parent[MAXN + 1];
int sz[MAXN + 1];
tuple<int, int, int> edges[MAXN + 1];

int getRoot(int x)
{
    if (parent[x] != x)
        parent[x] = getRoot(parent[x]);
    return parent[x];
}

bool mge(int x, int y)
{
    x = getRoot(x);
    y = getRoot(y);
    if (x == y)
        return false;
    if (sz[x] > sz[y])
        swap(x, y);
    parent[x] = y;
    sz[y] += sz[x];
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        fill(sz + 1, sz + n + 1, 1);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
        for (int i = 0; i < m; i++)
        {
            int x, y, s;
            cin >> x >> y >> s;
            edges[i] = {s, x, y};
        }
        sort(edges, edges + m);
        int under = -1;
        for (int i = 0; i < m; i++)
        {
            if (get<0>(edges[i]) >= k)
                break;
            under = get<0>(edges[i]);
            mge(get<1>(edges[i]), get<2>(edges[i]));
        }
        long long ans = INF;
        if (sz[getRoot(1)] == n)
        {
            if (under != -1)
                ans = min(ans, (long long) k - under);
            for (int i = 0; i < m; i++)
            {
                if (get<0>(edges[i]) < k)
                    continue;
                ans = min(ans, (long long) get<0>(edges[i]) - k);
                break;
            }
        }
        long long sum = 0;
        for (int i = 0; i < m; i++)
        {
            if (get<0>(edges[i]) < k)
                continue;
            if (mge(get<1>(edges[i]), get<2>(edges[i])))
            {
                sum += get<0>(edges[i]) - k;
                if (sz[getRoot(1)] == n)
                    ans = min(ans, sum);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}