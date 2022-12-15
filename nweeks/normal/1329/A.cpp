#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n,m;
	cin >> n >> m;
	vector<pair<int, int> > l(m);
	for (int i(0); i < m; ++i)
	{
		cin >> l[i].first;
		l[i].second = i;
	}
	
	ll sum(0);
	for (auto v : l)
		sum += v.first;

	if (sum < n)
	{
		cout << "-1" << endl;
		return 0;
	}
	vector<int> p(m);
	int lst_total_cover(0);

	for (int i(m-1); i >= 0; --i)
	{
		if (lst_total_cover == n)
		{
			cout << -1 << endl;
			return 0;
		}
		p[i] = max({1ll, lst_total_cover + 2LL - l[i].first, n - (sum-1)});
		if (p[i] > n-l[i].first + 1)
		{
			cout << -1 << endl;
			return 0;
		}
		lst_total_cover = p[i] + l[i].first - 1;
		sum -= l[i].first;
	}
	for (auto pp : p)
		cout << pp << ' ';
	cout << endl;
}