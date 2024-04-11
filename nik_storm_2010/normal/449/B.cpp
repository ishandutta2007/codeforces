#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair <ll, int> pli;
const int N = 1e5 + 100;
const int BIG_INT = 2e9;
const ll BIG_LL = 2e18;

vector <int> edges[N], costs[N];
int min_edge[N], cnt[N], n, m, k;
ll path[N];

void deikstra()
{
    for (int i = 1; i <= n; i++)  path[i] = BIG_LL;
    path[1] = 0;
    priority_queue <pli> base;
    for (int i = 1; i <= n; i++) base.push(make_pair(-path[i], i));
    while (base.empty() == false)
    {
        ll leng = -base.top().first;
        int nom = base.top().second;
        base.pop();
        if (leng > path[nom]) continue;
        for (int j = 0; j < edges[nom].size(); j++)
        {
            int to = edges[nom][j];
            if (leng + costs[nom][j] < path[to])
            {
                path[to] = leng + costs[nom][j];
                cnt[to] = 0;
                base.push(make_pair(-path[to], to));
            }
            if (leng + costs[nom][j] == path[to]) cnt[to]++;
        }
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) min_edge[i] = BIG_INT;
    for (int i = 1; i <= m; i++)
    {
        int u, v, x;
        scanf("%d %d %d", &u, &v, &x);
        edges[u].push_back(v);
        costs[u].push_back(x);
        edges[v].push_back(u);
        costs[v].push_back(x);
    }
    for (int i = 1; i <= k; i++)
    {
        int s, y;
        scanf("%d %d", &s, &y);
        min_edge[s] = min(min_edge[s], y);
    }
    int ans = k;
    for (int i = 1; i <= n; i++)
    {
        if (min_edge[i] == BIG_INT) continue;
        ans--;
        edges[1].push_back(i);
        costs[1].push_back(min_edge[i]);
    }
    deikstra();
    for (int i = 1; i <= n; i++)
    {
        if (min_edge[i] == BIG_INT) continue;
        if (min_edge[i] == path[i] && cnt[i] == 1); else ans++;
    }
    printf("%d\n", ans);
    return 0;
}