#include <bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define mp make_pair

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_HOME
		I_O;
	#else
	#define print(...) 0
	#endif
	int n; cin >> n;
	std::vector<int> sc[4];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			int t; cin >> t;
			sc[j].pb(t);
		}
	}
	int rank = 1;
	int to = sc[0][0] + sc[1][0] + sc[2][0] + sc[3][0];
	for (int i = 1; i < n; ++i)
	{
		int total = 0;
		for (int j = 0; j < 4; ++j)
		{
			total += sc[j][i];
		}
		if(total > to)
			rank++;
	}
	cout << rank;
}