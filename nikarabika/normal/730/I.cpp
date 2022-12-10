#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e3 + 7;

#define F first
#define S second

pair<pair<int, int>, int> p[N];
int dp[N][N], par[N][N];
int main()
{
	ios::sync_with_stdio(false);

	int n, a, b;
	cin >> n >> a >> b;
	for (int i=0; i<n; i++)
		cin >> p[i].F.first;
	for (int i=0; i<n; i++)
		cin >> p[i].F.second;
	for (int i=0; i<n; i++)
		p[i].S = i;
	sort(p, p+n);
	reverse(p, p+n);
	memset(dp, -63, sizeof dp);
	dp[0][0] = 0;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<=b; j++)
			if (dp[i+1][j+1] < dp[i][j] + p[i].F.second)
			{
				dp[i+1][j+1] = dp[i][j] + p[i].F.second;
				par[i+1][j+1] = 1;
			}
		for (int j=0; j<=b; j++)
			if (i - j < a)
			{
				if (dp[i+1][j] < dp[i][j] + p[i].F.first)
				{
					dp[i+1][j] = dp[i][j] + p[i].F.first;
					par[i+1][j] = -1;
				}
			}
			else
			{
				if (dp[i+1][j] < dp[i][j])
				{
					dp[i+1][j] = dp[i][j];
					par[i+1][j] = 0;
				}
			}
		/*for (int j=0; j<=b; j++)
			cerr << i+1 << " " << j << " " << dp[i+1][j] << "\n";*/
	}
	cout << dp[n][b] << "\n";
	vector<int> r1, r2;
	for (int i=n; i>0; i--)
	{
		if (par[i][b] == -1)
			r1.push_back(p[i-1].S+1);
		else if (par[i][b] == 1)
			r2.push_back(p[i-1].S+1);
		b -= max(0, par[i][b]);
	}
	for (auto x : r1)
		cout << x << " ";
	cout << "\n";
	for (auto x : r2)
		cout << x << " ";
	cout << "\n";
	return 0;
}