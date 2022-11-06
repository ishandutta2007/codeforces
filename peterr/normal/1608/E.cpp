#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 1E5;
const int MAXX = 1E9;
int x[MAXN];
int y[MAXN];
int c[MAXN];
int cc[MAXN];
int perm[6][3] = {
	{0, 1, 2},
	{0, 2, 1},
	{1, 0, 2},
	{1, 2, 0},
	{2, 1, 0},
	{2, 0, 1}
};
 
struct Node
{
	Node *left, *right;
	int lb, ub, sum1, sum2;
	
	Node(int lb, int ub)
	{
		left = right = nullptr;
		this->lb = lb;
		this->ub = ub;
		sum1 = sum2 = 0;
	}
	
	~Node()
	{
		if (left)
		{
			delete left;
			delete right;
			left = right = nullptr;
		}
	}
	
	void push()
	{
		if (!left)
		{
			int mid = floor((lb + ub) / 2.0);
			left = new Node(lb, mid);
			right = new Node(mid + 1, ub);
		}
	}
	
	void add1(int pos, int amt)
	{
		//cout << "add1 " << lb << " " << ub << endl;
		sum1 += amt;
		if (lb != ub)
		{
			push();
			int mid = floor((lb + ub) / 2.0);
			if (pos <= mid)
				left->add1(pos, amt);
			else
				right->add1(pos, amt);
		}
	}
	
	void add2(int pos, int amt)
	{
		sum2 += amt;
		if (lb != ub)
		{
			push();
			int mid = floor((lb + ub) / 2.0);
			if (pos <= mid)
				left->add2(pos, amt);
			else
				right->add2(pos, amt);
		}
	}
	
	int query(int leftCnt=0, int rightCnt=0)
	{
		//cout << "query " << lb << " " << ub << endl;
		if (lb == ub)
			return max(min(leftCnt + sum1, rightCnt), min(leftCnt, rightCnt + sum2));
		push();
		int ones = leftCnt + left->sum1;
		int twos = rightCnt + right->sum2;
		int ans = min(ones, twos);
		if (ones > twos)
			ans = max(ans, left->query(leftCnt, rightCnt + right->sum2));
		else
			ans = max(ans, right->query(leftCnt + left->sum1, rightCnt));
		return ans;
	}
};
 
int solve(int n)
{
	//cout << "solve " << endl;
	Node horz(-2 * MAXN, 2 * MAXN);
	Node vert(-2 * MAXN, 2 * MAXN);
	//cout << "constructed " << endl;
	vector<pair<int, int>> events;
	for (int i = 0; i < n; i++)
	{
		events.push_back({x[i], i});
		if (c[i] == 1)
		{
			//cout << "add1 " << i << endl;
			horz.add1(x[i], 1);
			vert.add1(y[i], 1);
		}
		else if (c[i] == 2)
		{
			//cout << "add2 " << i << endl;
			horz.add2(x[i], 1);
			vert.add2(y[i], 1);
		}
	}
	//cout << "added events " << endl;
	sort(events.begin(), events.end());
	int ans = 0;
	int ptr = 0;
	int cnt0 = 0;
	while (ptr < (int) events.size())
	{
		//cout << "ptr " << ptr << endl;
		int curX = events[ptr].first;
		bool changed = false;
		while (ptr < (int) events.size() && events[ptr].first == curX)
		{
			int ind = events[ptr].second;
			if (c[ind] == 0)
			{
				changed = true;
				cnt0++;
			}
			else if (c[ind] == 1)
			{
				horz.add1(x[ind], -1);
				vert.add1(y[ind], -1);
			}
			else if (c[ind] == 2)
			{
				horz.add2(x[ind], -1);
				vert.add2(y[ind], -1);
			}
			ptr++;
		}
		//cout << "about to query " << endl;
		if (changed)
		{
			ans = max(ans, min(cnt0, horz.query()));
			ans = max(ans, min(cnt0, vert.query()));
		}
		//cout << "done query " << endl;
	}
	return 3 * ans;
}

