#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

const int MAXN = 501;

int dp[MAXN];
int n;
int arr[MAXN];

bool can_be_replaced(int l, int r)
{
	vector<int> cpy(r-l+1);
	for (int i(0); i < SZ(cpy); ++i)
		cpy[i] = arr[l+i];
	while (SZ(cpy) > 1)
	{
		int i(0);
		while (i+1 < SZ(cpy) and cpy[i] != cpy[i+1])
			++i;
		if (i+1==SZ(cpy))
			return false;
		cpy[i]++;
		for (int j(i+1); j +1 < SZ(cpy); ++j)
			cpy[j]=cpy[j+1];
		cpy.pop_back();
	}
	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i(0); i < n; ++i)
		cin >> arr[i];
	
	dp[n] = 0;

	for (int state(n-1); state >= 0; --state)
	{
		dp[state] = n;
		for (int nxt(state+1); nxt <= n; ++nxt)
			if (can_be_replaced(state, nxt-1))
				dp[state] = min(dp[state], 1 + dp[nxt]);
	}
	cout << dp[0] << endl;
}