#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 225;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int n;
        cin >> n;
        vector<char> s(2 * n - 1);
        for (int i = 0; i < 2 * n - 1; ++i)
        {
            cin >> s[i];
        }
        for (int i = 0; i < n; ++i)
        {
            cout << s[n - 1];
        }
        cout << endl;
    }
    return 0;
}