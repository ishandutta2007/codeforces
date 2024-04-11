#include <bits/stdc++.h>

using namespace std;

const int INF = 1E9 + 5;
const int MAXN = 2E5;
pair<int, int> segs[9][2 * MAXN];

pair<int, int> query(int l, int r, pair<int, int> seg[2 * MAXN])
{
    pair<int, int> ans = make_pair(INF, MAXN);
    l += MAXN;
    r += MAXN;
    while (l <= r)
    {
        if (l % 2 != 0)
            ans = min(ans, seg[l++]);
        if (r % 2 == 0)
            ans = min(ans, seg[r--]);
        l /= 2;
        r /= 2;
    }
    return ans;
}

void update(int pos, int x, pair<int, int> seg[2 * MAXN])
{
    pos += MAXN;
    seg[pos] = make_pair(x, pos - MAXN);
    pos /= 2;
    while (pos > 0)
    {
        seg[pos] = min(seg[pos * 2], seg[pos * 2 + 1]);
        pos /= 2;
    }
}

void process(int index, int x)
{
    int ten = 1;
    for (int i = 0; i < 9; i++)
    {
        if (x / ten % 10 == 0)
        {
            update(index, INF, segs[i]);
        }
        else
        {
            update(index, x, segs[i]);
        }
        ten *= 10;
    }
}

int solve(int l, int r)
{
    if (l == r)
        return -1;
    int ans = 2 * INF;
    for (int i = 0; i < 9; i++)
    {
        pair<int, int> pr1 = query(l, r, segs[i]);
        int x1 = pr1.first;
        if (x1 == INF)
            continue;
        int ind = pr1.second;
        pair<int, int> pr2 = make_pair(INF, MAXN);
        if (l <= ind - 1)
            pr2 = min(pr2, query(l, ind - 1, segs[i]));
        if (r >= ind + 1)
            pr2 = min(pr2, query(ind + 1, r, segs[i]));
        int x2 = pr2.first;
        if (x2 != INF)
            ans = min(ans, x1 + x2);
    }
    if (ans != 2 * INF)
        return ans;
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        process(i, x);
    }
    for (int i = 0; i < m; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int ind, x;
            cin >> ind >> x;
            process(ind - 1, x);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << solve(l - 1, r - 1) << "\n";
        }
    }
    return 0;
}