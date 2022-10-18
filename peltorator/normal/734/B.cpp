#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define For(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll k2, k3, k5, k6;
    cin >> k2 >> k3 >> k5 >> k6;
    cout << 256 * min(k2, min(k5, k6)) + 32 * min(k2 - min(k2, min(k5, k6)), k3);
    return 0;
}