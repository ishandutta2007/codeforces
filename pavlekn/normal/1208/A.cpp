#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int a, b, n;
        cin >> a >> b >> n;
        if (n % 3 == 0)
        {
            cout << a << endl;
        }
        if (n % 3 == 1)
        {
            cout << b << endl;
        }
        if (n % 3 == 2)
        {
            cout << (a ^ b) << endl;
        }
    }
}