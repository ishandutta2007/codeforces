#include <bits/stdc++.h>

using namespace std;

const int MAXM = 128;
const int MAXN = 1E5;
const int INF = (int) 1E5;
long long arr[MAXN];
vector<int> adjList[MAXM];
int dist[MAXM];
int from[MAXM];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int p1 = 0;
    int p2 = 0;
    while (p1 < n)
    {
        while (p1 < n && arr[p1] == 0)
            p1++;
        if (p1 < n)
        {
            arr[p2] = arr[p1];
            p2++;
            p1++;
        }
    }
    n = p2;
    if (n > 128)
    {
        cout << 3 << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] & arr[j])
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        int ans = INF;
        for (int i = 0; i < n; i++)
        {
            fill(dist, dist + n, INF);
            fill(from, from + n, -1);
            from[i] = i;
            dist[i] = 0;
            queue<int> q;
            q.push(i);
            while (!q.empty())
            {
                int v = q.front();
                q.pop();
                for (int adj : adjList[v])
                {
                    if (adj == from[v])
                        continue;
                    if (from[adj] == -1)
                    {
                        from[adj] = v;
                        dist[adj] = dist[v] + 1;
                        q.push(adj);
                    }
                    else
                    {
                        ans = min(ans, dist[v] + dist[adj] + 1);
                    }
                }
            }
        }
        if (ans == INF)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }

    return 0;
}