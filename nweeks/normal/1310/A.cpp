#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nb_cate;
	cin >> nb_cate;
	vector<pair<ll, int> > cate(nb_cate);
	for (auto &[c, t] : cate)
		cin >> c;
	for (auto &[c, t] : cate)
		cin >> t;
	sort(cate.begin(), cate.end());

	priority_queue<int> eq_elem;
	ll tot_sum(0);
	int l(0);
	ll total_cost(0);
	int lst=0;
	while (l < nb_cate or SZ(eq_elem) > 0)
	{
		while (SZ(eq_elem) > 1 and (l==nb_cate or lst < cate[l].first))
		{
			tot_sum -= eq_elem.top();
			eq_elem.pop();
			total_cost += tot_sum;
			lst++;
		}
		if (l == nb_cate) break;
		if (lst < cate[l].first)
		{
			tot_sum=0;
			while (SZ(eq_elem))
				eq_elem.pop();
		}
		int r = l;
		while (r < nb_cate and cate[r].first == cate[l].first)
		{
			eq_elem.push(cate[r].second);
			tot_sum += cate[r].second;
			++r;
		}
		lst = cate[l].first;
		l = r;
	}
	cout << total_cost << endl;
}