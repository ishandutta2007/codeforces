#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
int a[maxn], pos[maxn], dp[maxn], n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[i]--;
		pos[a[i]] = i;
	}
	dp[n - 1] = 1;
	for(int i = n - 2; i >= 0; i--){
		if(pos[i + 1] > pos[i])
			dp[i] = dp[i + 1] + 1;
		else
			dp[i] = 1;
	}
	cout << n - (*(max_element(dp, dp + n))) << endl;
	return 0;
}