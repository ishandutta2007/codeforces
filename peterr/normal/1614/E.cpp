#include <bits/stdc++.h>

using namespace std;

const int INF = 2E9;

struct Node
{
	Node *lt, *rt;
	int val, lz, lb, ub;
	
	Node(int val, int lb, int ub) : lt(nullptr), rt(nullptr), val(val), lz(0), lb(lb), ub(ub)
	{
	}
	
	void prop()
	{
		if (!lt)
		{
			int mid = (lb + ub) / 2;
			lt = new Node(mid, lb, mid);
			rt = new Node(ub, mid + 1, ub);
		}
		lt->val += lz;
		lt->lz += lz;
		rt->val += lz;
		rt->lz += lz;
		lz = 0;
	}
	
	int query(int lo, int hi)
	{
		if (lb > hi || ub < lo)
			return -1;
		if (lo <= lb && hi >= ub)
			return val;
		prop();
		return max(lt->query(lo, hi), rt->query(lo, hi));
	}
	
	void add(int lo, int hi, int amt)
	{
		if (lb > hi || ub < lo)
			return;
		if (lo <= lb && hi >= ub)
		{
			lz += amt;
			val += amt;
			return;
		}
		prop();
		lt->add(lo, hi, amt);
		rt->add(lo, hi, amt);
		val = max(lt->val, rt->val);
	}
	
	int lower_bound(int x)
	{
		if (val < x)
			return INF;
		if (lb == ub)
			return lb;
		prop();
		if (lt->val >= x)
			return lt->lower_bound(x);
		return rt->lower_bound(x);
	}
	
	int upper_bound(int x)
	{
		if (val <= x)
			return INF;
		if (lb == ub)
			return lb;
		prop();
		if (lt->val > x)
			return lt->upper_bound(x);
		return rt->upper_bound(x);
	}
};

const int MOD = 1E9;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int last_ans = 0;
	Node root(MOD, 0, MOD);
	while (n--)
	{
		int t, k;
		cin >> t >> k;
		int lb = root.lower_bound(t);
		int ub = root.upper_bound(t);
		if (ub != INF)
		{
			root.add(ub, MOD, -1);
		}
		if (lb == INF)
		{
			root.add(0, MOD, 1);
		}
		else if (lb > 0)
		{
			root.add(0, lb - 1, 1);
		}
		while (k--)
		{
			int x;
			cin >> x;
			x = (x + last_ans) % (MOD + 1);
			int ans = root.query(x, x);
			cout << ans << "\n";
			last_ans = ans;
		}
	}
	return 0;
}