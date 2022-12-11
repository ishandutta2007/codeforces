#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        if (s2[i] == s1[i])
        {
            a[i] = 0;
        }
        else
        {
            a[i] = 1;
        }
    }
    int i = 0;
    int ans = 0;
    while (i < n - 1)
    {
        if (a[i] && a[i + 1] && s1[i] != s1[i + 1])
        {
            ++ans;
            a[i] = 0;
            a[i + 1] = 0;
            i += 2;
        }
        else if (a[i])
        {
            ++ans;
            a[i] = 0;
            ++i;
        }
        else
        {
            ++i;
        }
    }
    if (a[n - 1])
    {
        ++ans;
    }
    cout << ans << endl;
}