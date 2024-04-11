#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;
const int MAXN = 500;

int dp[MAXN][MAXN];

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int len;
	cin >> len;
	string s;
	cin>> s;

	for (int taille(1); taille <= len; ++taille)
		for (int l(0); l + taille-1 < len; ++l)
		{
			int r = l+taille;
			dp[l][r-1] = 1 + dp[l+1][r-1];
			for (int j(l+1); j < r; ++j)
				if (s[l] == s[j])
					dp[l][r-1] = min(dp[l][r-1], dp[l+1][j-1] + dp[j][r-1]);
		}
	cout << dp[0][len-1] << endl;
}