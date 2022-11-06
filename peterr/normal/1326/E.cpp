#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3E5;
const int LEN = 1 << 19;
const int SEGLEN = 1 << 20;
int seg[SEGLEN];
int lz[SEGLEN];
int loc[MAXN + 1];
int q[MAXN];
int ans[MAXN];

void prop(int pos)
{
    seg[pos] += lz[pos];
    if (pos * 2 < SEGLEN)
    {
        lz[pos * 2] += lz[pos];
        lz[pos * 2 + 1] += lz[pos];
    }
    lz[pos] = 0;
}

void inc(int pos, int lb, int rb, int l, int r, int amt)
{
    if (l > rb || r < lb)
        return;
    if (lb >= l && rb <= r)
        lz[pos] += amt;
    else
    {
        int mid = (lb + rb) / 2;
        inc(pos * 2, lb, mid, l, r, amt);
        inc(pos * 2 + 1, mid + 1, rb, l, r, amt);
        prop(pos * 2);
        prop(pos * 2 + 1);
        seg[pos] = min(seg[pos * 2], seg[pos * 2 + 1]);
    }
}

int query(int pos, int lb, int rb, int l, int r)
{
    if (l > rb || r < lb)
        return MAXN + 7;
    prop(pos);
    if (lb >= l && rb <= r)
        return seg[pos];
    int mid = (lb + rb) / 2;
    return min(query(pos * 2, lb, mid, l, r), query(pos * 2 + 1, mid + 1, rb, l, r));

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        loc[x] = i + 1;
    }
    for (int i = 0; i < n; i++)
        cin >> q[i];
    int cur = n;
    ans[0] = n;
    inc(1, 0, LEN - 1, 1, loc[n], -1);
    for (int i = 1; i < n; i++)
    {
        inc(1, 0, LEN - 1, 1, q[i - 1], 1);
        while (query(1, 0, LEN - 1, 1, n) >= 0)
        {
            cur--;
            inc(1, 0, LEN - 1, 1, loc[cur], -1);
        }
        ans[i] = cur;
    }
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}