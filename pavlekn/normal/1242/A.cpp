#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int m = 0;
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            m = i;
            break;
        }
    }
    if (m == 0)
    {
        cout << n << endl;
        return 0;
    }
    while (n % m == 0)
    {
        n /= m;
    }
    if (n != 1)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << m << endl;
    }
    return 0;
}