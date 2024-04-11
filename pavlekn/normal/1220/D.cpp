#include<bits/stdc++.h>

using namespace std;

#define int long long
#pragma GCC optimize("-O3")

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        int m = a[i];
        while (m % 2 == 0)
        {
            ++cnt[i];
            m /= 2;
        }
    }
    vector<int> c(65);
    for (int i = 0; i < n; ++i)
    {
        c[cnt[i]]++;
    }
    int ans = 0;
    int ind = 0;
    for (int i = 0; i < 65; ++i)
    {
        if (c[i] > ans)
        {
            ans = c[i];
            ind = i;
        }
    }
    cout << n - ans << endl;
    for (int i = 0; i < n; ++i)
    {
        if (cnt[i] != ind)
        {
            cout << a[i] << " ";
        }
    }
    cout << endl;
    return 0;
}