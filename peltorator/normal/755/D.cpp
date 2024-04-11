#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>

using namespace std;

typedef long long ll;

ll q[6000000];
ll n, k;

ll tf(ll r)
{
	ll result = 0;
	for (; r >= 0; r = (r & (r+1)) - 1)
		result += q[r];
	return result;
}

void tu(ll i)
{
	for (; i < n; i = (i | (i+1)))
		q[i]++;
}
int main()
{
    cin >> n >> k;
    k = min(k, n - k);
    ll x = 0;
    ll ans = 1;
    for (ll i = 0; i < n; i++)
    {
        ll y = (x + k) % n;
        if (y > x)
            ans += tf(y - 1) - tf(x);
        else
            ans += tf(n - 1) - tf(x) + tf(y - 1);
        tu(x);
        tu(y);
        x = y;
        ans ++;
        cout << ans << " ";
    }
    return 0;
}