#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

ll solve(void);

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nb_tests;
	cin >> nb_tests;

	for (int i(0); i < nb_tests; ++i)
		solve();
}

vector<pair<int, int> > pos;

void calc(int l, int r)
{
	if (l > r) return ;
	int mid = ((l+r+1)%2 ? (l+r)/2 : (l+r-1)/2);
	pos.emplace_back(-(r-l+1), mid);
	calc(l, mid-1);
	calc(mid+1, r);	
}

ll solve(void)
{
	int n;
	cin >> n;
	pos.clear();
	calc(1, n);
	sort(pos.begin(), pos.end());
	vector<int> ans(n);
	for (int i(0); i < n; ++i)
		ans[pos[i].second-1] = i+1;
	for (auto v : ans)
		cout << v << ' ';
	cout << '\n';
	return 0;
}