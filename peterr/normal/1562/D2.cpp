#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3E5;
int a[MAXN + 1];
int pref[MAXN + 2];
map<int, set<int>> when_;

vector<int> solve(int l, int r)
{
	int sum = pref[r] - pref[l - 1];
	if (!sum)
	{
		return {};
	}
	int len = r - l + 1;
	if (!(len & 1))
	{
		vector<int> ans2 = {r};
		vector<int> temp = solve(l, r - 1);
		ans2.push_back(temp[0]);
		return ans2;
	}
	vector<int> ans;
	//cout << "lr " << l << " " << r << endl;
	//cout << "pref1 " << pref[r] << endl;
	//cout << "pref2 " << pref[l - 1] << endl;
	//cout << "sum " << sum << endl;
	if (sum)
	{
		//int target = pref[l] + (sum + 1) / 2; 
		int target;
		if (sum < 0)
			target = pref[l - 1] + (sum - 1) / 2;
		else
			target = pref[l - 1] + (sum + 1) / 2;
		//cout << "target " << target << endl;
		int ind = *when_[target].lower_bound(l);
		ans.push_back(ind);
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		when_.clear();
		int n, q;
		string s;
		cin >> n >> q >> s;
		for (int i = 0; i < (int) s.length(); i++)
		{
			if ((s[i] == '+') == (i & 1))
				a[i + 1] = 1;
			else
				a[i + 1] = -1;
			pref[i + 1] = pref[i] + a[i + 1];
			when_[pref[i + 1]].insert(i + 1);
			//cout << "pref " << i << " " << pref[i] << endl;
		}
		//cout << "here is a " << endl;
		//for (int i = 1; i <= n; i++)
			//cout << a[i] << " \n"[i == n];
		while (q--)
		{
			int l, r;
			cin >> l >> r;
			//cout << "lr " << l << " " << r << endl;
			//cout << "pref1 " << pref[r] << endl;
			//cout << "pref2 " << pref[l - 1] << endl;
			//cout << "sum is " << sum << endl;
			vector<int> ans = solve(l, r);
			cout << ans.size() << "\n";
			if (ans.size())
			{
				for (int x : ans)
					cout << x << " ";
				cout << "\n";
			}
		}
	}
	return 0;
}