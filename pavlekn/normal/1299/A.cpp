#include<bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    int x = 0;
    vector<int> cnt(30);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        for (int j = 0; j < 30; ++j)
        {
            if (a[i] & (1 << j))
            {
                cnt[j]++;
            }
        }
    }
    int mx = 0;
    int ind = 0;
    for (int i = 0; i < n; ++i)
    {
        int cur = 0;
        for (int j = 0; j < 30; ++j)
        {
            if ((a[i] & (1 << j)) && cnt[j] == 1)
            {
                cnt[j]++;
                cur += (1 << j);
            }
        }
        if (cur > mx)
        {
            mx = cur;
            ind = i;
        }
    }
    cout << a[ind] << " ";
    for (int i = 0; i < n; ++i)
    {
        if (i != ind)
        {
            cout << a[i] << " ";
        }
    }
    return 0;
}