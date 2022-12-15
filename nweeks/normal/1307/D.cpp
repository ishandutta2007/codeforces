#include <bits/stdc++.h>
using namespace std;

typedef	long long ll;

const int MAXN = 2e5;

vector<int> G[MAXN];
vector<int> dis_start;
vector<int> dis_end;
vector<int> special;
int n,m,k;

struct Item
{
	int id;
	
	bool operator<(Item other) const
	{
		if (dis_end[id] == dis_end[other.id])
			return id < other.id;
		return dis_start[id] < dis_start[other.id];
	}
};

bool comp(int i, int j)
{
	if (dis_start[i] == dis_start[j])
		return i < j;
	return dis_start[i] < dis_start[j];
}


bool can(int want)
{
	deque<int> have;
	for (int i(0); i <k; ++i)
		have.push_back(special[i]);
	for (int i(0); i < k; ++i)
	{
		while (!have.empty() and 1+dis_end[have.front()] + dis_start[special[i]] < want)
			have.pop_front();
		if (!have.empty())
		{
			if (have.front() != special[i] and 1+dis_start[have.front()] + dis_end[special[i]] >= want)
				return true;
			if (have.front() == special[i])
			{
				have.pop_front();
				while (!have.empty() and 1+dis_end[have.front()] + dis_start[special[i]] < want)
					have.pop_front();
				if (!have.empty() and 1+dis_start[have.front()] + dis_end[special[i]] >= want)
					return true;
				have.push_front(special[i]);
			}
		}
	}
	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> k;
	special.resize(k);

	for (int i(0); i < k; ++i)
	{
		int u;
		cin >> u;
		--u;
		special[i]=u;
	}

	for (int i(0); i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	dis_start.resize(n);
	dis_end.resize(n);
	for (int i(0); i < n; ++i)
		dis_end[i] = dis_start[i] = 1e9;
	queue<int> Q;
	Q.push(0);
	dis_start[0]=0;
	while (!Q.empty())
	{
		int u = Q.front(); Q.pop();

		for (auto v : G[u])
			if (dis_start[v] > dis_start[u] + 1)
			{
				dis_start[v] = dis_start[u]+1;
				Q.push(v);
			}
	}
	Q.push(n-1);
	dis_end[n-1]=0;
	while (!Q.empty())
	{
		int u = Q.front(); Q.pop();

		for (auto v : G[u])
			if (dis_end[v] > dis_end[u] + 1)
			{
				dis_end[v] = dis_end[u] + 1;
				Q.push(v);
			}
	}

	sort(special.rbegin(), special.rend(), comp);	


	int l=1, r = dis_start[n-1];
	while (l < r)
	{
		int m = (l+r+1)/2;
		if (can(m))
			l=m;
		else
			r = m-1;
	}
	cout << l << endl;
}