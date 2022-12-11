#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e9;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    vector<int> l(n, INF);
    vector<int> r(n, -1);
    for (int i = 0; i < k; ++i)
    {
        cin >> a[i];
        --a[i];
        l[a[i]] = min(l[a[i]], i);
        r[a[i]] = max(r[a[i]], i);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (r[i] == -1)
        {
            ++ans;
        }
        if (i != 0 && r[i - 1] < l[i])
        {
            ++ans;
        }
        if (i != n - 1 && r[i + 1] < l[i])
        {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}