#pragma comment(linker, "/STACK:66777216")
#define _CRT_SECURE_NO_WARNINGS
#define sz(x) ((int)(x.size()))
#define X first
#define Y second
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vei;
typedef vector<vei> vvei;
typedef vector<bool> veb;
typedef vector<veb> vveb;

template<typename A, typename B>
istream& operator>>(istream& fin, pair<A, B>& p)
{
	fin >> p.X >> p.Y;
	return fin;
}
template<typename A>
istream& operator>>(istream& fin, vector<A>& v)
{
	int n = sz(v);
	for (int i = 0; i < n; ++i)
		fin >> v[i];
	return fin;
}

vveb is_win, is_draw;
vvei g, col, to_win;

void dfs(const int& v, const bool& nech)
{
	col[v][nech] = 1;
	bool dest = (nech == false);
	int n = sz(g[v]);
	if (n)
	{
		for (int i = 0; i < n && (is_win[v][nech] == false); ++i)
		{
			int to = g[v][i];
			if (col[to][dest] == 0)
				dfs(to, dest);
			else if (col[to][dest] == 1)
				is_draw[to][dest] = true;
			if (is_draw[to][dest])
				is_draw[v][nech] = true;
			if (is_win[to][dest] && (is_win[v][nech] == false))
			{
				is_win[v][nech] = true;
				to_win[v][nech] = to;
			}
		}
	}
	else if (nech)
	{
		is_win[v][nech] = true;
		to_win[v][nech] = -1;
	}
	col[v][nech] = 2;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	g.resize(n);
	is_win.resize(n, veb(2, false));
	is_draw.resize(n, veb(2, false));
	to_win.resize(n, vei(2, 0));
	col.resize(n, vei(2, 0));
	for (int i = 0; i < n; ++i)
	{
		int k;
		cin >> k;
		g[i].resize(k);
		cin >> g[i];
		for (int j = 0; j < k; ++j)
			--g[i][j];
	}
	int s;
	cin >> s;
	--s;
	dfs(s, false);
	if (is_win[s][0])
	{
		cout << "Win\n";
		cout << s + 1;
		bool b = false;
		while (to_win[s][b] != -1)
		{
			s = to_win[s][b];
			b = (b == false);
			cout << ' ' << s + 1;
		}
		cout << '\n';
	}
	else if (is_draw[s][0])
		cout << "Draw\n";
	else
		cout << "Lose\n";
	return 0;
}