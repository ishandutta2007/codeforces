#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3E5;
stack<int, vector<int>> a[MAXN + 1];
int b[MAXN];
int seg[MAXN * 2];

int query(int l, int r, int n)
{
    l += n;
    r += n;
    int ans = seg[l];
    while (l <= r)
    {
        if (l & 1)
            ans = max(ans, seg[l++]);
        if (!(r & 1))
            ans = max(ans, seg[r--]);
        l >>= 1;
        r >>= 1;
    }
    return ans;
}

void ch(int pos, int v, int n)
{
    pos += n;
    seg[pos] = v;
    pos >>= 1;
    while (pos)
    {
        seg[pos] = max(seg[pos * 2], seg[pos * 2 + 1]);
        pos >>= 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            while (!a[i].empty())
                a[i].pop();
        }
        fill(seg + 1, seg + 2 * n, 0);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a[x].push(i);
            ch(i, x, n);
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        bool ans = true;
        for (int i = n - 1; i >= 0; i--)
        {
            int x = b[i];
            if (a[x].empty())
            {
                ans = false;
                break;
            }
            int pos = a[x].top();
            a[x].pop();
            if (query(pos, n - 1, n) > x)
            {
                ans = false;
                break;
            }
            ch(pos, 0, n);
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}