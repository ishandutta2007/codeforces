

#include<bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	int n, t;
	t=1;
	while (t--) {
		cin >> n;
		vector<int> a(n);
		for (int i=0; i< n; ++i){
			cin >> a[i];
		}
		int sum = 0;
		for (int i=0; i<n; ++i){
			sum+=a[i];
		}
		if (sum%2==1) {cout << "0" << endl;}
		else {
			vector<int> dp(200005);
			dp[0]=1;
			for(int i:a){
				for(int j=200000-i; j>=0; j--){
					dp[j+i] |= dp[j];
				}
			}

			if (dp[sum/2] == 0) {
				cout << "0\n";
			} else {
				while (1) {
					for (int i = 0; i < n; i++) {
						if (a[i] % 2) {
								cout << "1\n";
							cout << i+1 << '\n';
							exit(0);
						}
					}
					for (int i = 0; i < n; i++) {
						a[i] /= 2;
					}
				}
			}
		}
	}
}