#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e6 + 5;

const int INF = 4e18 + 18;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, b;
    cin >> n >> b;
    int b1 = b;
    vector<pair<int, int>> a;
    int i = 2;
    while (i * i <= b1)
    {
        if (b % i == 0)
        {
            int cr = 0;
            while (b % i == 0)
            {
                ++cr;
                b /= i;
            }
            a.push_back({i, cr});
        }
        ++i;
    }
    if (b != 1)
    {
        a.push_back({b, 1});
    }
    int ans = INF;
    for (auto pr : a)
    {
        int el = pr.first;
        int res = 0;
        int cur = 1;
        while (n / el >= cur)
        {
            cur *= el;
            res += (n / cur);
        }
        ans = min(ans, res / pr.second);
    }
    cout << ans << endl;
    return 0;
}