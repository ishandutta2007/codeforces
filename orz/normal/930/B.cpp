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
#include <iomanip>
#include <algorithm>

using namespace std;
typedef vector<int> vei;
typedef vector<vei> vvei;
typedef pair<int, int> pii;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s;
	getline(cin, s);
	int n = sz(s);
	UM<char, vei> lt;
	for (int i = 0; i < n; ++i)
		lt[s[i]].push_back(i);
	int ans = 0;
	for (UM<char, vei>::iterator it = lt.begin(); it != lt.end(); ++it)
	{
		int pns = -1;
		for (int i = 1; i < n; ++i)
		{
			UM<char, int> u;
			for (int j = 0; j < sz(it->Y); ++j)
				++u[s[(it->Y[j] + i) % n]];
			int ns = 0;
			for (UM<char, int>::iterator tt = u.begin(); tt != u.end(); ++tt)
			if (tt->Y == 1)
				++ns;
			pns = max(pns, ns);
		}
		ans += pns;
	}

	cout << setprecision(30) << fixed << ((double)(ans)) / n;
	return 0;
}