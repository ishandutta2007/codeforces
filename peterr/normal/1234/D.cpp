#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int seg[2 * MAXN];

int query(int l, int r)
{
    l += MAXN;
    r += MAXN;
    int ans = 0;
    while (l <= r)
    {
        if (l & 1)
            ans = ans | seg[l++];
        if (!(r & 1))
            ans = ans | seg[r--];
        l >>= 1;
        r >>= 1;
    }
    return ans;
}

void upd(int pos, int val)
{
    pos += MAXN;
    seg[pos] = val;
    pos >>= 1;
    while (pos)
    {
        seg[pos] = seg[pos * 2] | seg[pos * 2 + 1];
        pos >>= 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    for (int i = 0; i < (int) s.length(); i++)
    {
        upd(i, 1 << (s[i] - 'a'));
    }
    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int pos;
            char c;
            cin >> pos >> c;
            upd(pos - 1, 1 << (c - 'a'));
        }
        else
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << __builtin_popcount(query(l, r)) << "\n";
        }
    }
    return 0;
}