#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

const int MAXN = 2e3 + 7;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); srand(clock());
    string s;
    cin >> s;
    int n = s.size();
    int x = (n + 19) / 20;
    int y = (n + x - 1) / x;
    cout << x << " " << y << endl;
    int k = 0;
    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            if (n % y != 0 && i >= (n % x) && j + 1 == y)
            {
                cout << '*';
            }
            else
            {
                cout << s[k];
                ++k;
            }
        }
        cout << endl;
    }
    return 0;
}