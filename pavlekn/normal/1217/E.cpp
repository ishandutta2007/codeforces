#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;

const int INF = 1e9 + 27;

int t1[4 * MAXN][10];
int t2[4 * MAXN][10];

int a[MAXN];

void update(int i, int v, int l, int r, int pos, int val)
{
    if (pos < l || pos >= r)
    {
        return;
    }
    if (pos == l && pos + 1 == r)
    {
        t1[v][i] = val;
        t2[v][i] = INF;
        return;
    }
    update(i, 2 * v + 1, l, (l + r) / 2, pos, val);
    update(i, 2 * v + 2, (l + r) / 2, r, pos, val);
    t1[v][i] = min(t1[2 * v + 1][i], t1[2 * v + 2][i]);
    t2[v][i] = max(t1[2 * v + 1][i], t1[2 * v + 2][i]);
    t2[v][i] = min(t2[v][i], t2[2 * v + 1][i]);
    t2[v][i] = min(t2[v][i], t2[2 * v + 2][i]);
    return;
}

pair<int, int> get(int i, int v, int l, int r, int tl, int tr)
{
    if (r <= tl || tr <= l)
    {
        return {INF, INF};
    }
    if (l <= tl && tr <= r)
    {
        return {t1[v][i], t2[v][i]};
    }
    auto ans1 = get(i, 2 * v + 1, l, r, tl, (tl + tr) / 2);
    auto ans2 = get(i, 2 * v + 2, l, r, (tl + tr) / 2, tr);
    t1[v][i] = min(t1[2 * v + 1][i], t1[2 * v + 2][i]);
    t2[v][i] = max(t1[2 * v + 1][i], t1[2 * v + 2][i]);
    t2[v][i] = min(t2[v][i], t2[2 * v + 1][i]);
    t2[v][i] = min(t2[v][i], t2[2 * v + 2][i]);
    return {min(ans1.first, ans2.first), min(min(ans1.second, max(ans1.first, ans2.first)), ans2.second)};
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    vector<int> pow(10);
    pow[0] = 1;
    for (int i = 0; i < 9; ++i)
    {
        pow[i + 1] = pow[i] * 10;
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            if ((a[i] / pow[j]) % 10)
            {
                update(j, 0, 0, MAXN, i, a[i]);
            }
            else
            {
                update(j, 0, 0, MAXN, i, INF);
            }
        }
    }
    for (int _ = 0; _ < m; ++_)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int pos, val;
            cin >> pos >> val;
            --pos;
            a[pos] = val;
            for (int i = 0; i < 10; ++i)
            {
                if ((val / pow[i]) % 10)
                {
                    update(i, 0, 0, MAXN, pos, val);
                }
                else
                {
                    update(i, 0, 0, MAXN, pos, INF);
                }
            }
        }
        else
        {
            int l, r;
            cin >> l >> r;
            --l;
            int ans = 2 * INF;
            for (int i = 0; i < 10; ++i)
            {
                auto cur = get(i, 0, l, r, 0, MAXN);
                if (cur.second < INF)
                {
                    ans = min(ans, cur.first + cur.second);
                }
            }
            if (ans == 2 * INF)
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << ans << "\n";
            }
        }
    }
    return 0;
}