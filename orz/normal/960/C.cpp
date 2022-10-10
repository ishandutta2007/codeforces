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
#include <set>
#include <iomanip>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef vector<int> vei;
typedef vector<ll> vel;
typedef vector<vei> vvei;
typedef pair<int, int> pii;
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

const int C = 31;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int x;
	ll d;
	cin >> x >> d;
	vei sd(C);
	for (int i = 1; i < C; ++i)
		sd[i] = (1 | (sd[i - 1] << 1));
	vei k;
	int h = C - 1;
	while (x)
	{
		while (sd[h] > x)
			--h;
		k.push_back(h);
		x -= sd[h];
	}
	vel ans;
	for (int i = 0; i < sz(k); ++i)
	{
		ll e = d * i + 1;
		for (int j = 0; j < k[i]; ++j)
			ans.push_back(e);
	}
	cout << sz(ans) << '\n';
	for (int i = 0; i < sz(ans); ++i)
		cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}