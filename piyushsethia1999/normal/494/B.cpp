#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	ll mod = 1000000007;
	string s, t;
	cin >> s >> t;
	ll l1 = t.size();
	string str = t + '$' + s;
	ll n = str.size();
	std::vector<ll> lps(n);
	lps[0] = 0;
	for (int i = 1; i < n; ++i)
	{
		ll tlps = lps[i-1];
		while(tlps > 0 && str[tlps] != str[i])
			tlps = lps[tlps-1];
		if(str[tlps] == str[i]) tlps++;
		lps[i] = tlps;
	}
	std::vector<ll> a(n, 0);
	std::vector<ll> q1(n, 0);
	std::vector<ll> q2(n, 0);
	for (int i = l1 + 1; i < n; ++i)
	{
		print(i - l1 - 1, lps[i]);
		if (lps[i] == l1)
		{
			a[i] = (q2[i-l1] + i - 2 * l1 + 1) % mod;
			q1[i] = (q1[i-1] + a[i]) % mod;
			q2[i] = (q2[i-1] + q1[i]) % mod;
		}
		else
		{
			a[i] = a[i-1];
			q1[i] = (q1[i-1] + a[i]) % mod;
			q2[i] = (q2[i-1] + q1[i]) % mod;
		}
	}
	cout<<q1[n-1];
	print(lps);
	print(a);
	print(q1);
	print(q2);
	print(lps);
}