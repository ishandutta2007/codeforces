#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int n, m;
int results;
set<vector<int>> results_set;

bool Check(const vector<int>& a)
{
	int sum = 0;
	int val = 0;
	for (int i = a.size() - 1; i >= 0; i--)
	{
		int cnt = a[i];
		for (int j = 0; j < cnt; j++)
		{
			++val;
			sum += val * (i + 1);
			if (sum > n) return false;
		}
	}
	return true;
}

vector<int> F(const vector<int>& a)
{
	vector<int> ret;
	ret.reserve(a.size());
	int val = -1;
	int count = 0;
	for (int x : a)
	{
		if (x == val)
		{
			++count;
		}
		else
		{
			if (count > 0)
			{
				ret.push_back(count);
			}
			count = 1;
			val = x;
		}
	}
	if (count > 0)
	{
		ret.push_back(count);
	}
	sort(ret.begin(), ret.end());
	return ret;
}

void DepthFirstSearch(int depth, int count, vector<int>& a)
{
	if (!a.empty())
	{
		if (m == 3)
		{
			++results;
		}
		else
		{
			vector<int> p = F(a);
			for (int i = 0; i < m - 4; ++i)
			{
				p = F(p);
				if (p.size() == 1 && p[0] == 1)
				{
					break;
				}
			}
			results_set.insert(p);
		}
	}
	for (; count > 0; count--)
	{
		a.push_back(count);
		if (Check(a))
		{
			DepthFirstSearch(depth + 1, count, a);
		}
		a.pop_back();
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n >> m;
	results = 0;
	results_set.clear();
	if (m == 1)
	{
		vector<int> f(n + 1);
		f[0] = 1;
		for (int val = 1; val <= n; val++)
		{
			for (int i = n; i >= 0; i--)
			{
				for (int count = i / val; count > 0; count--)
				{
					f[i] = (f[i] + f[i - count * val]) % MOD;
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{
			results = (results + f[i]) % MOD;
		}
	}
	else if (m == 2)
	{
		vector<vector<int>> f(n + 1, vector<int>(n + 1));
		for (int i = 1; i <= n; i++)
		{
			f[i][i] = 1;
		}
		for (int val = 2; val <= n + 1; val++)
		{
			vector<vector<int>> g(n / val + 1, vector<int>(n + 1));
			for (int i = f.size() - 1; i > 0; i--)
			{
				for (int j = 0; j <= n; j++)
				{
					f[i - 1][j] = (f[i - 1][j] + f[i][j]) % MOD;
				}
			}
			for (int count = 0; count <= n / val; count++)
			{
				int sum = count * val;
				for (int i = sum; i <= n; i++)
				{
					g[count][i] = f[count][i - sum];
				}
			}
			f.swap(g);
		}
		for (int i = 1; i <= n; i++)
		{
			results = (results + f[0][i]) % MOD;
		}
	}
	else
	{
		vector<int> a;
		DepthFirstSearch(1, n, a);
		results += results_set.size();
	}
	results = (results % MOD + MOD) % MOD;
	cout << results << endl;
	return 0;
}