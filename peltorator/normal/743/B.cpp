#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


ll f(ll n, ll k)
{
    ll x = (1ll<<n);
    if (k == x)
        return n + 1;
    if (k < x)
        return f(n - 1, k);
    return f(n - 1, k - x);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    ll t = f(n, k);
    cout << t;
    return 0;
}