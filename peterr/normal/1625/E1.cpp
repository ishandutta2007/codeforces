#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 3E5 + 5;
tuple<int, int, int> queries[MAXN];
vector<pair<int, long long>> children[MAXN];
int id[2 * MAXN];
int par[MAXN];
long long ans[MAXN];
int ind[MAXN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	string s;
	cin >> n >> q >> s;
	int mn = 0;
	int bal = 0;
	for (char ch : s)
	{
		if (ch == '(')
			bal++;
		else
			bal--;
		mn = min(bal, mn);
	}
	string new_s = "";
	for (int i = 0; i < -mn + 1; i++)
		new_s += '(';
	new_s += s;
	for (int i = 0; i < bal - mn + 1; i++)
		new_s += ')';
	s = new_s;
	n = (int) s.length();
	for (int i = 0; i < q; i++)
	{
		int t, l, r;
		cin >> t >> l >> r;
		l -= mn;
		r -= mn;
		queries[i] = {t, l, r};
	}
	vector<int> st;
	int cnt = 0;
	//cout << s << endl;
	//cout << n << endl;
	for (int i = 0; i < n; i++)
	{
		//cout << "iter " << i << endl;
		if (s[i] == '(')
		{
			id[i] = cnt;
			if (st.size())
			{
				par[id[i]] = st.back();
				ind[id[i]] = (int) children[par[id[i]]].size();
				children[par[id[i]]].push_back({i, 0});
			}
			st.push_back(cnt);
			cnt++;
		}
		else
			st.pop_back();
	}
	for (int i = cnt - 1; i >= 0; i--)
	{
		ans[i] = 1;
		for (int j = 0; j < (int) children[i].size(); j++)
		{
			pair<int, long long> child = children[i][j];
			children[i][j].second = ans[id[child.first]];
			if (j)
				children[i][j].second += children[i][j - 1].second;
			ans[i] += ans[id[child.first]];
		}
		if (children[i].size())
			ans[i] += (long long) children[i].size() * (children[i].size() - 1) / 2;
	}
	for (int i = 0; i < q; i++)
	{
		tuple<int, int, int> tup = queries[i];
		int l = get<1>(tup);
		int r = get<2>(tup);
		int v = id[l];
		int p = par[v];
		int ptr = ind[v];
		for (int jump = (int) children[p].size(); jump; jump >>= 1)
		{
			while (ptr + jump < (int) children[p].size() && children[p][ptr + jump].first <= r)
				ptr += jump;
		}
		long long res = children[p][ptr].second;
		if (ind[v])
			res -= children[p][ind[v] - 1].second;
		int len = ptr - ind[v] + 1;
		if (len)
			res += (long long) len * (len - 1) / 2;
		cout << res << "\n";
	}
	return 0;
}