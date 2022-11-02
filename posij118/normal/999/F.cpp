#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	
	int cnt[100005], cnt2[100005];
	fill(cnt, cnt + 100005, 0);
	fill(cnt2, cnt2 + 100005, 0);
	
	long long dp[k*n + 1];
	
	int c[k*n], f[n], h[k];
	for(int i = 0; i<k*n; i++){
		cin >> c[i];
		cnt[c[i]]++;
	}
	
	for(int i = 0; i<n; i++){
		cin >> f[i];
		cnt2[f[i]]++;
	}
	
	for(int i = 0; i<k; i++){
		cin >> h[i];
	}
	
	bool flag = 1;
	long long ans = 0;
	
	for(int i = 0; i<100004; i++){
		if(flag) fill(dp, dp + k*n+1, 0);
		flag = 0;
		for(int j = 0; j<cnt2[i]; j++){
			flag = 1;
			for(int l = k*n; l >= 1; l--){
				for(int m = max(l - k, 0); m<l; m++){
					dp[l] = max(dp[l], dp[m] + h[l - m - 1]);
				}
			}
		}
		
		ans += dp[min(k*cnt2[i], cnt[i])];
	}
	
	cout << ans << endl;
}