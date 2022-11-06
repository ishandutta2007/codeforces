#include <bits/stdc++.h>
 
using namespace std;

const long long MAXX = 1E18;

void solve(const string &s, int ind, long long x, int k)
{
	if (ind == (int) s.length())
		return;
	if (s[ind] == 'a')
	{
		cout << 'a';
		solve(s, ind + 1, x, k);
		return;
	}
	int cnt = 0;
	while (ind < (int) s.length() && s[ind] == '*')
	{
		ind++;
		cnt++;
	}
	long long ways = 1;
	int ptr = ind;
	while (ptr < (int) s.length())
	{
		if (s[ptr] == 'a')
		{
			ptr++;
			continue;
		}
		int cnt2 = 0;
		while (ptr < (int) s.length() && s[ptr] == '*')
		{
			cnt2++;
			ptr++;
		}
		int temp = 1 + cnt2 * k;
		if (ways > (MAXX + temp - 1) / temp)
			ways = MAXX;
		else
			ways *= temp;
	}
	for (int i = 0; i < cnt * k; i++)
	{
		if (ways >= x)
			break;
		x -= ways;
		cout << 'b';
	}
	solve(s, ind, x, k);
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		long long x;
		cin >> n >> k >> x;
		string s;
		cin >> s;
		solve(s, 0, x, k);
		cout << "\n";
	}
	return 0;
}