int solve2(int n)
{
	vector<vector<int>> vec(3);
	for (int i = 0; i < n; i++)
	{
		//cout << "pushing " << c[i] << endl;
		vec[c[i]].push_back(x[i]);
	}
	sort(vec[0].begin(), vec[0].end());
	sort(vec[1].begin(), vec[1].end());
	sort(vec[2].begin(), vec[2].end());
	int lo = 0;
	int hi = n / 3;
	while (lo < hi)
	{
		int mid = (lo + hi + 1) / 2;
		//cout << "test " << mid << endl;
		int curX = vec[0][mid - 1] + 1;
		//cout << "curx " << curX << endl;
		int ind = distance(vec[1].begin(), lower_bound(vec[1].begin(), vec[1].end(), curX));
		//cout << "ind " << ind << endl;
		//cout << "size " << vec[1].size() << endl;
		if (ind + mid - 1 >= (int) vec[1].size())
		{
			//cout << "NO" << endl;
			hi = mid - 1;
			continue;
		}
		curX = vec[1][ind + mid - 1] + 1;
		//cout << "curx " << curX << endl;
		ind = distance(vec[2].begin(), lower_bound(vec[2].begin(), vec[2].end(), curX));
		if (ind + mid - 1 >= (int) vec[2].size())
		{
			hi = mid - 1;
			continue;
		}
		//cout << "YES" << endl;
		lo = mid;
	}
	int ans = lo;
	//cout << "temp ans " << ans << endl;
	vector<pair<int, int>> vec1;
	vector<pair<int, int>> vec2;
	for (int i = 0; i < n; i++)
	{
		if (c[i] == 0)
			continue;
		if (c[i] == 1)
			vec1.push_back({y[i], x[i]});
		else
			vec2.push_back({y[i], x[i]});
	}
	sort(vec1.begin(), vec1.end());
	sort(vec2.rbegin(), vec2.rend());
	lo = 0;
	hi = n / 3;
	while (lo < hi)
	{
		int mid = (lo + hi + 1) / 2;
		int curX = vec[0][mid - 1];
		int cnt = mid;
		int lower = 0;
		for (pair<int, int> pr : vec1)
		{
			if (pr.second <= curX)
				continue;
			cnt--;
			lower = pr.first;
			if (!cnt)
				break;
		}
		if (cnt)
		{
			hi = mid - 1;
			continue;
		}
		cnt = mid;
		int upper = 0;
		for (pair<int, int> pr : vec2)
		{
			if (pr.second <= curX)
				continue;
			cnt--;
			upper = pr.first;
			if (!cnt)
				break;
		}
		if (cnt || lower >= upper)
		{
			hi = mid - 1;
			continue;
		}
		lo = mid;
	}
	//cout << "still nonzero " << ans << endl;
	ans = max(ans, lo);
	return ans * 3;
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	set<int> nums;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i] >> cc[i];
		//x[i] = i;
		//y[i] = i;
		//cc[i] = i % 3;
		nums.insert(x[i]);
		nums.insert(y[i]);
		cc[i]--;
		//cout << "cc " << cc[i] << endl;
	}
	map<int, int> mp;
	for (int num : nums)
	{
		mp[num] = (int) mp.size();
	}
	for (int i = 0; i < n; i++)
	{
		x[i] = mp[x[i]];
		y[i] = mp[y[i]];
	}
	//copy(cc, cc + n, c);
	//cout << "first solve " << solve2(n) << endl;
	//return 0;
	int ans = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < n; j++)
		{
			c[j] = perm[i][cc[j]];
			//cout << "c " << j << " " << c[j] << endl;
		}
		for (int j = 0; j < 4; j++)
		{
			ans = max(ans, solve2(n));
			for (int k = 0; k < n; k++)
			{
				swap(x[k], y[k]);
				x[k] = -x[k];
			}
		}
	}
	cout << ans << "\n";
	return 0;
}