#include <bits/stdc++.h>

using namespace std;

#define int long long

int cnt[(int)1e6 + 5];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    set<int> s;
    int l = 0;
    int r = 0;
    int ans = 0;
    int ansl = 1;
    int ansr = 1;
    while (l < n)
    {
        while (r < n && s.size() <= k)
        {
            s.insert(a[r]);
            cnt[a[r]]++;
            ++r;
        }
        if (s.size() > k)
        {
            s.erase(a[r - 1]);
            cnt[a[r - 1]]--;
            --r;
        }
        if (r - l > ans)
        {
            ans = r - l;
            ansl = l + 1;
            ansr = r;
        }
        if (cnt[a[l]] == 1)
        {
            s.erase(a[l]);
        }
        --cnt[a[l]];
        ++l;
    }
    cout << ansl << " " << ansr << endl;
    return 0;
}