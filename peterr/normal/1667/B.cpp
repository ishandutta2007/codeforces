#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 5E5;

struct Node
{
	Node* lt;
	Node* rt;
	pair<int, int> val;
	long long lb, ub;
	Node(long long lb, long long ub)
	{
		this->lb = lb;
		this->ub = ub;
		lt = rt = nullptr;
		val = {-10 * MAXN, 0};
	}
	
	~Node()
	{
		if (lt)
		{
			delete lt;
			lt = nullptr;
		}
		if (rt)
		{
			delete rt;
			rt = nullptr;
		}
	}
	
	void push()
	{
		long long mid = lb + (ub - lb) / 2;
		if (!lt)
			lt = new Node(lb, mid);
		if (!rt)
			rt = new Node(mid + 1, ub);
	}
	
	void set(long long pos, int val1, int val2)
	{
		//cout << lb << " " << ub << endl;
		if (lb == ub)
		{
			val = max(val, {val1, val2});
			return;
		}
		long long mid = lb + (ub - lb) / 2;
		push();
		if (pos <= mid)
			lt->set(pos, val1, val2);
		else
			rt->set(pos, val1, val2);
		val = max(lt->val, rt->val);
	}
	
	pair<int, int> query(long long l, long long r)
	{
		//cout << lb << " " << ub << endl;
		if (lb >= l && ub <= r)
			return val;
		if (lb > r || ub < l)
			return {-10 * MAXN, 0};
		push();
		return max(lt->query(l, r), rt->query(l, r));
	}
};

int a[MAXN];
pair<long long, int> pref[MAXN];
int perm[MAXN];
int prevperm[MAXN];
int dp[MAXN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		Node plus(-1, n);
		Node minus(-1, n);
		map<long long, int> mp;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		pref[0] = {a[0], 0};
		for (int i = 1; i < n; i++)
			pref[i] = {pref[i - 1].first + a[i], i};
		sort(pref, pref + n);
		for (int i = 0; i < n; i++)
		{
			perm[pref[i].second] = i;
		}
		prevperm[0] = -1;
		for (int i = 1; i < n; i++)
		{
			if (pref[i].first > pref[i - 1].first)
				prevperm[i] = i - 1;
			else
				prevperm[i] = prevperm[i - 1];
		}
		if (a[0] == 0)
		{
			dp[0] = 0;
		}
		else if (a[0] > 0)
		{
			dp[0] = 1;
		}
		else
		{
			dp[0] = -1;
		}
		mp[a[0]] = dp[0];
		plus.set(perm[0], dp[0], 0);
		minus.set(perm[0], dp[0] + n, 0);
		long long sum = a[0];
		//cout << "HERE\n";
		for (int i = 1; i < n; i++)
		{
			sum += a[i];
			int best = -10 * MAXN;
			if (sum == 0)
				best = max(best, 0);
			else if (sum > 0)
				best = max(best, i + 1);
			else
				best = max(best, -i - 1);
			if (mp.count(sum))
				best = max(best, mp[sum]);
			//cout << "best " << best << endl;
			//cout << sum + 1 << endl;
			//cout << INF << endl;
			pair<int, int> pr = plus.query(perm[i] + 1, n);
			best = max(best, pr.first - pr.second - (i - pr.second));
			//cout << "best " << best << endl;
			pr = minus.query(-1, prevperm[perm[i]]);
			best = max(best, pr.first - n + pr.second + (i - pr.second));
			//cout << "pr " << pr.first << " " << pr.second << "\n";
			//cout << "best " << best << endl;
			dp[i] = best;
			if (mp.count(sum))
				mp[sum] = max(mp[sum], dp[i]);
			else
				mp[sum] = dp[i];
			plus.set(perm[i], dp[i] + i, i);
			minus.set(perm[i], dp[i] + n - i, i);
			//cout << "setting sum " << sum << endl;
			//cout << "dp " << i << " " << dp[i] << endl;
			//cout << "sum " << i << " " << sum << endl;
		}
		cout << dp[n - 1] << "\n";
	}
	return 0;
}