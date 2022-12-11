#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); srand(clock());
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        if (n % i == 0 && n / i < k)
        {
            cout << i * k + n / i;
            return 0;
        }
    }
    return 0;
}