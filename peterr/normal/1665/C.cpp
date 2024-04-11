#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 2E5;
int freq[MAXN + 1];

bool check(int n, int x)
{
	int infects = 1;
	for (int i = 1; i <= n; i++)
	{
		if (freq[i])
			infects++;
		infects += max(0, freq[i] - max(0, (1 + (x - i))));
		//cout << "iter " << i << " " << max(0, freq[i] - (1 + (x - i))) << endl;
	}
	//cout << "check " << x << " " << infects << endl;
	return infects <= x;
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
		fill(freq + 1, freq + n + 1, 0);
		for (int i = 2; i <= n; i++)
		{
			int p;
			cin >> p;
			freq[p]++;
		}
		sort(freq + 1, freq + n + 1);
		reverse(freq + 1, freq + n + 1);
		int ans = 0;
		for (int jump = n; jump; jump >>= 1)
		{
			while (!check(n, ans + jump))
				ans += jump;
		}
		cout << ans + 1 << "\n";
	}
	return 0;
}