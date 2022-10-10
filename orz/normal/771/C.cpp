#pragma comment(linker, "/STACK:66777216")
#define ll long long
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> neighbors, a, b, sver;
vector<vector<int>> neighborhood;
vector<vector<ll>> pairss;
vector<ll> ssum, sdis;
vector<vector<int>> ver;
vector<bool> nvis;

void dfs(const int& v)
{
	int prnt = -1;
	nvis[v] = false;
	pairss[v].resize(k);
	ver[v].resize(k);
	sver[v] = 0;
	sdis[v] = 0;
	ssum[v] = 0;
	for (int j = 0; j < k; ++j)
	{
		ver[v][j] = 0;
		pairss[v][j] = 0;
	}
	for (int i = 0; i < neighbors[v]; ++i)
	{
		if (nvis[neighborhood[v][i]])
		{
			dfs(neighborhood[v][i]);
			sver[v] += sver[neighborhood[v][i]];
			for (int j = 0; j < k; ++j)
			{
				ver[v][(j + 1) % k] += ver[neighborhood[v][i]][j];
				pairss[v][j] += pairss[neighborhood[v][i]][j];
				pairss[v][(j + 1) % k] += ver[neighborhood[v][i]][j];
			}
			sdis[v] += sdis[neighborhood[v][i]] + sver[neighborhood[v][i]];
			ssum[v] += ssum[neighborhood[v][i]] + sdis[neighborhood[v][i]] + sver[neighborhood[v][i]];

		}
		else
			prnt = neighborhood[v][i];
	}
	vector<ll> adding(k);
	for (int j = 0; j < k; ++j)
		adding[j] = 0;
	for (int i = 0; i < neighbors[v]; ++i)
	{
		if (neighborhood[v][i] != prnt)
		{
			ssum[v] += (sdis[neighborhood[v][i]] + sver[neighborhood[v][i]]) * (sver[v] - sver[neighborhood[v][i]]);
			for (int j = 0; j < k; ++j)
			{
				for (int jj = 0; jj < k; ++jj)
				{
					adding[(j + jj + 2) % k] += static_cast<ll>(ver[neighborhood[v][i]][j]) * (ver[v][(jj + 1) % k] - ver[neighborhood[v][i]][jj]);
				}
			}
		}
	}
	for (int j = 0; j < k; ++j)
		pairss[v][j] += adding[j] / 2;
	++ver[v][0];
	++sver[v];
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> k;
	a.resize(n);
	b.resize(n);
	neighbors.resize(n);
	nvis.resize(n);
	pairss.resize(n);
	ver.resize(n);
	sver.resize(n);
	ssum.resize(n);
	sdis.resize(n);
	for (int i = 0; i < n; ++i)
	{
		neighbors[i] = 0;
		nvis[i] = true;
	}
	for (int i = 1; i < n; ++i)
	{
		cin >> a[i] >> b[i];
		--a[i];
		--b[i];
		++neighbors[a[i]];
		++neighbors[b[i]];
	}
	neighborhood.resize(n);
	for (int i = 0; i < n; ++i)
	{
		neighborhood[i].resize(neighbors[i]);
		neighbors[i] = 0;
	}
	for (int i = 1; i < n; ++i)
	{
		neighborhood[a[i]][neighbors[a[i]]++] = b[i];
		neighborhood[b[i]][neighbors[b[i]]++] = a[i];
	}
	dfs(0);
	ll ans = ssum[0];
	for (int i = 1; i < k; ++i)
		ans += (k - i) * pairss[0][i];
	cout << ans / k << endl;
	return 0;
}