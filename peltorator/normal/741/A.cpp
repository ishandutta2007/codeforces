#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


ll nod(ll a, ll b)
{
    return a ? nod(b % a, a) : b;
}

ll nok(ll a, ll b)
{
    return a / nod(a, b) * b;
}

vector<ll> a, b, l, used;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    a.resize(n);
    b.resize(n, -1);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
        b[a[i]] = i;
    }
    for (ll i = 0; i < n; i++)
        if (b[i] == -1)
        {
            cout << -1;
            return 0;
        }
    used.resize(n, 0);
    ll t = 1;
    for (ll i = 0; i < n; i++)
    {
        if  (!used[i])
        {
            ll v = i;
            ll cur = 0;
            while (used[v] == 0)
            {
                cur++;
                used[v] = 1;
                v = a[v];
            }
            if (cur % 2 == 0)
                cur /= 2;
            t = nok(t, cur);
        }
    }
    cout << t;
	return 0;
}