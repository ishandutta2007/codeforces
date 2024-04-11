#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <limits>
#include <tuple>
#include <iostream>
#include <cstdio>

using namespace std;

string sizes[6] = {"S", "M", "L", "XL", "XXL", "XXXL"};
map<string, int> nums;
vector<int> cnt(6);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 6; i++) 
    {
		nums[sizes[i]] = i;
		cin >> cnt[i];
	}
	int n;
	cin >> n;
	vector<set<pair<int, int> > > needs(6);
	vector<string> ans(n, "-");
	for (int i = 0; i < n; i++) 
	{
		string s;
		cin >> s;
		int sl = -1;
		for (int j = 0; j < (int)s.size(); j++) 
        {
			if (s[j] == ',') 
			{
				sl = j;
				break;
			}
		}
		if (sl == -1) 
        {
			ans[i] = s;
			cnt[nums[s]]--;
			if (cnt[nums[s]] < 0) 
            {
				cout << "NO\n";
				return 0;
			}
		} 
		else 
        {
			needs[nums[s.substr(0, sl)]].insert({1, i});
			needs[nums[s.substr(sl + 1, (int)s.size() - sl - 1)]].insert({0, i});
		}
	}
	for (int i = 0; i < 6; i++) 
    {
		while (cnt[i] > 0 && !needs[i].empty()) 
        {
			if (ans[needs[i].begin()->second] == "-") 
            {
				ans[needs[i].begin()->second] = sizes[i];
				cnt[i]--;
			}

			needs[i].erase(needs[i].begin());
		}
	}
	for (int i = 0; i < 6; i++) 
    {
		if (cnt[i] < 0) 
		{
			cout << "NO\n";
			return 0;
		}
	}
	for (int i = 0; i < n; i++) 
    {
		if (ans[i] == "-") 
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	for (auto t : ans) 
    {
		cout << t << "\n";
	}
	return 0;
}