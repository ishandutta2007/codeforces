#define _CRT_SECURE_NO_WARNINGS
#define sz(x) ((int)(x.size()))
#pragma comment(linker, "/STACK:66777216")
#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vei;
typedef vector<vei> vvei;

void dfs(const int& v, const vvei& g, int h, vei& razm)
{
	if (sz(razm) <= h)
		razm.resize(h + 1);
	++razm[h];
	++h;
	for (int i = 0; i < sz(g[v]); ++i)
		dfs(g[v][i], g, h, razm);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vvei g(n);
	for (int i = 1; i < n; ++i)
	{
		int t;
		cin >> t;
		g[t - 1].push_back(i);
	}
	vei r;
	dfs(0, g, 0, r);
	int ans = 0;
	for (int i = 0; i < sz(r); ++i)
		ans += r[i] & 1;
	cout << ans << '\n';
	return 0;
}