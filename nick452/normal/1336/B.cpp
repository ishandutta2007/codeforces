#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

long long sqr(long long n)
{
	return n * n;
}
long long eval(long long x, long long y, long long z)
{
	return sqr(x - y) + sqr(y - z) + sqr(z - x);
}
long long solve(const vector<int>& a, const vector<int>& b, const vector<int>& c)
{
	long long results = 1LL << 62;
	for (int va : a)
	{
		vector<int> gb, gc;
		auto it = lower_bound(b.begin(), b.end(), va);
		if (it != b.end()) 
			gb.push_back(*it);
		if (it != b.begin())
			gb.push_back(*(--it));
		it = lower_bound(c.begin(), c.end(), va);
		if (it != c.end())
			gc.push_back(*it);
		if (it != c.begin())
			gc.push_back(*(--it));
		for (int vb : gb)
			for (int vc : gc)
				results = min(results, eval(va, vb, vc));
	}
	return results;
}
int main()
{
#ifdef _MSC_VER
	freopen("b.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int num_cases;
	cin >> num_cases;
	while (num_cases--)
	{
		int n1, n2, n3;
		cin >> n1 >> n2 >> n3;
		vector<int> a1(n1);
		for (int i = 0; i < n1; i++) cin >> a1[i];
		vector<int> a2(n2);
		for (int i = 0; i < n2; i++) cin >> a2[i];
		vector<int> a3(n3);
		for (int i = 0; i < n3; i++) cin >> a3[i];
		sort(a1.begin(), a1.end());
		sort(a2.begin(), a2.end());
		sort(a3.begin(), a3.end());
		long long results = solve(a1, a2, a3);
		results = min(results, solve(a2, a3, a1));
		results = min(results, solve(a3, a1, a2));
		cout << results << endl;
	}
	return 0;
}