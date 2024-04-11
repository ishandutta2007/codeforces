#define _CRT_SECURE_NO_WARNINGS
#define sz(x) ((int)(x.size()))
#define X first
#define Y second
#define UM unordered_map
#pragma comment(linker, "/STACK:66777216")
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef vector<int> vei;
typedef vector<ll> vel;
typedef vector<vei> vvei;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;
typedef vector<ppiii> vppiii;
typedef vector<pii> vpii;

template<typename A>
istream& operator>>(istream& fin, vector<A>& v)
{
	int n = sz(v);
	for (int i = 0; i < n; ++i)
		fin >> v[i];
	return fin;
}
template<typename A, typename B>
istream& operator>>(istream& fin, pair<A, B>& v)
{
	fin >> v.X >> v.Y;
	return fin;
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
	vppiii e(m);
	cin >> e;
	vector<map<int, int>> ans(n);
	int a = 0;
	for (int i = 0; i < m; ++i)
	{
		int u = e[i].X.X - 1, v = e[i].X.Y - 1, w = e[i].Y;
		auto bad_auto = ans[u].lower_bound(w);
		int l = 1 + ((bad_auto == ans[u].begin()) ? 0 : (--bad_auto)->Y);
		bool t = true;
		while (t)
		{
			auto place_to = ans[v].lower_bound(w);
			if (place_to == ans[v].end())
				t = false;
			else if (place_to->Y < l)
				ans[v].erase(place_to);
			else
				t = false;
		}
		auto place_to = ans[v].lower_bound(w);
		if (place_to == ans[v].begin())
			ans[v][w] = l;
		else
		{
			--place_to;
			if (place_to->Y < l)
				ans[v][w] = l;
		}
		a = max(a, l);
	}
	cout << a << '\n';
	return 0;
}