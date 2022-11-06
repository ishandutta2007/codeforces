#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

ll *v;
ll *v1;
ll *v2;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	v = new ll[8000001];
	v1 = new ll[8000001];
	v2 = new ll[8000001];
	ll r, b;
	cin>>r>>b;
	ll h = sqrt(2*(r+b));
	if(((h*(h+1))/2) > (r+b))
		h--;
	ll max = 0;
	v[0] = 1;
	for (ll i = 1; i <= h ; ++i)
	{
		for (ll j = 0; j <= max; ++j)
		{
			v1[j] += v[j];
			if(v1[j] >= 1000000007)
				v1[j] -= 1000000007;
			v1[i+j] += v[j];
			if(v1[j+i] >= 1000000007)
				v1[i+j] -= 1000000007;
		}
		v2 = v1;
		v1 = v;
		v = v2;
		max += i;
		for (int i = 0; i <= max; ++i)
		{
			v1[i] = 0;
		}
	}
	ll f = r+b-(h*(h+1))/2;
	f = min(r, min(b, f));
	ll sum = 0;
	r = min(b, r);
	for (ll i = 0; i <= f; ++i)
	{
		sum += v[r-i];
		if(sum >= 1000000007)
			sum -= 1000000007;
	}
	cout<<sum;
}