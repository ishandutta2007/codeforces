#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int) 1E5;
int parent[MAXN + 1];
int s[MAXN + 1];
vector<int> adjList[MAXN + 1];

int getRoot(int a)
{
    if (parent[a] != a)
    {
        parent[a] = getRoot(parent[a]);
    }
    return parent[a];
}

int mge(int a, int b)
{
    int r1 = getRoot(a);
    int r2 = getRoot(b);
    if (r1 == r2)
        return r1;
    if (s[r1] > s[r2])
        swap(r1, r2);
    parent[r1] = r2;
    s[r2] += s[r1];
    return r2;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        s[i] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    unordered_map<int, int> comps;
    for (int i = 1; i <= n; i++)
    {
        unordered_map<int, int> cnt;
        for (int adj : adjList[i])
        {
            if (adj > i)
                continue;
            int r = getRoot(adj);
            if (cnt.find(r) == cnt.end())
                cnt[r] = 1;
            else
                cnt[r]++;
        }
        comps[i] = 1;
        int r1 = i;
        vector<pair<int, int>> vec;
        for (auto it = comps.begin(); it != comps.end(); it++)
        {
            vec.push_back({it->first, it->second});
        }
        for (pair<int, int> pr : vec)
        {
            int r2 = pr.first;
            int sizee = pr.second;
            if (cnt[r2] < sizee)
            {
                comps.erase(r1);
                comps.erase(r2);
                r1 = mge(r1, r2);
                comps[r1] = s[r1];
            }
        }
    }
    cout << (int) comps.size() - 1 << endl;
    return 0;
}