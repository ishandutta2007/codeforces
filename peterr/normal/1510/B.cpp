#include <bits/stdc++.h>

using namespace std;

const int INF = 1E9;
const int MAXD = 10;
const int MAXN = 1 << MAXD;
const int NODES = 2 * MAXN + 2;
const int SOURCE = NODES - 1;
const int SINK = NODES - 2;
vector<int> adjList[NODES];
vector<tuple<int, int, int, int>> edges;
int a[MAXN];
bool inq[NODES];
int dist[NODES];
int from[NODES];
int flow[NODES];
int par[NODES];
bool terminal[NODES];

void addEdge(int u, int v, int cap, int cost)
{
    adjList[u].push_back((int) edges.size());
    adjList[v].push_back((int) edges.size() + 1);
    edges.push_back({u, v, cap, cost});
    edges.push_back({v, u, 0, -cost});
}

void spfa()
{
    fill(dist, dist + NODES, INF);
    fill(from, from + NODES, -1);
    fill(inq, inq + NODES, false);
    queue<int> q;
    q.push(SOURCE);
    dist[SOURCE] = 0;
    inq[SOURCE] = true;
    flow[SOURCE] = INF;
    while (!q.empty())
    {
        int v = q.front();
        inq[v] = false;
        q.pop();
        for (int edgeId : adjList[v])
        {
            int adj = get<1>(edges[edgeId]);
            int cap = get<2>(edges[edgeId]);
            int cost = get<3>(edges[edgeId]);
            if (!cap)
                continue;
            if (dist[v] + cost < dist[adj])
            {
                dist[adj] = dist[v] + cost;
                flow[adj] = min(flow[v], cap);
                from[adj] = edgeId;
                if (!inq[adj])
                {
                    q.push(adj);
                    inq[adj] = true;
                }
            }
        }
    }
}

int mincostflow()
{
    int ans = 0;
    while (1)
    {
        spfa();
        if (dist[SINK] == INF)
            break;
        int cur = SINK;
        while (cur != SOURCE)
        {
            int edgeId = from[cur];
            int prev = get<0>(edges[edgeId]);
            get<2>(edges[edgeId]) -= flow[SINK];
            get<2>(edges[edgeId ^ 1]) += flow[SINK];
            cur = prev;
        }
        ans += flow[SINK] * dist[SINK];
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int d, n;
    cin >> d >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        a[i] = stoi(s, NULL, 2);
        addEdge(SOURCE, i, 1, 0);
        addEdge(i, SINK, 1, 0);
        addEdge(n + i, SINK, 1, 0);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j || (a[i] & a[j]) != a[i])
                continue;
            addEdge(i, n + j, 1, -1 - __builtin_popcount(a[i]));
        }
    }
    mincostflow();
    for (int i = 0; i < n; i++)
    {
        par[i] = i;
    }
    fill(terminal, terminal + n, true);
    for (int i = 0; i < n; i++)
    {
        for (int edgeId : adjList[i])
        {
            int adj = get<1>(edges[edgeId]);
            if (adj == SINK || get<2>(edges[edgeId]) == 1)
                continue;
            par[i] = adj - n;
            terminal[par[i]] = false;
        }
        //cout << "par " << i << " = " << par[i] << endl;
    }
    vector<char> ans;
    for (int i = 0; i < n; i++)
    {
        if (!terminal[i])
            continue;
        int cur = i;
        int mask = 0;
        while (1)
        {
            for (int j = 0; j < d; j++)
            {
                if (!(mask & (1 << j)) && (a[cur] & (1 << (d - j - 1))))
                {
                    mask = mask ^ (1 << j);
                    ans.push_back((char) ('0' + j));
                }
            }
            if (par[cur] == cur)
                break;
            cur = par[cur];
        }
        ans.push_back('R');
    }
    ans.pop_back();
    cout << ans.size() << "\n";
    for (char ch : ans)
        cout << ch << " ";
    cout << "\n";
    return 0;
}