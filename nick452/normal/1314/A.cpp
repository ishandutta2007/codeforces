#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	vector<int> t(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> t[i];
	}
	map<int, vector<int>> p;
	for (int i = 0; i < n; ++i)
	{
		p[a[i]].push_back(t[i]);
	}
	int next_t = 0;
	multiset<int> categories;
	long long sum_in_categories = 0;
	long long results = 0;
	for (const auto& group : p)
	{
		while (next_t < group.first && categories.size() > 0)
		{
			results += sum_in_categories;
			sum_in_categories -= *(--categories.end());
			categories.erase(--categories.end());
			++next_t;
		}
		next_t = group.first;
		for (int t : group.second) 
		{
			categories.insert(t);
			sum_in_categories += t;
		}
	}
	while (categories.size() > 0)
	{
		results += sum_in_categories;
		sum_in_categories -= *(--categories.end());
		categories.erase(--categories.end());
	}
	for (int i = 0; i < n; ++i)
	{
		results -= t[i];
	}
	cout << results << endl;
	return 0;
}