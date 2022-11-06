#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;
ll n, m, k;
ll findfloor(ll up, ll i) {
	return min((ll)(up/i), m);
}
ll findpos(ll low) {
	ll K = 0;
	for (int f = 1; f <= n; ++f)
	{
		K += (findfloor(low-1, f));
	}
	return (K);
}
ll findnumberjustgreaterthanorequalto(ll j)
{
	ll res = 100000000000000000L;
	for (int i = 1; i <= n; ++i)
	{
		ll s = 1;
		ll e = m;
		while(s < e) {
			ll mid = (s+e)>>1;
			if(mid*i >= j)
				e = mid;
			else
				s = mid + 1;
		}
		if((s*i) >= j && res > (s*i)) {
			res = s*i;
		}
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	// #ifdef PIYUSH_AASHIRWAAD
	// 	I_O;
	// #endif
	cin>>n>>m>>k;
	ll s = 1;
	ll e = m*n;
	ll mid;
	ll g;
	while(s < e) {
		mid = (s + e)/2;
		if((s+e)&1)
			mid++;
		g = findpos(mid);
		if(g < k) {
			if(s == mid)
				e = mid;
			s = mid;
		}
		else {
			e = mid-1;
		}
	}
	cout<<findnumberjustgreaterthanorequalto(s);
}
/* 
1 2 3
2 4 6
*/