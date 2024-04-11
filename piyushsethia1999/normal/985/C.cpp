#include<bits/stdc++.h>
#define ll long long int

using namespace std;
int main()
{
	ll n, k, l;
	cin>>n>>k>>l;
	ll m = n*k;
	std::vector<ll> v(m);
	for (ll i = 0; i < m; ++i)
	{
		cin>>v[i];
	}
	sort(v.begin(), v.end());
	ll maxv = l+v[0];
	ll count = upper_bound(v.begin(), v.end(), maxv) - v.begin();
	if(count >= n) {
		int rem = count - n;
		ll totalvol = v[0];
		int i = 0;
		while(rem >= k) {
			rem -= (k-1);
			i += k;
			totalvol += (v[i]);
		}
		i += (rem + 1);
		for(; i < count; i++)
		{
			totalvol += v[i];
		}
		cout<<totalvol;
	}
	else {
		cout<<"0";
	}
}