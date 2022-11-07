#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 3E5;

pair<int, int> pick(pair<int, int> pr1, pair<int, int> pr2)
{
	if (pr1.first == -1 && pr1.second == -1)
		return pr2;
	else if (pr2.first == -1 && pr2.second == -1)
		return pr1;
	if (pr1.second == -1)
		return pr2;
	return pr1;
}

pair<int, int> check(const vector<pair<int, int>> &vec1, const vector<pair<int, int>> &vec2, int k, int ind)
{
	if (vec1.empty() && vec2.empty())
		return {-1, -1};
	if (vec1.empty())
		return {vec2[0].second, -1};
	if (vec2.empty())
		return {vec1[0].second, -1};
	if (ind == -1)
		return {vec1[0].second, vec2[0].second};
	vector<pair<int, int>> zero1;
	vector<pair<int, int>> zero2;
	vector<pair<int, int>> one1;
	vector<pair<int, int>> one2;
	for (pair<int, int> pr : vec1)
	{
		if (pr.first & (1 << ind))
			one1.push_back(pr);
		else
			zero1.push_back(pr);
	}
	for (pair<int, int> pr : vec2)
	{
		if (pr.first & (1 << ind))
			one2.push_back(pr);
		else
			zero2.push_back(pr);
	}
	//cout << "ind " << ind << endl;
	//cout << "zero1 " << zero1.size() << endl;
	//cout << "zero2 " << zero2.size() << endl;
	//cout << "one1 " << one1.size() << endl;
	//cout << "one2 " << one2.size() << endl;
	if (k & (1 << ind))
	{
		pair<int, int> pr1 = check(one1, zero2, k, ind - 1);
		pair<int, int> pr2 = check(one2, zero1, k, ind - 1);
		return pick(pr1, pr2);
	}
	else
	{
		if (zero1.size() && one2.size())
			return {zero1[0].second, one2[0].second};
		if (zero2.size() && one1.size())
			return {zero2[0].second, one1[0].second};
		pair<int, int> pr1 = check(one1, one2, k, ind - 1);
		pair<int, int> pr2 = check(zero1, zero2, k, ind - 1);
		return pick(pr1, pr2);
	}
}

int main()
{
	int n, k;
	cin >> n >> k;
	if (k == 0)
	{
		cout << n << "\n";
		for (int i = 1; i <= n; i++)
			cout << i << " \n"[i == n];
		return 0;
	}
	int m = 32 - __builtin_clz(k);
	map<int, vector<pair<int, int>>> mp;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		mp[x >> (31 - __builtin_clz(k))].push_back({x, i});
	}
	vector<int> ans;
	for (auto it : mp)
	{
		//cout << "mapped " << it.first << "\n";
		//for (pair<int, int> pr : it.second)
			//cout << "\t" << pr.first << " " << pr.second << "\n";
		vector<pair<int, int>> vec1 = mp.count(it.first) ? mp[it.first] : vector<pair<int, int>>();
		vector<pair<int, int>> vec2 = mp.count(it.first ^ 1) ? mp[it.first ^ 1] : vector<pair<int, int>>();
		//cout << "checking " << it.first << " " << (it.first ^ 1) << endl;
		if ((it.first & 1) && mp.count(it.first ^ 1))
			continue;
		pair<int, int> pr = check(vec1, vec2, k, m - 2);
		if (pr.first != -1)
			ans.push_back(pr.first);
		if (pr.second != -1)
			ans.push_back(pr.second);
	}
	if (ans.size() >= 2)
	{
		cout << ans.size() << "\n";
		for (int x : ans)
			cout << x << " ";
		cout << "\n";
	}
	else
		cout << "-1\n";
	return 0;
}