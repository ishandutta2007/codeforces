#define _CRT_SECURE_NO_WARNINGS
#define ll long long
#define pii pair<int, int>

#include <iostream>
#include <vector>
#include <algorithm>

const ll M = 1000000007, N = 11;

using namespace std;

ll summ(const ll& a, const ll& b)
{
	ll c = a + b;
	while (c < 0)
		c += M;
	while (c > M)
		c -= M;
	return c;
}
ll prodd(const ll& a, const ll& b)
{
	ll c = (a * b) % M;
	while (c < 0)
		c += M;
	while (c > M)
		c -= M;
	return c;
}

struct inform
{
	vector<ll> ideal;
	vector<ll> nideal;
	vector<ll> kideal;
	inform() : ideal(vector<ll>(N)), nideal(vector<ll>(N)), kideal(vector<ll>(N)) {}
};

vector<bool> not_visited;
vector<vector<int>> neighborhood;
ll m, k, mk;
int x;

inform dfs(const int& v)
{
	inform y, t, ty;
	not_visited[v] = false;
	for (int i = 0; i < N; ++i)
	{
		y.ideal[i] = 0;
		y.nideal[i] = 0;
		y.kideal[i] = 0;
	}
	y.ideal[1] = 1;
	y.nideal[0] = mk;
	y.kideal[0] = k;
	/*
	cout << "VERTEX " << v << " BEFORE ALL:";
	cout << "\nIDEAL:";
	for (int i = 0; i <= x; ++i)
		cout << ' ' << y.ideal[i];
	cout << "\nKIDEAL:";
	for (int i = 0; i <= x; ++i)
		cout << ' ' << y.kideal[i];
	cout << "\nNIDEAL:";
	for (int i = 0; i <= x; ++i)
		cout << ' ' << y.nideal[i];
	cout << "\n\n";
	*/
	for (int i = 0; i < neighborhood[v].size(); ++i)
	{
		int u = neighborhood[v][i];
		if (not_visited[u])
		{
			t = dfs(u);
			for (int z = 0; z < N; ++z)
			{
				ty.ideal[z] = 0;
				ty.nideal[z] = 0;
				ty.kideal[z] = 0;
			}
			for (int iall = 0; iall < N; ++iall)
			{
				for (int ibig = 0; ibig <= iall; ++ibig)
				{
					ty.ideal[iall] = summ(ty.ideal[iall], prodd(y.ideal[ibig], t.kideal[iall - ibig]));
					ty.kideal[iall] = summ(ty.kideal[iall], prodd(y.kideal[ibig], summ(t.kideal[iall - ibig], summ(t.nideal[iall - ibig], t.ideal[iall - ibig]))));
					ty.nideal[iall] = summ(ty.nideal[iall], prodd(y.nideal[ibig], summ(t.nideal[iall - ibig], t.kideal[iall - ibig])));
				}
			}
			y = ty;
			/*
			cout << "VERTEX " << v << " AFTER" << u << ":";
			cout << "\nIDEAL:";
			for (int i = 0; i <= x; ++i)
				cout << ' ' << y.ideal[i];
			cout << "\nKIDEAL:";
			for (int i = 0; i <= x; ++i)
				cout << ' ' << y.kideal[i];
			cout << "\nNIDEAL:";
			for (int i = 0; i <= x; ++i)
				cout << ' ' << y.nideal[i];
			cout << "\n\n";
			*/
		}
	}
	/*
	cout << "VERTEX " << v << ":";
	cout << "\nIDEAL:";
	for (int i = 0; i <= x; ++i)
		cout << ' ' << y.ideal[i];
	cout << "\nKIDEAL:";
	for (int i = 0; i <= x; ++i)
		cout << ' ' << y.kideal[i];
	cout << "\nNIDEAL:";
	for (int i = 0; i <= x; ++i)
		cout << ' ' << y.nideal[i];
	cout << "\n\n";
	*/
	return y;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("c.in", "r", stdin);
	//freopen("c.out", "w", stdout);
	int n;
	cin >> n >> m;
	vector<pii> edges(n - 1);

	not_visited = vector<bool>(n);
	neighborhood = vector<vector<int>>(n);
	for (int i = 0; i < n; ++i)
		not_visited[i] = true;

	for (int i = 0; i < n - 1; ++i)
	{
		cin >> edges[i].first >> edges[i].second;
		--edges[i].first;
		--edges[i].second;
		neighborhood[edges[i].first].push_back(edges[i].second);
		neighborhood[edges[i].second].push_back(edges[i].first);
	}
	cin >> k >> x;
	mk = m - k;
	--k;
	/*
	for (int i = 0; i < n; ++i)
	{
		cout << "NEIGHBORHOOD OF " << i << ':';
		for (int j = 0; j < neighborhood[i].size(); ++j)
			cout << ' ' << neighborhood[i][j];
		cout << '\n';
	}
	cout << '\n';

	cout << "k = " << k << "; mk = " << mk << '\n';
	*/
	inform kek = dfs(0);
	ll h = 0;
	for (int i = 0; i <= x; ++i)
		h = summ(h, summ(kek.ideal[i], summ(kek.nideal[i], kek.kideal[i])));
	cout << h << '\n';
	return 0;
}