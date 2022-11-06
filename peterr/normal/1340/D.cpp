#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
vector<int> adjList[MAXN + 1];
vector<pair<int, int>> ans;

void solve(int v, int p, int num)
{
    ans.push_back(make_pair(v, num));
    int deg = (int) adjList[v].size();
    int children = v == p ? deg : deg - 1;
    int cur = num;
    for (int adj : adjList[v])
    {
        if (adj == p)
            continue;
        if (cur >= num && children < num)
        {
            cur = num - children - 1;
            ans.push_back(make_pair(v, cur));
        }
        cur++;
        solve(adj, v, cur);
        ans.push_back(make_pair(v, cur));
        children--;
    }
    if (v != 1 && cur != num - 1)
        ans.push_back(make_pair(v, num - 1));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    solve(1, 1, 0);
    cout << (int) ans.size() << "\n";
    for (pair<int, int> pr : ans)
        cout << pr.first << " " << pr.second << "\n";
    return 0;
}