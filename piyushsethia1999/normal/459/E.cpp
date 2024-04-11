#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	int n, m;
	cin >> n >> m;
	std::vector<int> res(n, 0);
	std::vector<int> res1(n, 0);
	std::vector<std::pair<int, std::pair<int, int> > > a;
	for (int i = 0; i < m; ++i)
	{
		int x, y, w;
		cin >> x >> y >> w;
		a.pb({w, {x-1, y-1}});
	}
	sort(a.rbegin(), a.rend());
	for (int i = 0; i < m; ++i)
	{
		int j = i;
		while(j < (m-1) && (a[(j+1)].first == a[i].first))
			j++;
		for (int o = i; o <= j; ++o)
			res1[a[o].second.first] = max(res1[a[o].second.first], res[a[o].second.second] + 1);
		for (int o = i; o <= j; ++o)
			res[a[o].second.first] = res1[a[o].second.first];
		i = j;
	}
	cout << *(max_element(res.begin(), res.end()));
}