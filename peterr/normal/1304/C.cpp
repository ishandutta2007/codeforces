#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
tuple<int, int, int> cust[MAXN];

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n, m;
        cin >> n >> m;
        int lo, hi;
        lo = hi = m;
        int curT = 0;
        bool ans = true;
        for (int i = 0; i < n; i++)
        {
            int t, l, h;
            cin >> t >> l >> h;
            int del = t - curT;
            int newlo = lo - del;
            int newhi = hi + del;
            lo = max(newlo, l);
            hi = min(newhi, h);
            curT = t;
            if (lo > hi)
                ans = false;
        }
        cout << (ans ? "YES" : "NO") << endl;
    }
    return 0;
}