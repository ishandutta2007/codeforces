#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e6 + 76;

const int INF = 1e15 + 112;

int t[8 * MAXN];
int add[8 * MAXN];
int sz[8 * MAXN];

void push(int v)
{
    if (sz[v] >= 1)
    {
        t[v] += add[v];
        add[2 * v + 1] += add[v];
        add[2 * v + 2] += add[v];
        add[v] = 0;
    }
}

void pull(int v)
{
    push(2 * v + 1);
    push(2 * v + 2);
    t[v] = max(t[2 * v + 1], t[2 * v + 2]);
    sz[v] = sz[2 * v + 1] + sz[2 * v + 2];
}

void build(int v, int l, int r)
{
    if (r - l == 1)
    {
        t[v] = 0;
        sz[v] = 1;
        return;
    }
    build(2 * v + 1, l, (l + r) / 2);
    build(2 * v + 2, (l + r) / 2, r);
    pull(v);
}

void update(int v, int tl, int tr, int l, int r, int val)
{
    push(v);
    if (l <= tl && tr <= r)
    {
        add[v] += val;
        push(v);
        return;
    }
    if (tl >= r || l >= tr)
    {
        return;
    }
    update(2 * v + 1, tl, (tl + tr) / 2, l, r, val);
    update(2 * v + 2, (tl + tr) / 2, tr, l, r, val);
    pull(v);
    return;
}

int get(int v, int tl, int tr, int l, int r)
{
    push(v);
    if (l <= tl && tr <= r)
    {
        return t[v];
    }
    if (tl >= r || l >= tr)
    {
        return -INF;
    }
    int res = max(get(2 * v + 1, tl, (tl + tr) / 2, l, r), get(2 * v + 2, (tl + tr) / 2, tr, l, r));
    pull(v);
    return res;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, p;
    cin >> n >> m >> p;
    build(0, 0, MAXN);
    vector<pair<int, int>> a(n);
    vector<pair<int, int>> b(m);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> b[i].first >> b[i].second;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int mn = a[n - 1].second;
    for (int i = n - 1; i >= 0; --i)
    {
        a[i].second = min(a[i].second, mn);
        mn = min(mn, a[i].second);
    }
    mn = b[m - 1].second;
    for (int i = m - 1; i >= 0; --i)
    {
        b[i].second = min(b[i].second, mn);
        mn = min(mn, b[i].second);
    }
    update(0, 0, MAXN, 0, b[0].first, -b[0].second);
    for (int i = 1; i < m; ++i)
    {
        update(0, 0, MAXN, b[i - 1].first, b[i].first, -b[i].second);
    }
    update(0, 0, MAXN, b[m - 1].first, MAXN, -INF);
    vector<pair<pair<int, int>, int>> c(p);
    for (int i = 0; i < p; ++i)
    {
        cin >> c[i].first.first >> c[i].first.second >> c[i].second;
    }
    sort(c.begin(), c.end());
    int ans = -INF;
    for (int i = 0; i < p; ++i)
    {
        int cnt = 0;
        int l = -1;
        int r = n;
        while (r - l > 1)
        {
            int med = (l + r) / 2;
            if (a[med].first > c[i].first.first)
            {
                r = med;
            }
            else
            {
                l = med;
            }
        }
        if (r == n)
        {
            ans = max(ans, -a[0].second - b[0].second);
            continue;
        }
        else
        {
            cnt += a[r].second;
        }
        update(0, 0, MAXN, c[i].first.second, MAXN, c[i].second);
        ans = max(ans, get(0, 0, MAXN, 0, MAXN) - cnt);
    }
    cout << ans << endl;
    return 0;
}