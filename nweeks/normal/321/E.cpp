#include <bits/stdc++.h>
#define SZ(v) ((int)(v).size())
using namespace std;
typedef long long ll;

const int MAXN = 4001;
const int INF = 1e9;

int unfam[MAXN][MAXN];
int cost[MAXN][MAXN];
int nbPersonnes, nbGondols;
int dp[MAXN][MAXN];
int opt[MAXN][MAXN];

void calc(int gondols, int l, int r, int optL, int optR)
{
	if (l > r) return;
	int mid = (l + r) / 2;
	opt[gondols][mid] = 0;
	dp[gondols][mid] = INF;
	for (int i(optL); i <= optR and i < mid; ++i)
		if (dp[gondols-1][i] + cost[i][mid-1] < dp[gondols][mid])
		{
			opt[gondols][mid] = i;
			dp[gondols][mid] = cost[i][mid-1] + dp[gondols-1][i];
		}
	if (l == r)
		return ;
	calc(gondols, l, mid-1, optL, opt[gondols][mid]);
	calc(gondols, mid+1, r, opt[gondols][mid], optR);
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> nbPersonnes >> nbGondols;
	string s;
	getline(cin, s);
	for (int i(0); i < nbPersonnes; ++i)
	{
		getline(cin, s);
		for (int j(0); j < nbPersonnes; ++j)
			unfam[i][j] = s[2*j] - '0';
		//for (int j(0); j < nbPersonnes; ++j)
			//cin >> unfam[i][j];
	}
	for (int i(0); i < nbPersonnes; ++i)
		for (int j(1); j < nbPersonnes; ++j)
			unfam[i][j] += unfam[i][j-1];
	for (int i(0); i < nbPersonnes; ++i)
		for (int j(i+1); j < nbPersonnes; ++j)
			cost[i][j] = cost[i][j-1] + unfam[j][j] - (i ? unfam[j][i-1] : 0);


	dp[0][0] = 0;
	for (int i(1); i < nbPersonnes; ++i)
		dp[0][i] = INF;
	for (int g(1); g <= nbGondols; ++g)
	{
		if (g > 1)
			calc(g, g, nbPersonnes, g-1, nbPersonnes-1);
		else
			calc(g, g, nbPersonnes, 0, 0);
	}
	cout << dp[nbGondols][nbPersonnes] << endl;
}