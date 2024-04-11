#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    int n, l, r;
    cin >> n >> l >> r;
    int suml = 0;
    int sumr = 0;
    for (int i = 0; i < l; ++i)
    {
        suml += (1 << i);
    }
    for (int i = 0; i < r; ++i)
    {
        sumr += (1 << i);
    }
    suml += (n - l);
    sumr += (1 << (r - 1)) * (n - r);
    cout << suml << " " << sumr << endl;
    return 0;
}