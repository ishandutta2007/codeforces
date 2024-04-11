#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    cout << n + 1 + n + n - 1 + min(k - 1, n - k) << endl;
    return 0;
}