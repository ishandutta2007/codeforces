#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> l(n);
    vector<int> r(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> l[i] >> r[i];
    }
    int k;
    cin >> k;
    int ans = n;
    for (int i = 0; i < n; ++i)
    {
        if (r[i] < k)
        {
            --ans;
        }
    }
    cout << ans << endl;
    return 0;
}