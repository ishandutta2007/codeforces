#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF LLONG_MAX

const int MAXN = 1e5+5;
ll arr[MAXN];
ll dp[MAXN][2];

void ini(){
	for(int i = 1;i<MAXN;i++)arr[i] = INF;
}
int main(){
	ini();
	int n;
	cin >> n;
	for(int j = 1;j<=n;j++)cin >> arr[j];
	for(int i = 1;i<=n;i++)
		dp[i][0] = arr[i]+dp[i-1][0];
	sort(arr,arr+MAXN);
	for(int i = 1;i<=n;i++)
		dp[i][1] = dp[i-1][1]+arr[i];
	int q;
	cin >> q;
	int t,l,r;
	while(q--){
		cin >> t >> l >> r;
		cout << dp[r][t-1]-dp[l-1][t-1]<<"\n";
	}
	return 0;
}