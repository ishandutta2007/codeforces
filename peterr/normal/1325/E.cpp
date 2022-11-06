#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
const int MAXA = 1E6;
bool sq[MAXA + 1];
int a[MAXN];
int sieve[MAXA + 1];
int name[MAXA + 1];
vector<int> adjList[MAXN + 1];
bool sp[MAXN + 1];
int dist[MAXN + 1];
int from[MAXN + 1];
bool edgeSeen[MAXA + 1];

int main()
{
    for (int i = 2; i <= MAXA; i++)
    {
        if (sieve[i] == 0)
        {
            sieve[i] = i;
            for (int j = 2 * i; j <= MAXA; j += i)
            {
                sieve[j] = i;
            }
        }
    }
    int cnt = 0;
    for (int i = 2; i <= MAXA; i++)
    {
        if (sieve[i] == i)
            name[i] = ++cnt;
    }
    for (int i = 1; i * i <= MAXA; i++)
    {
        sq[i * i] = true;
    }
    int n;
    cin >> n;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (sq[a[i]])
            flag = true;
    }
    if (flag)
    {
        cout << 1 << endl;
    }
    else
    {
        bool one = false;
        for (int i = 0; i < n; i++)
        {
            int p = sieve[a[i]];
            int x = a[i];
            bool par = 0;
            while (x % p == 0)
            {
                x /= p;
                par = !par;
            }
            if (x > 1 && sieve[x] == x)
            {
                int p2 = sieve[x];
                if (p2 == x && par == 1)
                {
                    if (edgeSeen[p * p2])
                        one = true;
                    edgeSeen[p * p2] = true;
                    int u = name[p];
                    int v = name[p2];
                    adjList[v].push_back(u);
                    adjList[u].push_back(v);
                }
                else if (par == 0)
                {
                    if (sp[name[p2]])
                        one = true;
                    sp[name[p2]] = true;
                }
            }
            else
            {
                if (sp[name[p]])
                    one = true;
                sp[name[p]] = true;
            }
        }
        if (one)
            cout << 2 << endl;
        else
        {
            queue<pair<int, int>> q;
            fill(dist, dist + MAXN + 1, -1);
            for (int i = 1; i <= MAXN; i++)
            {
                if (sp[i])
                {
                    q.push(make_pair(i, 0));
                    dist[i] = 0;
                    from[i] = i;
                }
            }
            int d = MAXN * 2;
            while (!q.empty())
            {
                pair<int, int> pr = q.front();
                q.pop();
                for (int adj : adjList[pr.first])
                {
                    if (from[adj] == 0)
                    {
                        q.push(make_pair(adj, pr.second + 1));
                        dist[adj] = pr.second + 1;
                        from[adj] = from[pr.first];
                    }
                    else if (from[adj] != from[pr.first])
                    {
                        d = min(d, dist[adj] + pr.second + 3);
                    }
                }
            }
            for (int i = 2; i * i <= MAXA; i++)
            {
                if (sieve[i] != i)
                    continue;
                fill(from, from + MAXN + 1, 0);
                fill(dist, dist + MAXN + 1, -1);
                dist[name[i]] = 0;
                from[name[i]] = i;
                q.push(make_pair(name[i], 0));
                while (!q.empty())
                {
                    pair<int, int> pr = q.front();
                    q.pop();
                    for (int adj : adjList[pr.first])
                    {
                        if (adj == from[pr.first])
                            continue;
                        if (from[adj] == 0)
                        {
                            from[adj] = pr.first;
                            dist[adj] = dist[pr.first] + 1;
                            q.push(make_pair(adj, dist[adj]));
                        }
                        else
                        {
                            d = min(d, dist[pr.first] + dist[adj] + 1);
                        }
                    }
                }
            }
            if (d == MAXN * 2)
                cout << -1 << endl;
            else
                cout << d << endl;
        }
    }
    return 0;
}