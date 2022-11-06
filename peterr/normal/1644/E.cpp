#include <bits/stdc++.h>
 
using namespace std;

long long solve(string s, int n)
{
	bool has_d = false;
	bool has_r = false;
	for (char ch : s)
	{
		if (ch == 'D')
			has_d = true;
		else
			has_r = true;
	}
	if (has_d && has_r)
	{
		long long ans = (int) s.length() + 1;
		int r_cnt = 0;
		int d_cnt = 0;
		for (char ch : s)
		{
			if (ch == 'R')
				r_cnt++;
			else
				d_cnt++;
		}
		// to the right
		int rows = d_cnt + 1;
		ans += (long long) rows * (n - r_cnt - 1);
		// to the down
		int side_offset = 0;
		for (int i = 0; i < (int) s.length(); i++)
		{
			if (s[i] == 'D')
				break;
			side_offset++;
		}
		int cols = r_cnt + 1;
		//cout << "pre " << ans << endl;
		ans += (long long) (cols - side_offset) * (n - d_cnt - 1);
		//cout << "post " << ans << endl;
		// to the downright
		//cout << "pre " << ans << endl;
		ans += (long long) (n - rows) * (n - cols);
		//cout << "post " << ans << endl;
		return ans;
	}
	else
		return n;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		if (s[0] == 'D')
		{
			for (int i = 0; i < (int) s.length(); i++)
			{
				s[i] = (s[i] == 'R' ? 'D' : 'R');
			}
		}
		cout << solve(s, n) << "\n";
	}
	return 0;
}