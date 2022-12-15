#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

const int MAXN = 2e6+1;

pair<int, int> seg[MAXN];
int p(0), deb;
int n;

pair<int, int> get_best(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
		return (a.second < b.second ? a : b);
	if (a.first < b.first)
		return a;
	return b;
}

void init(void)
{
	while ((1<<p) < n)
		++p;
	deb = (1<<p)-1;
	for (int i(0); i < n; ++i)
		seg[deb + i] = make_pair(1, i+1);
	for (int i(n); i < (1<<p); ++i)
		seg[deb+i] = make_pair(1e9, i+1);
	
	for (int i(deb-1); i >= 0; --i)
		seg[i] = get_best(seg[2*i+1], seg[2*i+2]);
}

void point_update(int pos, int val)
{
	pos += deb;
	seg[pos].first = val;
	while (pos > 0)
	{
		pos = (pos-1)/2;
		seg[pos] = get_best(seg[2*pos+1], seg[2*pos+2]);	
	}
}

void show_tree(void)
{
	cout << "----------" << endl;
	for (int k(0); k <= p; ++k)
	{
		for (int i(0); i < (1<<k); ++i)
			cout << seg[(1<<k) - 1 + i].first << ' ';
		cout << endl;
	}
	cout << "----------" << endl;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n;
	init();
	point_update(0, 1e9);
	int cur_ans=1;
	for (int i(2); i <= n; ++i)
	{
		int change = seg[0].second;
		int val = seg[0].first;
		//cout << change << ' ' << val << endl;
		//show_tree();
		assert(change <= n);
		cur_ans = max(cur_ans, val);
		cout << cur_ans << ' ';
		point_update(change-1, 1e9);
		for (int j(2*change); j <= n; j += change)
		{
			if (seg[deb+j-1].first < change)
				point_update(j-1,change);
		}
	}	
	cout << endl;
}