
#include <iostream>

using namespace std;


int main(){

	int n,m;
	cin >> n >> m;
	int a[n+1],dp[n+1];
	for (int i=0; i<n; i++){
		cin >> a[i];
		double temp; cin >> temp;
	}
	int ans = 0;
	for (int i=0; i<n; i++){
		dp[i] = 1;
		for (int j=0; j<i; j++) if (a[j]<=a[i]){
			dp[i] = max(dp[i], dp[j]+1);
		}
		ans = max(ans, dp[i]);
	}
	cout << n-ans << endl;
	return 0;
}