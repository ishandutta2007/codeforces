#include <bits/stdc++.h>

using namespace std;

const int MAXM = 1E5;
const int MAXN = 2E5;
vector<int> a[MAXM];
map<int, int> compress;
unordered_set<int> who[MAXN];
unordered_set<int> where[MAXM];
int freq[MAXN];
map<int, int> mp[MAXM];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int n;
		cin >> n;
		a[i].resize(n);
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			if (!compress.count(a[i][j]))
				compress[a[i][j]] = (int) compress.size();
			a[i][j] = compress[a[i][j]];
			mp[i][a[i][j]]++;
			freq[a[i][j]]++;
		}
		for (auto it : mp[i])
		{
			if (it.second & 1)
			{
				where[i].insert(it.first);
				who[it.first].insert(i);
			}	
		}
	}
	bool valid = true;
	for (int i = 0; i < MAXN; i++)
	{
		if (freq[i] & 1)
		{
			valid = false;
		}
	}
	if (!valid)
	{
		cout << "NO\n";
		return 0;
	}
	for (int i = 0; i < MAXM; i++)
	{
		while (where[i].size())
		{
			int u = *where[i].begin();
			where[i].erase(u);
			who[u].erase(i);
			int v = *where[i].begin();
			where[i].erase(v);
			who[v].erase(i);
			mp[i][v]++;
			//cout << "start " << i << " " << u << " " << v << endl;
			while (u != v)
			{
				int nextList = *who[v].begin();
				where[nextList].erase(v);
				who[v].erase(nextList);
				//cout << "p " << nextList << " " << v << " ";
				v = *where[nextList].begin();
				where[nextList].erase(v);
				who[v].erase(nextList);
				mp[nextList][v]++;
				//cout << v << endl;
			}
		}
	}
	cout << "YES\n";
	for (int i = 0; i < m; i++)
	{
		for (auto& it : mp[i])
		{
			it.second /= 2;
		}
		for (int j = 0; j < (int) a[i].size(); j++)
		{
			if (mp[i][a[i][j]])
			{
				cout << "L";
				mp[i][a[i][j]]--;
			}
			else
				cout << "R";
		}
		cout << "\n";
	}
	return 0;
}