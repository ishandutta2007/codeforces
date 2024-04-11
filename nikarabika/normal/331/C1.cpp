#include <bits/stdc++.h>

using namespace std;

#define smin(x, y) (x) = min((x), (y))

const int maxn = 1e6 + 10;
int dp[maxn], n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	dp[0] = 0;
	for(int i = 1; i < maxn; i++){
		int a = i;
		dp[i] = maxn;
		while(a){
			smin(dp[i], dp[i - (a % 10)] + 1);
			a /= 10;
		}
	}
	cin >> n;
	cout << dp[n] << endl;
	return 0;
}