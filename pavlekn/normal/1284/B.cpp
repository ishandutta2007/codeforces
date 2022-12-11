#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int cnt = 0;
    vector<int> l;
    vector<int> r;
    for (int _ = 0; _ < n; ++_)
    {
        int k;
        cin >> k;
        vector<int> a(k);
        for (int i = 0; i < k; ++i)
        {
            cin >> a[i];
        }
        int fl = false;
        for (int i = 1; i < k; ++i)
        {
            if (a[i - 1] < a[i])
            {
                fl = true;
                break;
            }
        }
        if (fl)
        {
            ++cnt;
        }
        else
        {
            r.push_back(a[0]);
            l.push_back(a[k - 1]);
        }
    }
    int ans = 0;
    ans += cnt * n * 2 - cnt * cnt;
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    for (auto el : r)
    {
        ans += (lower_bound(l.begin(), l.end(), el) - l.begin());
    }
    cout << ans << endl;
    return 0;
}