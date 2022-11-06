#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 5E5;
const int MAXQ = 3E5;

struct fenwick {
	vector<int> vec;
	fenwick(int arr[MAXN])
	{
		vec = vector<int>(MAXN);
		for (int i = 0; i < MAXN; i++)
			inc(i, arr[i]);
	}
	
	void inc(int pos, int amt)
	{
		if (!pos)
		{
			vec[pos] += amt;
			return;
		}
		while (pos < MAXN)
		{
			vec[pos] += amt;
			pos += pos & -pos;
		}
	}
	
	int query(int pos)
	{
		int ans = vec[0];
		while (pos)
		{
			ans += vec[pos];
			//cout << "pos " << vec[pos] << endl;
			pos -= pos & -pos;
		}
		return ans;
	}
	
	int query(int l, int r)
	{
		int ans = query(r);
		if (l)
			ans -= query(l - 1);
		return ans;
	}
};

string a[3];
int b[MAXN];
int left_end[MAXN];
int right_end[MAXN];
int starts[MAXN];
int ends_[MAXN];
tuple<int, int, int> queries[MAXQ];
int res[MAXQ];

int doCount(int cur, int prev)
{
	int ans = 0;
	if ((cur & 3) == 1 && !(prev & 1))
		ans++;
	if (cur == 2 && !(prev & 2))
		ans++;
	if ((cur & 6) == 4 && !(prev & 4))
		ans++;
	if (cur == 3 && !(prev & 3))
		ans++;
	if (cur == 6 && !(prev & 6))
		ans++;
	if (cur == 7 && !prev)
		ans++;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < 3; i++)
	{
		cin >> a[i];
	}
	//cout << "Here" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (a[j][i] == '1')
				b[i] += 1 << j;
		}
	}
	vector<pair<int, int>> events;
	for (int i = 0; i < n; i++)
	{
		int cur = b[i];
		int prev = i ? b[i - 1] : 0;
		if ((cur & 3) == 1 && !(prev & 1))
			starts[i]++;
		if (cur == 2 && !(prev & 2))
			starts[i]++;
		if ((cur & 6) == 4 && !(prev & 4))
			starts[i]++;
		if (cur == 3 && !(prev & 3))
			starts[i]++;
		if (cur == 6 && !(prev & 6))
			starts[i]++;
		if (cur == 7 && !prev)
			starts[i]++;
		if (cur == 7 && prev == 5)
		{
			int j = i - 1;
			while (j)
			{
				if (b[j - 1] == 7)
				{
					events.push_back({j, i});
					break;
				}
				else if (b[j - 1] != 5)
				{
					events.push_back({0, i});
					break;
				}
				j--;
			}
		}
		//cout << "starts " << i << " " << starts[i] << endl;
	}
	sort(events.begin(), events.end());
	//for (pair<int, int> pr : events)
	//{
		//cout << "event " << pr.first << " " << pr.second << endl;
	//}
	fenwick bit1(starts);
	fenwick bit2(ends_);
	int q;
	cin >> q;

	//cin >> q;
	for (int i = 0; i < q; i++)
	{
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		queries[i] = {l, r, i};
	}
	//cout << "Here" << endl;
	sort(queries, queries + q);
	int ptr = 0;
	for (int i = 0; i < q; i++)
	{
		int l = get<0>(queries[i]);
		int r = get<1>(queries[i]);
		int ind = get<2>(queries[i]);
		// adjust ptr
		while (ptr < (int) events.size() && events[ptr].first <= l)
		{
			//cout << "activated " << endl;
			//cout << "increasing " << events[ptr].second << endl;
			bit2.inc(events[ptr].second, 1);
			ptr++;
		}
		int ans = 0;
		ans = doCount(b[l], 0) + bit1.query(l + 1, r) - bit2.query(l + 1, r);
		//cout << "sub " << bit2.query(l + 1, r) << endl;
		res[ind] = ans;
	}
	for (int i = 0; i < q; i++)
	{
		cout << res[i] << "\n";
	}
	return 0;
}