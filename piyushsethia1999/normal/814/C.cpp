#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
#ifdef PIYUSH_HOME
	I_O;
#else
#define print(...) 0
#endif
	int n; cin >> n;
	string s; cin >> s;
	int size = s.size();
	std::vector<std::vector<int> > grid(26, std::vector<int>(size + 1, 0));
	for (int j = 0; j < 26; ++j)
	{
		char ch = 'a' + j;
		// cout << ch << "\n";
		for (int siz = 1; siz <= size; ++siz)
		{
			int cnt = 0;
			for (int i = 0; i < siz; ++i)
				if (s[i] != ch)
					cnt++;
			int ma = cnt;
			for (int i = 1; i <= (size - siz); ++i)
			{
				if (s[i - 1] != ch)
					cnt--;
				if (s[i + siz - 1] != ch)
					cnt++;
				ma = min(cnt, ma);
			}
			grid[j][siz] = ma;
		}
	}
	// print(grid['o' - 'a']);
	int q; cin >> q;
	for (int i = 0; i < q; ++i)
	{
		int m; cin >> m;
		char C; cin >> C;
		int c = C - 'a';
		cout << (upper_bound(grid[c].begin(), grid[c].end(), m) - grid[c].begin() - 1) << "\n";
	}
}