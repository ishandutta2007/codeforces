#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); srand(clock());
    int n, s;
    cin >> n >> s;
    vector<int> deg(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u; --v;
        deg[u]++;
        deg[v]++;
    }
    int c = 0;
    for (int i = 0; i < n; ++i)
    {
        if (deg[i] == 1)
        {
            ++c;
        }
    }
    double ss = s;
    double cc = c;
    cout << setprecision(20) << (ss / cc) * 2 << endl;
    return 0;
}