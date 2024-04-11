#include<bits/stdc++.h>

using namespace std;

#define int long long
#pragma GCC optimize("-O3")

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    for (int ii = 0; ii < q; ++ii)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        vector<int> used(2049, false);
        used[0] = true;
        for (int i = 0; i < n; ++i)
        {
            vector<int> cur;
            for (int j = 0; j < 2049; ++j)
            {
                if (used[j] && j + a[i] <= 2048)
                {
                    cur.push_back(j + a[i]);
                }
            }
            for (auto el : cur)
            {
                used[el] = true;
            }
        }
        if (used[2048])
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