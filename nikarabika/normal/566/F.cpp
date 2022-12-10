#include <bits/stdc++.h>

using namespace std;

#define PB push_back

const int maxn = 1e6 + 10;
int dp[maxn], cnt[maxn];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		cnt[x]++;
	}
	for(int i = 1; i <= 1e6; i++){
		dp[i] += cnt[i];
		for(int j = i; j <= 1e6; j += i)
			dp[j] = max(dp[j], dp[i]);
	}
	cout << *max_element(dp, dp + maxn) << endl;
	return 0;
}