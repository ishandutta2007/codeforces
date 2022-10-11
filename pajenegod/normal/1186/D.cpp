#include <bits/stdc++.h>

using ll = long long;
using namespace std;

ll go_up(ll x)
{
    int sign = 2 * (x > 0) - 1;
    return sign * 100000 * (((x*sign) + 99999)/100000);
}

ll go_down(ll x)
{
    int sign = 2 * (x > 0) - 1;
    return sign * 100000 * ((x*sign)/100000);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<ll> A(n);
    for (auto &a : A)
    {
        double ad;
        cin >> ad;
        a = round(ad * 1e5);
    }


    ll upper = 0;
    ll lower = 0;
    for (auto a : A)
    {
        if (a > 0)
            upper += go_down(a);
        else
            lower += go_down(-a);
    }
    ll ups = max(lower - upper, 0LL) / 100000;
    ll downs = max(upper - lower, 0LL) / 100000;

    vector<ll> B;
    for (auto a : A)
    {
        if (a % 100000 == 0)
            B.push_back(a / 100000);
        else if (a > 0)
        {
            if (ups > 0)
            {
                B.push_back(go_up(a) / 100000);
                --ups;
            } else
                B.push_back(go_down(a) / 100000);
        } else
        {
            if (downs > 0)
            {
                B.push_back(-go_up(-a) / 100000);
                --downs;
            } else
                B.push_back(-go_down(-a) / 100000);
        }
    }

        
    for (auto b : B)
        cout << b << '\n';
}