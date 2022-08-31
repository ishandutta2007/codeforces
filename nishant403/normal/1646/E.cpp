#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define S second
#define F first
#define f(i, n) for (int i = 0; i < n; i++)
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define vi vector<int>
#define pii pair<int, int>
#define all(x) x.begin(), x.end()

const int N = 1e6 + 100;
int vis[N];
int cc[21];

const int SZ = N * 21;
bool go[SZ];

void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= 20; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (go[j * i] == false)
            {
                cc[i]++;
                go[j * i] = true;
            }
        }

        cc[i] += cc[i - 1];
    }

    vis[1] = 1;
    int res = 1;

    for (int i = 2; i <= n; i++)
    {
        if (vis[i])
            continue;

        int num = i;
        int cnt = 0;

        while (num <= n)
        {
            cnt++;
            vis[num] = 1;
            num *= i;
        }

        res += cc[cnt];
    }

    cout << res << '\n';
}

signed main()
{
    fast;

    int t = 1;

    //    cin >> t;

    while (t--)

        solve();
}