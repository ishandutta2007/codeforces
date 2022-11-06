#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300000;
int a[MAXN + 1];
int b[MAXN + 1];
vector<int> from_[MAXN + 1];
int back_[MAXN + 1];
bool slipped[MAXN + 1];

int main()
{
	int n;
	cin >> n;
	fill(back_, back_ + n + 1, -1);
	set<int> live;
	for (int i = 0; i < n; i++)
	{
		live.insert(i);
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
		from_[i + b[i]].push_back(i);
	}
	from_[0].push_back(0);
	queue<pair<int, int>> q;
	q.push({n, n});
	slipped[n] = true;
	for (int w : from_[n])
		live.erase(w);
	//cout << "LIVE" << endl;
	//for (int w : live)
		//cout << w << " ";
	//cout << endl;
	while (q.size())
	{
		pair<int, int> pr = q.front();
		int v = pr.first;
		if (!v)
			break;
		//cout << "q " << v << " " << pr.second << endl;
		q.pop();
		auto it = live.upper_bound(v);
		if (it != live.begin())
		{
			it--;
			//cout << "it " << *it << endl;
			vector<int> temp;
			while (*it >= v - a[v])
			{
				int u = *it;
				//cout << "jump to " << u << endl;
				back_[u] = pr.second;
				if (!slipped[u + b[u]])
				{
					slipped[u + b[u]] = true;
					for (int w : from_[u + b[u]])
					{
						temp.push_back(w);
						back_[w] = pr.second;
					}
					q.push({u + b[u], u});
				}
				if (it == live.begin())
					break;
				it--;
			}
			for (int w : temp)
			{
				live.erase(w);
			}
		}
	}
	if (back_[0] == -1)
	{
		cout << "-1\n";
	}
	else
	{
		vector<int> vec;
		int cur = 0;
		while (cur != n)
		{
			vec.push_back(cur);
			cur = back_[cur];
		}	
		reverse(vec.begin(), vec.end());
		cout << vec.size() << "\n";
		for (int d : vec)
			cout << d << " ";
		cout << "\n";
	}
	return 0;
}