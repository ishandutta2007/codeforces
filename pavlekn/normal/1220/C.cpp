#include<bits/stdc++.h>

using namespace std;

#define int long long
#pragma GCC optimize("-O3")

const int MAXN = 1007;

int a[MAXN][MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    char mn = s[0] + 1;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] > mn)
        {
            cout << "Ann" << "\n";
        }
        else
        {
            mn = s[i];
            cout << "Mike" << "\n";
        }
    }
    return 0;
}