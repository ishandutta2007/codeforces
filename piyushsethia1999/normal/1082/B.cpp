#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	string s; cin >> s;
	std::vector<int> gg(n + 2, 0);
	int total = 0;
	for (int i = 0; i < s.size(); ++i)
		if (s[i] == 'G') {
			gg[i + 1] = gg[i] + 1;
			total++;
		}
	std::vector<int> grev(n + 2, 0);
	for (int i = n - 1; i >= 0; --i)
		if (s[i] == 'G')
			grev[i + 1] = grev[i + 2] + 1;
	int mm = 0;
	for (int i = 0; i < n; ++i)
	{
		if (s[i] == 'S')
		{
			mm = max(mm, gg[i] + grev[i + 2] + 1);
		}
	}
	if (total == n)
	{
		mm = n;
	}
	mm = min(total, mm);
	cout << mm;
}