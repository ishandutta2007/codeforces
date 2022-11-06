#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
tuple<int, int, int> edges[MAXN];
bool active[MAXN];
int parent[MAXN + 1];
int sz[MAXN + 1];

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
    if (sz[r1] < sz[r2])
        swap(r1, r2);
    parent[r2] = r1;
    sz[r1] += sz[r2];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = make_tuple(w, u, v);
    }
    sort(edges, edges + m);
    fill(active, active + m, true);
    int ptr = 0;
    int ans = 0;
    while (ptr < m)
    {
        int start = ptr;
        int w = get<0>(edges[ptr]);
        while (ptr < m && get<0>(edges[ptr]) == w)
        {
            int u = get<1>(edges[ptr]);
            int v = get<2>(edges[ptr]);
            if (getRoot(u) == getRoot(v))
                active[ptr] = false;
            ptr++;
        }
        for (int j = start; j < ptr; j++)
        {
            if (active[j])
            {
                int u = get<1>(edges[j]);
                int v = get<2>(edges[j]);
                if (getRoot(u) == getRoot(v))
                    ans++;
                mge(u, v);
            }
        }
    }
    cout << ans << endl;
    return 0;
}