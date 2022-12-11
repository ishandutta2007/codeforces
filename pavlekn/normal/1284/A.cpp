#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    vector<string> t(m);
    for (int i = 0; i < n; ++i)
    {
        cin >> s[i];
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> t[i];
    }
    int q;
    cin >> q;
    for (int _ = 0; _ < q; ++_)
    {
        int k;
        cin >> k;
        cout << s[(k - 1) % n] << t[(k - 1) % m] << endl;
    }
    return 0;
}