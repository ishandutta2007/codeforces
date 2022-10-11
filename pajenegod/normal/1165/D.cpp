#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
    return b ? a : gcd(b, a%b);
}

ll lcm(ll a, ll b)
{
    ll g = gcd(a,b);
    return (a/g)*b;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<ll>D(n);
        for (auto &d: D)
            cin >> d;

        sort(D.begin(), D.end());

        ll x = 1;
        
        for (auto d : D)
        {
            x = lcm(x, d);
            if (x>=1000000000000LL)
                break;
        }

        if (x >= 1000000000000LL)
        {
            cout << -1 << '\n';
            continue;
        }

        x *= *min_element(D.begin(), D.end());
        
        if (x >= 1000000000000LL)
        {
            cout << -1 << '\n';
            continue;
        }

        vector<ll> smalldiv(0);
        vector<ll> bigdiv(0);
        ll div = 2;
        while (div*div < x)
        {
            if (x % div == 0)
            {
                smalldiv.push_back(div);
                bigdiv.push_back(x/div);
            }
            ++div;
        }
        
        if (div*div == x)
            smalldiv.push_back(div);

        reverse(bigdiv.begin(), bigdiv.end());
        
        smalldiv.insert(smalldiv.end(), bigdiv.begin(), bigdiv.end());
        if (D == smalldiv)
            cout << x << '\n';
        else
            cout << -1 << '\n';





    }
}