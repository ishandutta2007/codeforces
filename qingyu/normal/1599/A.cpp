#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::abs;
using std::string;

const int N = 2e5 + 50;

int n, a[N];

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	std::sort(a + 1, a + n + 1);
	string s;
	int switches = 0;
	cin >> s;
	for (int i = 1; i < s.length(); ++i)
		if (s[i] != s[i - 1])
			++switches;
	int l = n - switches, r = n - switches + 1;
	std::vector<std::pair<int, char>> vecs;
	int sum = 0, last = 0;
	if (s[0] == 'L')
	{
		vecs.emplace_back(a[l], 'L');
		sum += a[l];
		--l;
	}
	else
	{
		vecs.emplace_back(a[l], 'R');
		sum -= a[l];
		--l;
		last = 1;
	}
	for (int i = 1; i < s.length(); ++i)
	{
		if (s[i] == s[i - 1])
		{
			if (last == 0)
			{
				sum -= a[l]; 
				vecs.emplace_back(a[l], 'R');
				--l;
				last = 1;
			}
			else
			{
				sum += a[l];
				vecs.emplace_back(a[l], 'L');
				--l;
				last = 0;
			}
		}
		else
		{
			if (s[i] == 'L')
			{
				sum += a[r];
				vecs.emplace_back(a[r], 'L');
				++r;
			}
			else
			{
				sum -= a[r];
				vecs.emplace_back(a[r], 'R');
				++r;
			}
		}
		if (s[i] == 'L') assert(sum > 0);
		else assert(sum < 0);
	}
	for (auto [i, j] : vecs)
		cout << i << " " << j << '\n';
}