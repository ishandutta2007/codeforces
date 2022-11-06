#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int bit[MAXN + 1];
int prefMax[MAXN + 1];
int prefMin[MAXN + 1];
int sufMax[MAXN + 1];
int sufMin[MAXN + 1];
int a[MAXN + 1];

int query(int pos)
{
    int ans = 0;
    while (pos)
    {
        ans += bit[pos];
        pos -= pos & -pos;
    }
    return ans;
}

int query(int l, int r)
{
    return query(r) - query(l - 1);
}

void inc(int pos, int amt, int n)
{
    while (pos <= n)
    {
        bit[pos] += amt;
        pos += pos & -pos;
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
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        fill(bit, bit + n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '+')
            {
                inc(i + 1, 1, n);
                a[i + 1] = a[i] + 1;
            }
            else
            {
                inc(i + 1, -1, n);
                a[i + 1] = a[i] - 1;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            prefMin[i] = min(prefMin[i - 1], a[i]);
            prefMax[i] = max(prefMax[i - 1], a[i]);
        }
        sufMin[n] = a[n];
        sufMax[n] = a[n];
        for (int i = n - 1; i >= 1; i--)
        {
            sufMin[i] = min(sufMin[i + 1], a[i]);
            sufMax[i] = max(sufMax[i + 1], a[i]);
        }
        while (m--)
        {
            int l, r;
            cin >> l >> r;
            int between = query(l, r);
            int mx = prefMax[l - 1];
            int mn = prefMin[l - 1];
            if (r < n)
            {
                mx = max(mx, sufMax[r + 1] - between);
                mn = min(mn, sufMin[r + 1] - between);
            }
            cout << mx - mn + 1 << "\n";
        }
    }
    return 0;
}