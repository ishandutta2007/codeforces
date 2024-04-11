#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int parent[MAXN + 1];
int s[MAXN + 1];
int m[MAXN + 1];
int t[MAXN + 1];
int edges[MAXN];
int deg[MAXN + 1];
int ans[MAXN + 1];

int getRoot(int x)
{
    if (parent[x] != x)
        parent[x] = getRoot(parent[x]);
    return parent[x];
}

void mge(int a, int b)
{
    int r1 = getRoot(a);
    int r2 = getRoot(b);
    if (r1 == r2)
        return;
    if (s[r1] < s[r2])
        swap(r1, r2);
    parent[r2] = r1;
    s[r1] += s[r2];
    m[r1] = max(m[r1], m[r2]);
    t[r1] = a;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        s[i] = 1;
        m[i] = i;
        t[i] = i;
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> edges[i];
        deg[edges[i]]++;
    }
    int root = edges[0];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] == 0)
            pq.push({i, i});
    }
    for (int i = n - 2; i >= 0; i--)
    {
        int mainLamp = edges[i];
        pair<int, int> pr = pq.top();
        pq.pop();
        int target = pr.second;
        int r = getRoot(target);
        ans[t[r]] = mainLamp;
        mge(mainLamp, r);
        deg[mainLamp]--;
        r = getRoot(mainLamp);
        if (deg[mainLamp] == 0)
        pq.push({m[r], mainLamp});
    }
    cout << root << "\n";
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] != 0)
            cout << ans[i] << " " << i << "\n";
    }

    return 0;
}