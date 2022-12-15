#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int x = n;
    vector <int> p(0);
    vector <int> d(0);
    for (int i = 1; i * i <= n; i++)
    {
        if (i > 1 && x % i == 0)
        {
            p.push_back(i);
            while (x % i == 0) x /= i;
        }
        if (n % i == 0)
        {
            if (i > 1) d.push_back(i);
            if (i * i != n) d.push_back(n / i);
        }
    }
    if (x > 1) p.push_back(x);
    //=============================
    if (p.size() == 2 && p[0] * p[1] == n)
    {
        cout << p[0] << " " << p[1] << " " << n << "\n";
        cout << 1 << "\n";
        return;
    }
    //=============================
    sort(d.begin(), d.end());
    vector <int> ans(d.size(), 0);
    vector <int> flag(d.size(), 0);
    ans[(int) ans.size() - 1] = n;
    flag[(int) ans.size() - 1] = true;
    int pos = 0;
    for (int i = 0; i < p.size(); i++)
    {
        for (int id = 0; id < d.size(); id++) if (!flag[id])
        {
            int x = d[id];
            if (x % p[i] == 0)
            {
                if (i + 1 < (int) p.size())
                {
                    if (x % p[i + 1]) ans[pos++] = x, flag[id] = true;
                } else ans[pos++] = x, flag[id] = true;

            }
        }
        for (int id = 0; id < d.size(); id++) if (!flag[id])
        {
            int x = d[id];
            if (x % p[i] == 0)
            {
                ans[pos++] = x;
                flag[id] = true;
            }
        }
    }
    for (int x : ans) cout << x << " ";
    cout << "\n" << 0 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("file.inp","r",stdin);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}