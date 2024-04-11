#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 3E5 + 5;
tuple<int, int, int> queries[MAXN];
vector<int> children[MAXN];
int numChildren[MAXN];
int id[2 * MAXN];
int par[MAXN];
int ind[MAXN];
long long bit[MAXN];
int deleted_bit[MAXN];
int last[MAXN];

void upd(int pos, long long amt)
{
	if (!pos)
	{
		bit[pos] += amt;
		return;
	}
	while (pos < MAXN)
	{
		bit[pos] += amt;
		pos += pos & -pos;
	}
}

long long query(int pos)
{
	if (pos < 0)
		return 0;
	long long ans = bit[0];
	while (pos)
	{
		ans += bit[pos];
		pos -= pos & -pos;
	}
	return ans;
}

long long query(int l, int r)
{
	return query(r) - query(l - 1);
}

void upd2(int pos, int amt)
{
	if (!pos)
	{
		deleted_bit[pos] += amt;
		return;
	}
	while (pos < MAXN)
	{
		deleted_bit[pos] += amt;
		pos += pos & -pos;
	}
}

int query2(int pos)
{
	if (pos < 0)
		return 0;
	int ans = deleted_bit[0];
	while (pos)
	{
		ans += deleted_bit[pos];
		pos -= pos & -pos;
	}
	return ans;
}

int query2(int l, int r)
{
	return query2(r) - query2(l - 1);
}

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
				children[par[id[i]]].push_back(i);
			}
			st.push_back(cnt);
			cnt++;
		}
		else
			st.pop_back();
	}
	for (int i = cnt - 1; i >= 0; i--)
	{
		last[i] = i;
		for (int j = 0; j < (int) children[i].size(); j++)
		{
			int child = children[i][j];
			last[i] = max(last[i], last[id[child]]);
		}
		numChildren[i] = (int) children[i].size();
		long long ways = 1;
		if (children[i].size())
			ways += (long long) children[i].size() * (children[i].size() - 1) / 2;
		upd(i, ways);
	}
	for (int i = 0; i < q; i++)
	{
		tuple<int, int, int> tup = queries[i];
		int t = get<0>(tup);
		int l = get<1>(tup);
		int r = get<2>(tup);
		int v = id[l];
		int p = par[v];
		if (t == 1)
		{
			upd(v, -1);
			numChildren[p]--;
			upd(p, -numChildren[p]);
			upd2(v, 1);
			upd2(p, -1);
		}
		else
		{
			int ptr = ind[v];
			for (int jump = (int) children[p].size(); jump; jump >>= 1)
			{
				while (ptr + jump < (int) children[p].size() && children[p][ptr + jump] <= r)
					ptr += jump;
			}
			long long res = query(v, last[id[children[p][ptr]]]);
			int num_deleted = query2(v, last[id[children[p][ptr]]]);
			int len = ptr - ind[v] + 1 - num_deleted;
			if (len)
				res += (long long) len * (len - 1) / 2;
			cout << res << "\n";
		}
	}
	return 0;
}