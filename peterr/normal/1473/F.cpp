#include <bits/stdc++.h>

using namespace std;

const long long INF = 1E15;
const int MAXN = 3002;
int a[MAXN];
int b[MAXN];
//vector<int> adjList[MAXN];
vector<pair<int, long long>> adjList[MAXN];
int from[MAXN];
bool mult[101][101];

void addEdge(int u, int v, long long w)
{
    adjList[u].push_back({v, w});
    adjList[v].push_back({u, 0});
}

void incEdge(int u, int v, long long amt)
{
    for (pair<int, long long> &edge : adjList[u])
    {
        if (edge.first == v)
        {
            edge.second += amt;
            return;
        }
    }
}

long long bfs(int source, int sink)
{
    fill(from, from + sink + 1, -1);
    from[source] = source;
    queue<pair<int, long long>> q;
    q.push({source, INF});
    while (!q.empty())
    {
        pair<int, long long> pr = q.front();
        int v = pr.first;
        long long flow = pr.second;
        q.pop();
        for (pair<int, long long> edge : adjList[v])
        {
            int adj = edge.first;
            long long w = edge.second;
            if (w == 0 || from[adj] != -1)
                continue;
            from[adj] = v;
            if (adj == sink)
                return min(flow, w);
            q.push({adj, min(flow, w)});
        }
    }
    return 0;
}

long long maxflow(int source, int sink)
{
    long long ans = 0;
    while (1)
    {
        long long flow = bfs(source, sink);
        if (!flow)
            break;
        ans += flow;
        int cur = sink;
        while (cur != source)
        {
            int prev = from[cur];
            incEdge(prev, cur, -flow);
            incEdge(cur, prev, flow);
            cur = prev;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 1; i <= 100; i++)
        for (int j = i; j <= 100; j += i)
            mult[i][j] = true;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        b[i] = -b[i];
    }
    int source = n;
    int sink = n + 1;
    long long ans = 0;
    vector<bool> seen(101);
    for (int i = 0; i < n; i++)
    {
        if (b[i] > 0)
        {
            addEdge(i, sink, b[i]);
        }
        else if (b[i] < 0)
        {
            ans += b[i];
            addEdge(source, i, -b[i]);
        }
        fill(seen.begin(), seen.end(), false);
        for (int j = i - 1; j >= 0; j--)
        {
            if (!seen[a[j]] && mult[a[j]][a[i]])
            {
                seen[a[j]] = true;
                addEdge(i, j, INF);
            }
        }
    }
    ans += maxflow(source, sink);
    cout << -ans << "\n";
    return 0;
}