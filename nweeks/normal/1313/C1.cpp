#include <bits/stdc++.h>
using namespace std;

typedef	long long ll;

const int MAXN = 1e3;

ll dp[MAXN][MAXN];
ll mx_height[MAXN];
ll sol[MAXN];
int cnt_plots;

ll calc(int l, int r)
{
	if (l > r) return 0;
	if (dp[l][r] != -1) return dp[l][r];

	int smallest(l);
	for (int i(l+1); i <= r; ++i)
		if (mx_height[i] < mx_height[smallest])
			smallest = i;

	dp[l][r] = (l-r+1) * mx_height[smallest];
	for (int i(l); i <= r; ++i)
		if (mx_height[i] == mx_height[smallest])
			dp[l][r] = max({dp[l][r], (r-i+1) * mx_height[smallest] + calc(l, i-1), 
					(i-l+1) * mx_height[smallest] +  calc(i+1, r)});
	return dp[l][r];
}

void find_sol(int l, int r)
{
	if (l == r)
	{
		sol[l] = mx_height[l];
		return ;
	}
	if (l > r) return ;

	int smallest(l);
	for (int i(l+1); i <= r; ++i)
		if (mx_height[i] < mx_height[smallest])
			smallest = i;
	if ((l-r+1) * mx_height[smallest] == dp[l][r])
	{
		for (int i(l); i <= r; ++i)
			sol[i] = mx_height[smallest];
		return;
	}
	int which(-1);
	for (int i(l); i <= r; ++i)
	{
		if (mx_height[i] != mx_height[smallest])
			continue;
		if (max( (r-i+1) * mx_height[smallest] + calc(l, i-1),
					(i-l+1) * mx_height[smallest] + calc(i+1, r)) == dp[l][r])
		{
			which = i;
			break;
		}
	}	
	assert(which != -1);
	if ( (r-which+1) * mx_height[which] + calc(l, which -1) == dp[l][r])
	{
		for (int j(which); j <= r; ++j)
			sol[j] = mx_height[which];
		find_sol(l, which-1);
		return ;
	}
	for (int j(l); j <= which; ++j)
		sol[j] = mx_height[which];
	find_sol(which+1, r);

}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> cnt_plots;
	for (int i(0); i < cnt_plots; ++i)
		cin >> mx_height[i];

	for (int i(0); i < cnt_plots; ++i)
	{
		for (int j(0); j < cnt_plots; ++j)
			dp[i][j] = -1;
		dp[i][i] = mx_height[i];
	}
	calc(0, cnt_plots-1);	
	find_sol(0,cnt_plots-1);
	for (int i(0); i < cnt_plots; ++i)
		cout << sol[i] << ' ';
	cout << endl;
}