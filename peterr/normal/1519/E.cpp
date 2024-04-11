#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
tuple<int, int, int, int> a[MAXN + 1];
vector<pair<int, int>> ans;
vector<vector<int>> comps;
vector<int> where[MAXN + 1];
tuple<int, int, int> edges[MAXN];
bool used[MAXN + 1];
vector<int> adjList[2 * MAXN];
bool visited[2 * MAXN];

pair<long long, long long> norm(long long x, long long y)
{
    long long g = __gcd(x, y);
    return {x / g, y / g};
}

int dfs(int v, int p)
{
    int unusedId = -1;
    visited[v] = true;
    for (int edgeId : adjList[v])
    {
        tuple<int, int, int> e = edges[edgeId];
        int adj = get<0>(e);
        if (adj == v)
            adj = get<1>(e);
        int ind = get<2>(e);
        if (adj == p || used[ind] || visited[adj])
            continue;
        int edgeId2 = dfs(adj, v);
        if (edgeId2 != -1)
        {
            ans.push_back({ind, get<2>(edges[edgeId2])});
            used[ind] = used[get<2>(edges[edgeId2])] = true;
        }
    }
    for (int edgeId : adjList[v])
    {
        tuple<int, int, int> e = edges[edgeId];
        int adj = get<0>(e);
        if (adj == v)
            adj = get<1>(e);
        int ind = get<2>(e);
        if (adj == p || used[ind])
            continue;
        if (unusedId == -1)
        {
            unusedId = edgeId;
        }
        else
        {
            ans.push_back({ind, get<2>(edges[unusedId])});
            used[ind] = used[get<2>(edges[unusedId])] = true;
            unusedId = -1;
        }
    }
    return unusedId;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    map<pair<long long, long long>, vector<int>> mp;
    for (int i = 1; i <= n; i++)
    {
        int w, x, y, z;
        cin >> w >> x >> y >> z;
        a[i] = {w, x, y, z};
        mp[norm((long long) (w + x) * z, (long long) x * y)].push_back(i);
        mp[norm((long long) w * z, (long long) x * (y + z))].push_back(i);
    }
    int cnt = 0;
    for (auto it : mp)
    {
        comps.push_back(vector<int>());
        for (int ind : it.second)
        {
            comps.back().push_back(ind);
            where[ind].push_back(cnt);
        }
        cnt++;
        //cout << "key " << it.first.first << " " << it.first.second << endl;
        //for (int ind : it.second)
        //  cout << ind << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        int ind1 = where[i][0];
        int ind2 = where[i][1];
        edges[i - 1] = {ind1, ind2, i};
        adjList[ind1].push_back(i - 1);
        adjList[ind2].push_back(i - 1);
        //cout << "where " << i << endl;
        //for (int ind : where[i])
        //    cout << ind << endl;
    }
    dfs(1, 1);
    for (int i = 0; i < 2 * n; i++)
    {
        if (!visited[i])
            dfs(i, i);
    }
    cout << ans.size() << "\n";
    for (pair<int, int> pr : ans)
        cout << pr.first << " " << pr.second << "\n";
    return 0;
}