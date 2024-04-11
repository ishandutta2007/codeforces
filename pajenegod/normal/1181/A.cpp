#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main()
{
    ll x,y,z;
    cin >> x >> y >> z;
    
    ll total = (x+y)/z;

    cout << total << " ";

    total -= x/z;
    total -= y/z;

    x %= z;
    y %= z;

    if (total > 0)
    {
        ll a = min(x,y);
        ll b = min(z-x, z-y);
        cout << min(a,b);
    }
    else
        cout << 0;
}