#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
	ll n;
	cin >> n;
	ll **graph;
	ll **adjmatrix;
	adjmatrix = new ll*[n];
	graph = new ll*[n];
	for (ll i = 0; i < n; ++i)
	{
		adjmatrix[i] = new ll[n];
		graph[i] = new ll[n];
	}
	for (ll i = 0; i < n; ++i)
	{
		for (ll j = 0; j < n; ++j)
		{
			cin>>adjmatrix[i][j];
			graph[i][j] = adjmatrix[i][j];
		}
	}
	std::vector<ll> v(n);
	for (ll i = 0; i < n; ++i)
	{
		cin>>v[n-i-1];
		v[n-i-1]--;
	}
	std::vector<ll> ans(n);
	for (ll k = 0; k < n; ++k)
	{
		for (ll i = 0; i < n; ++i)
		{
			for (ll j = 0; j < n; ++j)
			{
				graph[i][j] = min(graph[i][j], graph[i][v[k]] + graph[v[k]][j]);
			}
		}
		ll sum = 0;
		for (ll i = 0; i <= k; ++i)
		{
			for (ll j = 0; j <= k; ++j)
			{
				sum += graph[v[i]][v[j]];
			}
		}
		ans[n - k - 1] = sum;
	}
	for (ll i = 0; i < n; ++i)
	{
		cout<<ans[i]<<" ";
	}
}