#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
vector<int> adjList[MAXN + 1];
bool special[MAXN + 1];
tuple<int, int, int> pt[MAXN + 1];
int dist[MAXN + 1];
int bit[MAXN + 1];

void inc(int pos, int amt)
{
    if (pos == 0)
    {
        bit[pos] += amt;
        return;
    }

    while (pos <= MAXN)
    {
        bit[pos] += amt;
        pos += pos & -pos;
    }
}

int query(int pos)
{
    int ans = 0;
    while (pos)
    {
        ans += bit[pos];
        pos -= pos & -pos;
    }
    return ans;
}

int sc()
{
    int target = query(MAXN);
    int ans = 0;
    for (int i = 20; i >= 0; i--)
    {
        if ((1 << i) + ans <= MAXN && bit[(1 << i) + ans] < target)
        {
            ans += (1 << i);
            target -= bit[ans];
        }
    }
    if (ans == 0 && bit[0] == 1)
        return 0;
    return ans + 1;
}

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b)
{
    return get<0>(a) - get<1>(a) < get<0>(b) - get<1>(b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        special[a] = true;
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
        get<2>(pt[i]) = i;
    fill(dist + 1, dist + n + 1, -1);
    dist[1] = 0;
    get<0>(pt[1]) = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int adj : adjList[v])
        {
            if (dist[adj] == -1)
            {
                dist[adj] = dist[v] + 1;
                get<0>(pt[adj]) = dist[adj];
                q.push(adj);
            }
        }
    }
    fill(dist + 1, dist + n + 1, -1);
    dist[n] = 0;
    get<1>(pt[n]) = 0;
    q.push(n);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int adj : adjList[v])
        {
            if (dist[adj] == -1)
            {
                dist[adj] = dist[v] + 1;
                get<1>(pt[adj]) = dist[adj];
                q.push(adj);
            }
        }
    }
    for (int i = 1; i <= n; i++)
        if (special[i])
            inc(get<1>(pt[i]), 1);
    int cnt = k;
    sort(pt + 1, pt + n + 1, cmp);
    int top = -1;

    int ans = -1;
    for (int i = 1; i <= n; i++)
    {
        tuple<int, int, int> cur = pt[i];
        if (!special[get<2>(cur)])
            continue;
        inc(get<1>(cur), -1);
        cnt--;
        if (cnt)
        {
            ans = max(ans, get<0>(cur) + sc() + 1);
        }
        if (top != -1)
        {
            ans = max(ans, get<1>(cur) + top + 1);
        }
        top = max(top, get<0>(cur));
    }
    ans = min(ans, dist[1]);
    cout << ans << "\n";
    return 0;
}