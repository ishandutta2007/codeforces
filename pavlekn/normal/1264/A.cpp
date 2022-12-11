#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 7;

int cnt[MAXN];

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
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            ++cnt[a[i]];
        }
        int g = cnt[a[0]];
        int s = 0;
        int ss = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            if (a[i] != a[0] && a[i] > a[i + 1] && (i + 1 - g) > g)
            {
                s = i + 1 - g;
                ss = a[i];
                break;
            }
        }
        if (s == 0)
        {
            cout << 0 << " " << 0 << " " << 0 << endl;
            for (auto el : a)
            {
                --cnt[el];
            }
            continue;
        }
        int fl = false;
        for (int i = n / 2 - 1; i >= 0; --i)
        {
            if (a[i] > a[i + 1] && a[i] < ss && i + 1 - g - s > g)
            {
                fl = true;
                cout << g << " " << s << " " << i + 1 - g - s << endl;
                break;
            }
        }
        for (auto el : a)
        {
            --cnt[el];
        }
        if (!fl)
        {
            cout << 0 << " " << 0 << " " << 0 << endl;
        }
    }
    return 0;
}