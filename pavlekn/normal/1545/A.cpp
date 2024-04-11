#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
        map<int, int> A;
        map<int, int> B;
        for (int i = 0; i < n; ++i)
        {
            if (i % 2 == 0)
            {
                A[a[i]]++;
            }
            else
            {
                B[a[i]]++;
            }
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n; ++i)
        {
            if (i % 2 == 0)
            {
                A[a[i]]--;
            }
            else
            {
                B[a[i]]--;
            }
        }
        string ans = "YES";
        for (auto el : A)
        {
            if (el.second)
            {
                ans = "NO";
            }
        }
        for (auto el : B)
        {
            if (el.second)
            {
                ans = "NO";
            }
        }
        cout << ans << endl;
    }
    return 0;
}