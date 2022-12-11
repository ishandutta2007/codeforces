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
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        for (int i = 1; i < n; ++i)
        {
            if (a[i] <= a[i - 1])
            {
                a[i]++;
            }
        }
        set<int> s;
        for (auto el : a)
        {
            s.insert(el);
        }
        cout << s.size() << endl;
    }
    return 0;
}