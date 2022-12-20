#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int N = 2e5 + 5;
const long long oo = 1e18;

struct node
{
    int u, i, j;
    node(){}
    node(int _u, int _i, int _j)
    {
        u = _u;
        i = _i;
        j = _j;
    }
};

vector <pair <int, int>> adj[N];

node Node[4 * N];

long long dp[4 * N];

int id[N][2][2];
int n,m,numNode;

bool minimize(long long &a, long long b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

void dijkstra()
{
    int s = id[1][0][0];
    set <pair <long long, int>> heap;
    heap.insert(mp(0LL, s));
    dp[s] = 0;

    while (heap.size())
    {
        pair <long long, int> res = *heap.begin();
        heap.erase(heap.begin());

        if (res.fi != dp[res.se])
            continue;

        int cur = res.se;
        int u = Node[cur].u;
        int i = Node[cur].i;
        int j = Node[cur].j;

        for (pair <int, int> to : adj[u])
        {
            int v = to.fi;
            int w = to.se;

            for (int x = 0; x <= (i ^ 1); x++)
            for (int y = 0; y <= (j ^ 1); y++)
            {
                int cost = w;
                int newi = i | x;
                int newj = j | y;
                if (x)
                    cost -= w;
                if (y)
                    cost += w;
                int nxt = id[v][newi][newj];
                if (minimize(dp[nxt], dp[cur] + cost))
                    heap.insert(mp(dp[nxt], nxt));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("file.inp","r",stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back(mp(v, w));
        adj[v].push_back(mp(u, w));
    }
    for (int i = 1; i <= n; i++)
    for (int j = 0; j <= 1; j++)
    for (int k = 0; k <= 1; k++)
    {
        id[i][j][k] = ++numNode;
        dp[numNode] = oo;
        Node[numNode] = node(i, j, k);
    }
    dijkstra();

    for (int i = 2; i <= n; i++)
        cout << dp[id[i][1][1]] << " ";
    return 0;
}