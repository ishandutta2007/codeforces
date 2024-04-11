#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = 0;
    int ind = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] > mx)
        {
            mx = a[i];
            ind = i;
        }
    }
    string ans = "YES";
    for (int i = 0; i < ind - 1; ++i)
    {
        if (a[i] > a[i + 1])
        {
            ans = "NO";
        }
    }
    for (int i = ind; i < n - 1; ++i)
    {
        if (a[i] < a[i + 1])
        {
            ans = "NO";
        }
    }
    cout << ans << endl;
    return 0;
}