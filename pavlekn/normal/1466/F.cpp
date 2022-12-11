#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

const int MAXN = 5e5 + 55;

vector<vector<int>> g(MAXN);

vector<vector<int>> num(MAXN);

int sz[MAXN];
int used[MAXN];

int p[MAXN];

int get(int u)
{
    if (p[u] == u)
    {
        return u;
    }
    return p[u] = get(p[u]);
}

void merge(int u, int v)
{
    u = get(u);
    v = get(v);
    p[u] = v;
}

int pw[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    pw[0] = 1;
    for (int i = 1; i < MAXN; ++i)
    {
        pw[i] = (pw[i - 1] * 2) % mod;
    }
    for (int i = 0; i < MAXN; ++i)
    {
        p[i] = i;
    }
    int n, m;
    cin >> n >> m;
    vector<int> ans;
    int cnt = 0;
    set<pair<int, int>> s;
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        vector<int> a(k);
        for (int j = 0; j < k; ++j)
        {
            cin >> a[j];
            num[a[j]].push_back(i);
            g[i].push_back(a[j]);
            ++sz[i];
        }
        s.insert({sz[i], i});
    }
    while (!s.empty())
    {
        auto el = (*s.begin());
        s.erase(s.begin());
        if (el.first == 0)
        {
            continue;
        }
        if (el.first == 2)
        {
            break;
        }
        int u = el.second;
        ans.push_back(u);
        for (auto e : g[u])
        {
            if (!used[e])
            {
                used[e] = true;
                ++cnt;
                for (auto v : num[e])
                {
                    s.erase({sz[v], v});
                    --sz[v];
                    s.insert({sz[v], v});
                }
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (sz[i] == 2)
        {
            int u = g[i][0];
            int v = g[i][1];
            if (get(u) == get(v))
            {
                continue;
            }
            merge(u, v);
            ++cnt;
            ans.push_back(i);
        }
    }
    sort(ans.begin(), ans.end());
    cout << pw[cnt] << " " << ans.size() << endl;
    for (auto el : ans)
    {
        cout << el + 1 << " ";
    }
    cout << endl;
    return 0;
}