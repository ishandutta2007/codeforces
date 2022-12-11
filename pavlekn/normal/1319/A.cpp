#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] && !b[i])
        {
            ++cnt1;
        }
        if (!a[i] && b[i])
        {
            ++cnt2;
        }
    }
    if (cnt1 == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << (cnt2 / cnt1) + 1 << endl;
    }
    return 0;
}