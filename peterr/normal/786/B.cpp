#include <bits/stdc++.h>

using namespace std;

const long long INF = 1E15;
const int LOGN = 17;
const int MAXN = 1E5;
vector<tuple<int, int, int>> adjList[3][2 * MAXN + 1];
long long dist[3][2 * MAXN + 1];

void build(int ind, int prev, int n)
{
    if (prev != -1)
    {
        adjList[1][prev].push_back(make_tuple(1, ind, 0));
        adjList[2][ind].push_back(make_tuple(2, prev, 0));
    }
    if (ind >= n)
    {
        adjList[1][ind].push_back(make_tuple(0, ind - n, 0));
        adjList[0][ind - n].push_back(make_tuple(2, ind, 0));
    }
    else
    {
        build(ind * 2, ind, n);
        build(ind * 2 + 1, ind, n);
    }
}

void add1(int v, int w, int l, int r, int n)
{
    r += n;
    l += n;
    while (l <= r)
    {
        if (l & 1)
        {
            adjList[0][v].push_back(make_tuple(1, l, w));
            l++;
        }
        if ((r & 1) == 0)
        {
            adjList[0][v].push_back(make_tuple(1, r, w));
            r--;
        }
        l >>= 1;
        r >>= 1;
    }
}

void add2(int v, int w, int l, int r, int n)
{
    r += n;
    l += n;
    while (l <= r)
    {
        if (l & 1)
        {
            adjList[2][l].push_back(make_tuple(0, v, w));
            l++;
        }
        if ((r & 1) == 0)
        {
            adjList[2][r].push_back(make_tuple(0, v, w));
            r--;
        }
        l >>= 1;
        r >>= 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q, s;
    cin >> n >> q >> s;
    s--;
    build(1, -1, n);
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int v, u, w;
            cin >> v >> u >> w;
            u--;
            v--;
            adjList[0][v].push_back(make_tuple(0, u, w));
        }
        else
        {
            int v, l, r, w;
            cin >> v >> l >> r >> w;
            v--;
            l--;
            r--;
            if (t == 2)
            {
                add1(v, w, l, r, n);
            }
            else
            {
                add2(v, w, l, r, n);
            }
        }
    }
    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
    pq.push(make_tuple(0, 0, s));
    for (int i = 0; i < 3; i++)
        fill(dist[i], dist[i] + 2 * n, INF);
    dist[0][s] = 0;
    while (!pq.empty())
    {
        tuple<long long, int, int> tup = pq.top();
        pq.pop();
        long long d = get<0>(tup);
        int ind1 = get<1>(tup);
        int ind2 = get<2>(tup);
        if (d > dist[ind1][ind2])
            continue;
        for (tuple<int, int, int> edge : adjList[ind1][ind2])
        {
            int otherind1 = get<0>(edge);
            int otherind2 = get<1>(edge);
            int weight = get<2>(edge);
            if (d + weight < dist[otherind1][otherind2])
            {
                dist[otherind1][otherind2] = weight + d;
                pq.push(make_tuple(dist[otherind1][otherind2], otherind1, otherind2));
            }
        }
    }
    for (int i = 0; i < n; i++)
        if (dist[0][i] == INF)
            dist[0][i] = -1;
    for (int i = 0; i < n; i++)
        cout << dist[0][i] << " \n"[i == n - 1];
    return 0;
}