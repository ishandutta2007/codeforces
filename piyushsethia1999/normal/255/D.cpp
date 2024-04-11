#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

ll sum(ll n)
{
	if(n <= 0l)
		return 0l;
	return ((n*(n+1l))/2l);
}

ll l2(ll h, ll b1, ll b2)
{
	if(h <= 0)
		return 0;
	return (h + 2*sum(h-1) - sum(h-b1-1) - sum(h-b2-1));
}

ll l1(ll h)
{
	if(h <= 0)
		return 0l;
	return (h*h);
}

ll getres(ll n, ll x, ll y, ll t)
{
	ll b1 = n-x;
	ll b2 = x-1;
	return (2l*(t+1)*t + 1l - l1(x+t-n) - l1(t-(x-1l)) - l2(y+t-n, b1, b2) - l2(t-(y-1l), b1, b2));
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	ll n, x, c, y;
	cin >> n >> x >> y >> c;
	ll st = 0;
	ll en = 50000;
	while(st < en)
	{
		ll mid = (st+en)/2l;
		if(getres(n, x, y, mid) < c)
			st = mid + 1;
		else
			en = mid;
	}
	cout << st;
}