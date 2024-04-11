#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int deg[MAXN + 1];
tuple<int, int, int> edges[MAXN - 1];
bool visited[MAXN - 1];
int nxt[MAXN + 1];
unordered_map<int, vector<int>> where;
queue<int> q;
int edgeAns[MAXN - 1];

void solve(int added, int n)
{
    int cur = q.front();
    q.pop();
    for (int edgeId : where[cur])
    {
        if (!visited[edgeId])
        {
            edgeAns[added + 1] = edgeId;
            visited[edgeId] = true;
            tuple<int, int, int> curEdge = edges[edgeId];
            int a, b, c;
            a = get<0>(curEdge);
            b = get<1>(curEdge);
            c = get<2>(curEdge);
            if (b == cur)
                swap(a, b);
            if (c == cur)
                swap(a, c);
            deg[b]--;
            deg[c]--;
            if (deg[b] == 1)
                q.push(b);
            if (deg[c] == 1)
                q.push(c);
            if (added == n - 3)
            {
                nxt[a] = b;
                nxt[b] = c;
                nxt[c] = a;
            }
            else
            {
                solve(added + 1, n);
                if (nxt[b] == c)
                {
                    nxt[b] = a;
                    nxt[a] = c;
                }
                else
                {
                    nxt[c] = a;
                    nxt[a] = b;
                }
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        where.clear();
        q = queue<int>();
        fill(deg + 1, deg + n + 1, 0);
        for (int i = 1; i <= n; i++)
            where[i] = vector<int>();
        for (int i = 1; i <= n - 2; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            edges[i] = make_tuple(a, b, c);
            deg[a]++;
            deg[b]++;
            deg[c]++;
            where[a].push_back(i);
            where[b].push_back(i);
            where[c].push_back(i);
        }
        for (int i = 1; i <= n; i++)
            if (deg[i] == 1)
                q.push(i);
        fill(nxt + 1, nxt + n + 1, 0);
        fill(visited + 1, visited + n - 1, false);
        solve(0, n);
        int cur = 1;
        for (int i = 0; i < n; i++)
        {
            if (i > 0)
                cout << " ";
            cout << cur;
            cur = nxt[cur];
        }
        cout << endl;
        for (int i = 1; i <= n - 2; i++)
        {
            if (i > 1)
                cout << " ";
            cout << edgeAns[i];
        }
        cout << endl;
    }
    return 0;
}