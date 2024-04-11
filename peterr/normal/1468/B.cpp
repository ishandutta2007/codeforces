#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int a[MAXN];
int par[MAXN];
int sz[MAXN];
int small[MAXN];
int big[MAXN];
bool visited[MAXN];
long long pref[MAXN];

long long query(int l, int r)
{
    return pref[r] - (l > 0 ? pref[l - 1] : 0);
}

int getRoot(int x)
{
    if (par[x] != x)
        par[x] = getRoot(par[x]);
    return par[x];
}

bool mge(int x, int y)
{
    x = getRoot(x);
    y = getRoot(y);
    if (x == y)
        return false;
    if (sz[x] > sz[y])
        swap(x, y);
    par[x] = y;
    sz[y] += sz[x];
    small[y] = min(small[y], small[x]);
    big[y] = max(big[y], big[x]);
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    priority_queue<pair<int, int>> pq;
    fill(sz, sz + n, 1);
    for (int i = 0; i < n; i++)
    {
        par[i] = small[i] = big[i] = i;
        cin >> a[i];
        if (i < n - 1)
        {
            pq.push({a[i] - 1, i});
        }
        if (i)
            pref[i] = pref[i - 1];
        pref[i] += a[i];
    }
    map<int, int> mp;
    mp[1E9] = 0;
    int curAns = 0;
    while (!pq.empty())
    {
        pair<int, int> pr = pq.top();
        pq.pop();
        int k = pr.first;
        int r = pr.second;
        if (visited[r])
            continue;
        int root = getRoot(r);
        int l = small[root];
        if (query(l, r) <= (long long) k * (r - l + 1))
            continue;
        while (r < n - 1 && query(l, r) > (long long) k * (r - l + 1))
        {
            visited[r] = true;
            mge(r, r + 1);
            root = getRoot(r);
            r = big[root];
        }
        if (r < n - 1)
        {
            int len = r - l + 1;
            pq.push({(query(l, r) + len - 1) / len - 1, r});
        }
        curAns = max(curAns, r - l);
        mp[k] = curAns;
    }
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        auto it = mp.lower_bound(k);
        cout << it->second << " ";
    }
    cout << "\n";
    return 0;
}