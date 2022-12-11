#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    for (int _ = 0; _ < q; ++_)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            --a[i];
            b[i] = a[i];
        }
        sort(b.begin(), b.end());
        int cur = 0;
        vector<int> num(n);
        num[b[0]] = 0;
        for (int i = 1; i < n; ++i)
        {
            if (b[i] > b[i - 1])
            {
                ++cur;
            }
            num[b[i]] = cur;
        }
        for (int i = 0; i < n; ++i)
        {
            a[i] = num[a[i]];
        }
        int k = cur + 1;
        vector<int> l(k, n);
        vector<int> r(k);
        for (int i = 0; i < n; ++i)
        {
            l[a[i]] = min(l[a[i]], i);
            r[a[i]] = max(r[a[i]], i);
        }
        int ans = 0;
        int i = 0;
        while (i < k)
        {
            int j = i + 1;
            while (j < k && l[j] > r[j - 1])
            {
                ++j;
            }
            ans = max(ans, j - i);
            i = j;
        }
        cout << k - ans << endl;
    }
    return 0;
}