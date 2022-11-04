#include <iostream>
using namespace std;
struct MC {
	long long val=0;
	long long cost=0;
};
MC dp[300001];
MC dp1[300001];
MC dp2[300001];
int main()
{
	int n, q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		cin >> n;
		long long cs;
		for (int j = 1; j <= n; ++j) {
			long long tmpcs;
			cin >> dp[j].val>>tmpcs;
			dp[j].cost = dp2[j].cost = dp1[j].cost = 1000000000000000001;
			dp1[j].val = dp[j].val + 1;
			dp2[j].val = dp1[j].val + 1;
			if (dp[j].val != dp[j - 1].val && dp[j - 1].cost < dp[j].cost)dp[j].cost = dp[j - 1].cost;
			if (dp[j].val != dp1[j - 1].val && dp1[j - 1].cost < dp[j].cost)dp[j].cost = dp1[j - 1].cost;
			if (dp[j].val != dp2[j - 1].val && dp2[j - 1].cost < dp[j].cost)dp[j].cost = dp2[j - 1].cost;
			if (dp1[j].val != dp2[j - 1].val && tmpcs + dp2[j - 1].cost < dp1[j].cost)dp1[j].cost = tmpcs + dp2[j - 1].cost;
			if (dp1[j].val != dp1[j - 1].val && tmpcs + dp1[j - 1].cost < dp1[j].cost)dp1[j].cost = tmpcs + dp1[j - 1].cost;
			if (dp1[j].val != dp[j - 1].val && tmpcs + dp[j - 1].cost < dp1[j].cost)dp1[j].cost = tmpcs + dp[j - 1].cost;
			if (dp2[j].val != dp[j - 1].val && 2*tmpcs + dp[j - 1].cost < dp2[j].cost)dp2[j].cost = 2*tmpcs + dp[j - 1].cost;
			if (dp2[j].val != dp1[j - 1].val && 2 * tmpcs + dp1[j - 1].cost < dp2[j].cost)dp2[j].cost = 2 * tmpcs + dp1[j - 1].cost;
			if (dp2[j].val != dp2[j - 1].val && 2 * tmpcs + dp2[j - 1].cost < dp2[j].cost)dp2[j].cost = 2 * tmpcs + dp2[j - 1].cost;
			//cout << dp[j].val << " " << dp1[j].val << " " << dp2[j].val << "\n";
			//cout << dp[j].cost << " " << dp1[j].cost << " " << dp2[j].cost << "\n";
		}
		cs = dp[n].cost;
		if (dp1[n].cost < cs)cs = dp1[n].cost;
		if (dp2[n].cost < cs)cs = dp2[n].cost;
		cout << cs << "\n";
	}
	return 0;
}