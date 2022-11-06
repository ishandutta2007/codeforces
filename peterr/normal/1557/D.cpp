#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 3E5;
const int LOG = 20;
const int LEN = 1 << LOG;
pair<int, int> seg[2 * LEN];
pair<int, int> lz[2 * LEN];
vector<pair<int, int>> a[MAXN + 1];
map<int, int> mp;
set<int> nums;
int ans[MAXN + 1];
int from[MAXN + 1];

void prop(int ind)
{
	if (ind >= LEN)
		return;
	lz[ind * 2] = max(lz[ind * 2], lz[ind]);
	lz[ind * 2 + 1] = max(lz[ind * 2 + 1], lz[ind]);
	seg[ind * 2] = max(seg[ind * 2], lz[ind]);
	seg[ind * 2 + 1] = max(seg[ind * 2 + 1], lz[ind]);
	lz[ind] = {0, -1};
}

pair<int, int> query(int l, int r, int ind=1, int lb=0, int ub=LEN)
{
	prop(ind);
	if (ub <= l || lb >= r)
		return {0, -1};
	if (lb >= l && ub <= r)
		return seg[ind];
	int mid = (lb + ub) / 2;
	pair<int, int> pr1 = query(l, r, ind * 2, lb, mid);
	pair<int, int> pr2 = query(l, r, ind * 2 + 1, mid, ub);
	return max(pr1, pr2);
}

void op(int l, int r, pair<int, int> pr, int ind=1, int lb=0, int ub=LEN)
{
	prop(ind);
	if (ub <= l || lb >= r)
		return; 
	if (lb >= l && ub <= r)
	{
		seg[ind] = max(seg[ind], pr);
		lz[ind] = max(lz[ind], pr);
		return;
	}
	int mid = (lb + ub) / 2;
	op(l, r, pr, ind * 2, lb, mid);
	op(l, r, pr, ind * 2 + 1, mid, ub);
	seg[ind] = max(seg[ind], seg[ind * 2]);
	seg[ind] = max(seg[ind], seg[ind * 2 + 1]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int ind, l, r;
		cin >> ind >> l >> r;
		a[ind].push_back({l, r});
		nums.insert(l);
		nums.insert(r);
	}
	for (int x : nums)
	{
		mp[x] = (int) mp.size();
	}
	for (int i = 1; i <= n; i++)
	{
		for (pair<int, int>& pr : a[i])
		{
			pr.first = mp[pr.first];
			pr.second = mp[pr.second];
		}
	}
	int best = 1;
	int when = 1;
	for (int i = 1; i <= n; i++)
	{
		ans[i] = 1;
		for (pair<int, int> pr : a[i])
		{
			pair<int, int> q = query(pr.first, pr.second + 1);
			//cout << "found " << q.first << " " << q.second << endl;
			if (q.first >= ans[i])
			{
				ans[i] = q.first + 1;
				from[i] = q.second;
			}
		}
		for (pair<int, int> pr : a[i])
		{
			op(pr.first, pr.second + 1, {ans[i], i});
		}
		//cout << "ans " << i << " = " << ans[i] << endl;
		if (ans[i] > best)
		{
			best = ans[i];
			when = i;
		}
	}
	set<int> good;
	while (when)
	{
		good.insert(when);
		when = from[when];
	}
	set<int> erased;
	for (int i = 1; i <= n; i++)
	{
		if (!good.count(i))
			erased.insert(i);
	}
	cout << erased.size() << "\n";
	for (int x : erased)
		cout << x << " ";
	cout << "\n";
	return 0;
}