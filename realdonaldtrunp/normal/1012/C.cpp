#include<bits/stdc++.h>
using namespace std;


#define MAX 5005

int n;
vector<int> v;

long long int dp[MAX][MAX][2];



int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		int a;
		scanf("%d", &a);
		v.push_back(a);
	}
	for (int i = 0; i < MAX; i++){
		for (int j = 0; j < MAX; j++){
			dp[i][j][0] = dp[i][j][1] = LLONG_MAX;
		}
	}
	dp[0][0][0] = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j <= i; j++){
			for (int k = 0; k < 2; k++){
				if (dp[i][j][k] == LLONG_MAX)continue;
				int height = -1;
				if (i){
					height = v[i - 1];
				}
				if (k){
					height = min(v[i - 1], v[i - 2] - 1);
				}
				//unselect
				dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][k]);
				//select
				long long int need = max(0, height-(v[i]-1));
				if(i+1<v.size())need += max(0, v[i+1] - (v[i] - 1));
				need += dp[i][j][k];
				dp[i + 2][j+1][true] = min(dp[i + 2][j+1][true], need);
			}
		}
	}
	for (int i = 1; i <= (n+1) / 2; i++){
		long long int ans = LLONG_MAX;
		for (int j = n; j < n + 2; j++){
			for (int k = 0; k < 2; k++){
				ans = min(ans, dp[j][i][k]);
			}
		}
		if (i>1)printf(" ");
		printf("%lld", ans);
	}
	puts("");
	return 0;
}