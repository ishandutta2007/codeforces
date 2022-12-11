#include <bits/stdc++.h>

using namespace std;

#define int long long

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
        vector<int> a(n);
        int sum = 0;
        map<int, int> cnt;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            sum += a[i];
            cnt[a[i] % 2]++;
        }
        if (cnt.size() == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}