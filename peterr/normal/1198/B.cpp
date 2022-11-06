#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
const int LOGN = 32 - __builtin_clz(MAXN);
const int LEN = 1 << LOGN;
int bal[MAXN];
int seg[2 * (1 << LOGN)];
int n;

void build(int i)
{
    if (i >= LEN)
    {
        seg[i] = bal[i - LEN];
    }
    else
    {
        build(i * 2);
        build(i * 2 + 1);
        seg[i] = 0;
    }
}

void prop(int i)
{
    seg[i * 2] = max(seg[i * 2], seg[i]);
    seg[i * 2 + 1] = max(seg[i * 2 + 1], seg[i]);
    seg[i] = 0;
}

int query(int i, int l, int r, int x)
{
    if (l == r)
    {
        return seg[i];
    }
    prop(i);
    int mid = (l + r) / 2;
    if (x <= mid)
    {
        return query(i * 2, l, mid, x);
    }
    else
    {
        return query(i * 2 + 1, mid + 1, r, x);
    }
}

void upd(int i, int l, int r, int x, int val)
{
    if (l == r)
    {
        seg[i] = val;
    }
    else
    {
        prop(i);
        int mid = (l + r) / 2;
        if (x <= mid)
        {
            upd(i * 2, l, mid, x, val);
        }
        else
        {
            upd(i * 2 + 1, mid + 1, r, x, val);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> bal[i];
    }
    build(1);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int num;
        cin >> num;
        if (num == 1)
        {
            int p, x;
            cin >> p >> x;
            upd(1, 0, LEN - 1, p - 1, x);
        }
        else
        {
            int x;
            cin >> x;
            seg[1] = max(seg[1], x);
        }
    }
    for (int i = 0; i < n; i++)
        cout << query(1, 0, LEN - 1, i) << " ";
    return 0;
}