#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    cout << max(0ll, min(min(n, m - 1), k - 2) * 3 + 3) << endl;
    return 0;
}