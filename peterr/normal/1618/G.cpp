#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 2E5;
int par[2 * MAXN];
int sz[2 * MAXN];
long long query_ans[MAXN];
list<int> small[2 * MAXN];
list<int> big[2 * MAXN];
long long smallsum[2 * MAXN];
long long bigsum[2 * MAXN];
long long ans = 0;

int getRoot(int x)
{
	if (par[x] != x)
		par[x] = getRoot(par[x]);
	return par[x];
}	

bool mge(int x, int y)
{
	//cout << "merging " << x << " " << y << endl;
	x = getRoot(x);
	y = getRoot(y);
	//cout << "means " << x << " " << y << endl;
	if (x == y)
		return false;
	if (sz[x] > sz[y])
		swap(x, y);
	par[x] = y;
	sz[y] += sz[x];
	if (y < x)
	{
		swap(small[x], small[y]);
		swap(big[x], big[y]);
		swap(smallsum[x], smallsum[y]);
		swap(bigsum[x], bigsum[y]);
	}
	ans -= bigsum[x];
	ans -= bigsum[y];
	while (small[y].size() && big[x].size())
	{
		big[y].push_front(small[y].back());
		bigsum[y] += small[y].back();
		smallsum[y] -= small[y].back();
		small[y].pop_back();
		small[x].push_back(big[x].front());
		smallsum[x] += big[x].front();
		bigsum[x] -= big[x].front();
		big[x].pop_front();
	}
	if (big[x].size())
	{
		bigsum[y] += bigsum[x];
		bigsum[x] = 0;
		big[y].splice(big[y].begin(), big[x]);
	}
	if (small[y].size())
	{
		smallsum[x] += smallsum[y];
		smallsum[y] = 0;
		small[x].splice(small[x].end(), small[y]);
	}
	swap(small[x], small[y]);
	swap(smallsum[x], smallsum[y]);
	ans += bigsum[y];
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, q;
	cin >> n >> m >> q;
	vector<pair<int, int>> points;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		points.push_back({a, 0});
		ans += a;
	}
	for (int i = 0; i < m; i++)
	{
		int b;
		cin >> b;
		points.push_back({b, 1});
	}
	sort(points.begin(), points.end());
	vector<tuple<int, int, int>> events;
	for (int i = 0; i < n + m; i++)
	{
		//cout << "point " << i << " " << points[i].first << " " << points[i].second << endl;
		par[i] = i;
		sz[i] = 1;
		if (points[i].second == 0)
		{
			big[i].push_back(points[i].first);
			bigsum[i] = points[i].first;
		}
		else
		{
			small[i].push_back(points[i].first);
			smallsum[i] = points[i].first;
		}
		if (i)
		{
			events.push_back({points[i].first - points[i - 1].first, i, i - 1});
		}
	}
	sort(events.begin(), events.end());
	vector<pair<int, int>> queries(q);
	for (int i = 0; i < q; i++)
	{
		cin >> queries[i].first;
		queries[i].second = i;
		//cout << "input query " << i << " " << queries[i].first << " " << queries[i].second << endl;
	}
	sort(queries.begin(), queries.end());
	int ptr = 0;
	for (pair<int, int> pr : queries)
	{
		//cout << "query " << pr.first << endl;
		int k = pr.first;
		while (ptr < (int) events.size() && get<0>(events[ptr]) <= k)
		{
			mge(get<1>(events[ptr]), get<2>(events[ptr]));
			ptr++;
		}
		query_ans[pr.second] = ans;
	}
	for (int i = 0; i < q; i++)
	{
		cout << query_ans[i] << "\n";
	}
	return 0;
}