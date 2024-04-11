#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int u, v, w;
};

const int MAXN = (int) 1E5;
int parent[MAXN + 1];
int s[MAXN + 1];
int special[MAXN + 1];
vector<Edge> edges;

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

int getRoot(int x)
{
    if (parent[x] != x)
        parent[x] = getRoot(parent[x]);
    return parent[x];
}

void mge(int a, int b)
{
    int r1 = getRoot(a);
    int r2 = getRoot(b);
    if (r1 == r2)
        return;
    if (s[r1] > s[r2])
        swap(r1, r2);
    parent[r1] = r2;
    s[r2] += s[r1];
    special[r2] += special[r1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        s[i] = 1;
    }
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        special[x]++;
    }
    for (int i = 0; i < m; i++)
    {
        Edge e;
        cin >> e.u >> e.v >> e.w;
        edges.push_back(e);
    }
    sort(edges.begin(), edges.end(), cmp);
    int ans = 0;
    int index = 0;
    for (int i = 0; i < n - 1; i++)
    {
        while (true)
        {
            Edge e = edges[index];
            index++;
            int r1 = getRoot(e.u);
            int r2 = getRoot(e.v);
            if (r1 != r2)
            {
                if (special[r1] > 0 && special[r2] > 0)
                    ans = e.w;
                mge(e.u, e.v);
                break;
            }
        }
    }
    for (int i = 0; i < k; i++)
    {
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}