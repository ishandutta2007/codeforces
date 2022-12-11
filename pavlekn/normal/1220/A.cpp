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
    int cnt1 = 0;
    int cnt2 = 0;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'n')
        {
            ++cnt1;
        }
        if (s[i] == 'r')
        {
            ++cnt2;
        }
    }
    for (int i = 0; i < cnt1; ++i)
    {
        cout << 1 << " ";
    }
    for (int i = 0; i < cnt2; ++i)
    {
        cout << 0 << " ";
    }
    return 0;
}