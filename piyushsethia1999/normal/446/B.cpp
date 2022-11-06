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
	priority_queue<ll> pqr, pqc, klp;
	ll n, m, k, p;
	cin >> n >> m >> k >> p;
	std::vector<std::vector<ll> > grid(n, std::vector<ll>(m));
	for (ll i = 0; i < n; ++i)
	{
		for (ll j = 0; j < m; ++j)
		{
			cin >> grid[i][j];
		}
	}
	for (ll i = 0; i < n; ++i)
	{
		ll sum = 0;
		for (ll j = 0; j < m; ++j)
		{
			sum += grid[i][j];
		}
		pqr.push(sum);
	}
	for (ll j = 0; j < m; ++j)
	{
		ll sum = 0;
		for (ll i = 0; i < n; ++i)
		{
			sum += grid[i][j];
		}
		pqc.push(sum);
	}
	ll offsetrow = 0;
	ll offsetcolumn = 0;
	ll maxsum = -1000000000000000000L;
	ll temp;
	ll maxsumrow[k+1];
	maxsumrow[0] = 0;
	for (ll i = 1; i <= k; ++i)
	{
		maxsumrow[i] = maxsumrow[i-1] + pqr.top();
		pqr.push(pqr.top() - p*m);
		pqr.pop();
	}
	ll maxsumcolumn[k+1];
	maxsumcolumn[0] = 0;
	for (ll i = 1; i <= k; ++i)
	{
		maxsumcolumn[i] = maxsumcolumn[i-1] + pqc.top();
		pqc.push(pqc.top() - p*n);
		pqc.pop();		
	}
	for (ll i = 0; i <= k; ++i)
	{
		maxsum = max(maxsum, maxsumrow[i]+maxsumcolumn[k-i]-i*(k-i)*p);
	}
	cout << maxsum;
}