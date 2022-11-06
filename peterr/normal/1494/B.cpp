#include <bits/stdc++.h>

using namespace std;

bool check(int n, int u, int r, int d, int l)
{
    return u >= 0 && r >= 0 && d >= 0 && l >= 0 && u <= n - 2 && r <= n - 2 && d <= n - 2 && l <= n - 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, u, r, d, l;
        cin >> n >> u >> r >> d >> l;
        bool ans = false;
        for (int i = 0; i < (1 << 4); i++)
        {
            int uu = u;
            int rr = r;
            int dd = d;
            int ll = l;
            if (i & (1 << 0))
                uu--, rr--;
            if (i & (1 << 1))
                rr--, dd--;
            if (i & (1 << 2))
                dd--, ll--;
            if (i & (1 << 3))
                ll--, uu--;
            ans = ans || check(n, uu, rr, dd, ll);
        }
        cout << (ans ? "YES" : "NO") << "\n";
    }
    return 0;
}