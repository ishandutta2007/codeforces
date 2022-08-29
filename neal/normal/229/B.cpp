#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 100005, INF = 1011111111;

int N, M;
vector<pair<int, int> > adj[MAX];
set<int> bad[MAX];
int dist[MAX];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int > > > hp;

void hp_push(int num, int ndist)
{
    if (ndist < dist[num])
    {
        dist[num] = ndist;
        hp.push(make_pair(dist[num], num));
    }
}

void dijkstra()
{
    memset(dist, 63, sizeof(dist));
    hp_push(0, 0);

    while (!hp.empty())
    {
        pair<int, int> top = hp.top(); hp.pop();
        int num = top.second, d = top.first;

        if (d > dist[num])
            continue;

        while (bad[num].count(d) > 0)
            d++;

        for (int i = 0; i < (int) adj[num].size(); i++)
            hp_push(adj[num][i].first, d + adj[num][i].second);
    }
}

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c); a--; b--;
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }

    for (int i = 0; i < N; i++)
    {
        int k;
        scanf("%d", &k);

        while (k-- > 0)
        {
            int t;
            scanf("%d", &t);
            bad[i].insert(t);
        }
    }

    dijkstra();
    printf("%d\n", dist[N - 1] < INF ? dist[N - 1] : -1);
    return 0;
}