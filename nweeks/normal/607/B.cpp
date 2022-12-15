#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 501;

int dp[MAXN][MAXN][2];

signed main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nbGem;
	cin >> nbGem;
	vector<int> col(nbGem);
	for (auto &v : col) cin >> v;
	for (int len(0); len <= nbGem; ++len)
		for (int deb(0); deb + len <= nbGem; ++deb)
			for (int inPal(0); inPal < 2; ++inPal)
			{
				int fin = deb + len;
				int &cur = dp[deb][fin][inPal];
				cur = 1e18;
				if (len <= 1)
					cur = len and !inPal;
				else
				{
					for (int nxt(deb+1); nxt < fin; ++nxt)
						if (col[nxt] == col[deb])
						{
							cur = min(cur, 1+dp[deb+1][nxt][1] + dp[nxt+1][fin][inPal]);
							if (inPal)
								cur = min(cur, dp[deb+1][nxt][1] + dp[nxt+1][fin][0]);
						}
					cur = min(cur, 1 + dp[deb+1][fin][inPal]);
					if (inPal)
						cur = min(cur, dp[deb+1][fin][0]);
				}
			}
	cout << dp[0][nbGem][0] << endl;
}