#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
vector<int> adjList[MAXN + 1];
bool visited[MAXN + 1];
int dist[MAXN + 1];
int pre[MAXN + 1];

void bfs(int start, int &leaf, bool doDist, bool doPrev)
{
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = true;
    while (!q.empty())
    {
        int cur = q.front().first;
        int d = q.front().second;
        if (doDist)
            dist[cur] = d;
        q.pop();
        for (int adj : adjList[cur])
        {
            if (!visited[adj])
            {
                if (doPrev)
                    pre[adj] = cur;
                visited[adj] = true;
                q.push({adj, d + 1});
            }
        }
        leaf = cur;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    int leaf, otherLeaf, diam, trash, center;
    bfs(1, leaf, false, false);
    fill(visited + 1, visited + n  + 1, false);
    bfs(leaf, otherLeaf, true, true);
    diam = dist[otherLeaf];
    if (diam != k * 2)
    {
        cout << "No" << endl;
    }
    else
    {
        center = otherLeaf;
        for (int i = 0; i < diam / 2; i++)
            center = pre[center];
        fill(visited + 1, visited + n + 1, false);
        bfs(center, trash, true, false);
        /*
        cout << "leaf " << leaf << endl;
        cout << "other " << otherLeaf << endl;
        cout << "test pre" << endl;
        for (int i = 1; i <= n; i++)
            cout << i << " " << pre[i] << endl;
        cout << "test dist" << endl;
        for (int i = 1; i <= n; i++)
            cout << i << " " << dist[i] << endl;
        */
        bool valid = true;
        for (int i = 1; i <= n; i++)
        {
            if (i == center)
            {
                if (adjList[i].size() < 3)
                    valid = false;
            }
            else if (adjList[i].size() == 1)
            {
                if (dist[i] != k)
                    valid = false;
            }
            else if (adjList[i].size() < 4)
            {
                valid = false;
            }
        }
        if (valid)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}