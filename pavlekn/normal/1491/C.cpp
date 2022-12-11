#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 5e3 + 7;

int a[MAXN];
int add[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            add[i] = 0;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            ans += max(a[i] - 1 - add[i], 0LL);
            if (add[i] > a[i] - 1)
            {
                add[i + 1] += add[i] - (a[i] - 1);
            }
            for (int j = i + 2; j < n && j <= i + a[i]; ++j)
            {
                ++add[j];
            }
        }
        cout << ans << endl;
    }
    return 0;
}