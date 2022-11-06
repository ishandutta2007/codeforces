#include <bits/stdc++.h>

using namespace std;

const int MAXN = 18;
const int MAXLEN = 1 << MAXN;
int a[(1 << MAXN) + 1];
bool flip[MAXN + 1];
long long seg[MAXLEN * 2];

void doSwap(int k)
{
    flip[k] = !flip[k];
}

void doRev(int k)
{
    for (int i = k; i >= 1; i--)
    {
        doSwap(i);
    }
}

void upd(int pos, int ind, int newVal, int lb, int ub, int level)
{
    if (ind >= MAXLEN)
    {
        seg[ind] = newVal;
        return;
    }
    int mid = (ub + lb) / 2;
    int len = 1 << (level - 1);
    if (pos <= mid)
    {
        if (flip[level])
            upd(pos + len, ind * 2 + 1, newVal, mid + 1, ub, level - 1);
        else
            upd(pos, ind * 2, newVal, lb, mid, level - 1);
    }
    else
    {
        if (flip[level])
            upd(pos - len, ind * 2, newVal, lb, mid, level - 1);
        else
            upd(pos, ind * 2 + 1, newVal, mid + 1, ub, level - 1);
    }
    seg[ind] = seg[ind * 2] + seg[ind * 2 + 1];
}

long long query(int l, int r, int ind, int lb, int ub, int level)
{
    l = max(l, lb);
    r = min(r, ub);
    if (l > r)
        return 0;
    if (level == 0)
        return seg[ind];
    if (l > ub || r < lb)
        return 0;
    if (l == lb && r == ub)
    {
        return seg[ind];
    }
    int mid = (lb + ub) / 2;
    int len = 1 << (level - 1);
    if (l > mid)
    {
        if (flip[level])
        {
            return query(l - len, r - len, ind * 2, lb, mid, level - 1);
        }
        return query(l, r, ind * 2 + 1, mid + 1, ub, level - 1);
    }
    if (r <= mid)
    {
        if (flip[level])
        {
            return query(l + len, r + len, ind * 2 + 1, mid + 1, ub, level - 1);
        }
        return query(l, r, ind * 2, lb, mid, level - 1);
    }
    int x1 = l;
    int y1 = mid;
    int x2 = mid + 1;
    int y2 = r;
    if (flip[level])
    {
        return query(x1 + len, y1 + len, ind * 2 + 1, mid + 1, ub, level - 1) + query(x2 - len, y2 - len, ind * 2, lb, mid, level - 1);
    }
    return query(x1, y1, ind * 2, lb, mid, level - 1) + query(x2, y2, ind * 2 + 1, mid + 1, ub, level - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= (1 << n); i++)
    {
        int x;
        cin >> x;
        upd(i - 1, 1, x, 0, (1 << MAXN) - 1, MAXN);
    }
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x, k;
            cin >> x >> k;
            upd(x - 1, 1, k, 0, (1 << MAXN) - 1, MAXN);
        }
        else if (type == 2)
        {
            int k;
            cin >> k;
            doRev(k);
        }
        else if (type == 3)
        {
            int k;
            cin >> k;
            doSwap(k + 1);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << query(l, r, 1, 0, (1 << MAXN) - 1, MAXN) << "\n";
        }
    }
    return 0;
}