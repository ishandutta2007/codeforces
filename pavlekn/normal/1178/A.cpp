#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> ans;
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }
    int cur = a[0];
    ans.push_back(1);
    for (int i = 0; i < n; ++i)
    {
        if (2 * a[i] <= a[0])
        {
            ans.push_back(i + 1);
            cur += a[i];
        }
    }
    if (cur > sum - cur)
    {
        cout << ans.size() << endl;
        for (auto el : ans)
        {
            cout << el << " ";
        }
    }
    else
    {
        cout << 0 << endl;
    }
    return 0;
}