#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5E5;
bool seen[MAXN];
vector<int> adjList[MAXN + 1];
vector<int> prs[MAXN + 1];
vector<int> where[MAXN];
bool visited[MAXN + 1];

int main()
{
    int n;
    cin >> n;
    if (n & 1)
    {
        cout << "Second" << endl;
        for (int i = 1; i <= 2 * n; i++)
        {
            int p;
            cin >> p;
            prs[p].push_back(i);
            where[i % n].push_back(p);
            //cout << i << " " << where[i % n].back() << endl;
        }
        for (int i = 0; i < n; i++)
        {
            int u = where[i][0];
            int v = where[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        vector<int> ans;
        for (int i = 1; i <= n; i++)
        {
            if (visited[i])
                continue;
            visited[i] = true;
            ans.push_back(prs[i][0]);
            seen[prs[i][0] % n] = true;
            int cur = prs[i][1];
            int node = i;
            while (!seen[cur % n])
            {
                int nxt = where[cur % n][0];
                if (nxt == node)
                    nxt = where[cur % n][1];
                node = nxt;
                if (prs[node][0] % n == cur % n)
                {
                    ans.push_back(prs[node][0]);
                    cur = prs[node][1];
                }
                else
                {
                    ans.push_back(prs[node][1]);
                    cur = prs[node][0];
                }
                visited[node] = true;
            }
        }
        int sum = 0;
        for (int x : ans)
        {
            //cout << "x " << x << endl;
            sum += x;
            if (sum >= 2 * n)
                sum -= 2 * n;
        }
        bool flip = sum > 0;
        sort(ans.begin(), ans.end());
        reverse(ans.begin(), ans.end());
        for (int i = 1; i <= 2 * n; i++)
        {
            if (ans.back() == i)
            {
                ans.pop_back();
                if (!flip)
                    cout << i << " ";
            }
            else
            {
                if (flip)
                    cout << i << " ";
            }
        }
        cout << endl;
    }
    else
    {
        cout << "First" << endl;
        for (int i = 1; i <= n; i++)
        {
            cout << i << " ";
        }
        for (int i = 1; i <= n; i++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    int trash;
    cin >> trash;
    return 0;
}