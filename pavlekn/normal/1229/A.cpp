#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    map<int, int> cnt;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }
    int ans = 0;
    vector<int> used(n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (a[i] == a[j])
            {
                used[i] = true;
                used[j] = true;
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (used[i] && (a[i] | a[j]) == a[i])
            {
                used[j] = true;
            }
        }
    }
    int cc = 0;
    for (int i = 0; i < n; ++i)
    {
        if (used[i])
        {
            cc += b[i];
        }
    }
    cout << cc << endl;
    return 0;
}