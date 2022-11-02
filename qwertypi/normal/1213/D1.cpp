#include <iostream>
#include <numeric>
typedef long long ll;
using namespace std;

int dp[200001][20];
int main(){
	for(int i=0;i<=200000;i++){
		fill(dp[i], dp[i]+20, 0);
	}
	int n, k;
	cin >> n >> k;
	for(int i=0;i<n;i++){
		int v;
		cin >> v;
		int t = 0;
		while(v){
			dp[v][t]++;
			v /= 2;
			t++;
		}
		dp[0][t]++;
	}
	ll ans = (1 << 30);
	for(int i=0;i<=200000;i++){
		int j = 0;
		ll curCnt = 0;
		ll res = 0;
		while(j < 20 && curCnt < k){
			if(dp[i][j] + curCnt >= k){
				res += (k - curCnt) * j;
				curCnt = k;
				break;
			}else{
				curCnt += dp[i][j];
				res += dp[i][j] * j;
				j++;
			}
		}
		if(curCnt == k){
			ans = min(ans, res);
		}
	}
	cout << ans;
}