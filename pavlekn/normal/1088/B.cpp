#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> ans;
    ans.push_back(a[0]);
    for (int i = 1; i < n; ++i)
    {
        if (a[i] - a[i - 1] != 0)
        {
            ans.push_back(a[i] - a[i - 1]);
        }
    }
    for (int i = 0; i < k; ++i)
    {
        ans.push_back(0);
    }
    for (int i = 0; i < k; ++i)
    {
        cout << ans[i] << endl;
    }
    return 0;
}