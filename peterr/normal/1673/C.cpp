#include <bits/stdc++.h>
 
using namespace std;

const int MOD = 1E9 + 7;
const int MAXN = 4E4;
int dp[MAXN + 1];
set<int> nums;

void add(int &x, int y)
{
	x += y;
	if (x >= MOD)
		x -= MOD;
}

int main()
{
	for (int i = 1; i <= MAXN; i++)
	{
		string s = to_string(i);
		bool valid = true;
		for (int i = 0; i < (int) s.length(); i++)
		{
			if (s[i] != s[(int) s.length() - i - 1])
				valid = false;
		}
		if (valid)
		{
			nums.insert(i);
		}
	}
	//cout << "nums " << nums.size() << endl;
	dp[0] = 1;
	for (int x : nums)
	{
		vector<int> vec(x);
		//cout << x << endl;
		for (int i = 0; i <= MAXN; i++)
		{
			int prev = dp[i];
			if (i >= x)
				add(dp[i], vec[i % x]);
			add(vec[i % x], prev);
		}
	}
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << dp[n] << "\n";
	}
	return 0;
}