#include <cstdio>
#include <iostream>
using namespace std;
const int maxn=2134;
const int sigma_size=5;
const int dirs[]={0, 1, 2, 1, 2};
int dp[maxn][sigma_size], a[maxn], n;
int main(){
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d", &a[i]);
	for(int i=1; i<=n+1; i++)
		for(int j=1; j<sigma_size; j++)
			dp[i][j]=max(dp[i-1][j], dp[i-1][j-1])+(a[i]==dirs[j]);
	printf("%d\n", dp[n+1][4]);
	return 0;
}