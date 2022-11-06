#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
const int LOGN = 17;
int a[MAXN + 1];
vector<int> adjList[MAXN + 1];
int id[MAXN + 1];
int sz[MAXN + 1];
int bit[MAXN + 1];
map<int, int> freq;
int anc[LOGN + 1][MAXN + 1];
int dep[MAXN + 1];
int where[MAXN + 1];
map<int, int> seen;
bool valid = true;

void inc(int pos, int amt)
{
    while (pos <= MAXN)
    {
        bit[pos] += amt;
        pos += pos & -pos;
    }
}

void inc(int l, int r, int amt)
{
    inc(l, amt);
    if (r + 1 <= MAXN)
        inc(r + 1, -amt);
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

int lca(int u, int v)
{
    if (dep[u] > dep[v])
        swap(u, v);
    int diff = dep[v] - dep[u] - 1;
    for (int i = LOGN; i >= 0; i--)
    {
        if (diff & (1 << i))
            v = anc[i][v];
    }
    return v;
}

int doNumber(int v, int p, map<int, int> &curFreq, int cnt=1, int d=0)
{
    dep[v] = d;
    anc[0][v] = p;
    sz[v] = 1;
    id[v] = cnt++;
    for (int adj : adjList[v])
    {
        if (adj == p)
            continue;
        map<int, int> tempFreq;
        cnt = doNumber(adj, v, tempFreq, cnt, d + 1);
        if (tempFreq.count(a[v]) && curFreq.count(a[v]))
            valid = false;
        if (tempFreq.size() > curFreq.size())
            swap(tempFreq, curFreq);
        for (auto it : tempFreq)
            curFreq[it.first] += it.second;
        sz[v] += sz[adj];
    }
    curFreq[a[v]]++;
    int f = curFreq[a[v]];
    if (f > 1 && f != freq[a[v]])
        valid = false;
    return cnt;
}

void dfs(int v=1, int p=1)
{
    if (seen.count(a[v]))
    {
        int u = seen[a[v]];
        where[u] = lca(u, v);
    }
    else
        seen[a[v]] = v;
    for (int adj : adjList[v])
    {
        if (adj == p)
            continue;
        dfs(adj, v);
    }
    if (seen[a[v]] == v)
        seen.erase(a[v]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    fill(where + 1, where + n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        freq[a[i]]++;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    map<int, int> tempMap;
    doNumber(1, 1, tempMap);
    if (!valid)
    {
        cout << "0\n";
        return 0;
    }
    for (int i = 1; i <= LOGN; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            anc[i][j] = anc[i - 1][anc[i - 1][j]];
        }
    }
    dfs();
    /*
    for (int i = 1; i <= n; i++)
        cout << "num " << i << " " << where[i] << endl;
    */
    int delta = 0;
    for (int i = 1; i <= n; i++)
    {
        if (freq[a[i]] == 1)
            continue;
        if (where[i] == -1)
        {
            inc(id[i], id[i] + sz[i] - 1, 1);
        }
        else
        {
            delta++;
            for (int adj : adjList[i])
            {
                if (adj == where[i])
                {
                    inc(id[adj], id[adj] + sz[adj] - 1, -1);
                    break;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (query(i) + delta == 0)
            ans++;
    }
    cout << ans << "\n";
    return 0;
}