#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 500;
int a[MAXN];
vector<pair<int, int>> ops;
vector<int> ans;
map<int, int> freq;

void solve(int n)
{
	vector<int> vec(n);
	for (int i = 0; i < n; i++)
	{
		vec[i] = a[i];
	}
	int extra = 0;
	while (vec.size())
	{
		int x = vec[0];
		int i = 1;
		while (vec[i] != x)
			i++;
		ans.push_back(2 * i);
		vector<int> new_vec;
		for (int j = 1; j < i; j++)
		{
			ops.push_back({i + j + extra, vec[j]});
			new_vec.push_back(vec[j]);
		}
		extra += i + 1 + (i - 1);
		reverse(new_vec.begin(), new_vec.end());
		for (int j = i + 1; j < (int) vec.size(); j++)
			new_vec.push_back(vec[j]);
		swap(vec, new_vec);
	}
}

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
		freq.clear();
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			freq[a[i]]++;
		}
		bool valid = true;
		for (auto it : freq)
			if (it.second & 1)
				valid = false;
		if (!valid)
		{
			cout << "-1\n";
			continue;
		}
		ops.clear();
		ans.clear();
		solve(n);
		cout << ops.size() << "\n";
		for (pair<int, int> pr : ops)
			cout << pr.first << " " << pr.second << "\n";
		cout << ans.size() << "\n";
		for (int x : ans)
			cout << x << " ";
		cout << "\n";
	}
	return 0;
}