#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int t[N];
int dp[N];

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d", &n);

	t[0] = -1e9;

	for(int i = 1; i <= n; ++i){
		scanf("%d", t + i);

		dp[i] = dp[i - 1] + 20;

		int x = lower_bound(t, t + i, t[i] - 90 + 1) - t - 1;
		dp[i] = min(dp[i], dp[x] + 50);
		x = lower_bound(t, t + i, t[i] - 1440 + 1) - t - 1;
		dp[i] = min(dp[i], dp[x] + 120);


		printf("%d\n", dp[i] - dp[i - 1]);
	}


	return 0;
}