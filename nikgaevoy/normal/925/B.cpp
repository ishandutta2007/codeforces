#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <random>
#include <limits>
#include <string>
#include <sstream>
#include <iomanip>

#include <cassert>
#include <cmath>
#include <ctime>

#pragma comment(linker, "/STACK:200000000")

using namespace std;

mt19937 mt(736);

void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	long long n, x1, x2, good = 0, p1=-1, p2=-1;
	vector<pair<long long, long long>>b;
	vector<long long> ans1, ans2;
	cin >> n >> x1 >> x2;
	b.resize(n);
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		b[i] = make_pair(x, i);
	}
	sort(b.begin(), b.end());
	reverse(b.begin(), b.end());
	for (int i = 0; i < n; i++)
	{
		if (x1 <= b[i].first * (i + 1))
		{
			p1 = i;
			i = n + 1;
		}
	}
	if (p1 != -1)
	{
		for (int i = p1+1; i < n; i++)
		{
			if (x2 <= b[i].first * (i-p1))
			{
				p2 = i;
				i = n + 1;
			}
		}
		if (p2 != -1)
		{
			good = 1;
			for (int i = 0; i <=p1; i++)
			{
				ans1.push_back(b[i].second);
			}
			for (int i = p1+1; i <= p2; i++)
			{
				ans2.push_back(b[i].second);
			}
		}
	}
	if (good == 0)
	{
		p1 = -1;
		p2 = -1;
		long long dt = x1;
		x1 = x2;
		x2 = dt;
		for (int i = 0; i < n; i++)
		{
			if (x1 <= b[i].first * (i + 1))
			{
				p1 = i;
				i = n + 1;
			}
		}
		if (p1 != -1)
		{
			for (int i = p1 + 1; i < n; i++)
			{
				if (x2 <= b[i].first * (i - p1))
				{
					p2 = i;
					i = n + 1;
				}
			}
			if (p2 != -1)
			{
				good = 1;
				for (int i = 0; i <= p1; i++)
				{
					ans1.push_back(b[i].second);
				}
				for (int i = p1 + 1; i <= p2; i++)
				{
					ans2.push_back(b[i].second);
				}
			}
		}
		swap(ans1, ans2);
	}
	if (good == 0)
	{
		cout << "No" << endl;
	}
	else
	{
		cout << "Yes" << endl;
		cout << ans1.size() << ' ' << ans2.size() << endl;
		for (int i = 0; i < ans1.size(); i++)
		{
			cout << ans1[i]+1 << ' ';
		}
		cout << endl;
		for (int i = 0; i < ans2.size(); i++)
		{
			cout << ans2[i]+1 << ' ';
		}
		cout << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

#ifdef LOCAL
	solve();

	cout << "clock: " << clock() << endl;
#else
	solve();
#endif // LOCAL

	return 0;
}