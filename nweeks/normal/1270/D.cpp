#include <bits/stdc++.h>
using namespace std;

int n,k;

int id[501];

pair<int, int> request(const set<int> &req)
{
	assert(req.size() == k);
	cout << "?";
	for (auto &e : req)
		cout << ' ' << e;
	cout << endl;	
	cout.flush();
	pair<int, int> p;
	cin >> p.first >> p.second;
	return p;
}

int		main(void)
{
	cin >> n >> k;

	if (k == 1)
	{
		cout << "! 1" << endl;
		cout.flush();
		return 0;
	}

	set<int> init;
	for (int i(1); i <= k; ++i)
		init.insert(i);

	int beg, value;
	auto p = request(init);
	beg = p.first, value = p.second;

	bool know = false;

	set<int> pitit;
	set<int> grand;
	
	init.erase(beg);
	
	init.insert(k+1);
	auto req = request(init);
	init.erase(k+1);
	if (req.second > value)
		grand.insert(k+1);
	else
		pitit.insert(k+1);
	
	init.insert(beg);
	if (!pitit.empty())
	{
		int tem = *pitit.begin();
		init.insert(tem);
		for (int i(1); i <= k; ++i)
			if (i != beg)
			{
				assert(init.find(i) != init.end());
				init.erase(i);
				auto req = request(init);
				init.insert(i);
				if (req.second == value)
					pitit.insert(i);
				else
				{
					assert(req.second < value);
					grand.insert(i);
				}
			}
	}
	else
	{
		int tem = *grand.begin();
		init.insert(tem);
		for (int i(1); i <= k; ++i)
			if (i != beg)
			{
				assert(init.find(i) != init.end());
				init.erase(i);
				auto req = request(init);
				init.insert(i);
				if (req.second == value)
					grand.insert(i);
				else
				{
					assert(req.second > value);
					pitit.insert(i);
				}
			}
	}

	int m(1);
	for (auto e : pitit)
		if (e <= k)
			m++;
	cout << "! " << m << endl;
	cout.flush();
}