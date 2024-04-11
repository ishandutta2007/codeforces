#include <iostream>
#include <algorithm>
#include <limits.h>

#define N 30
#define INF (LLONG_MAX>>2)

using namespace std;

long long def[2*N][2*N];
long long dp[2*N][2*N], tmp[2*N][2*N];
int a[N], b[N];
int n, m;

void calc(int x) {
	if(x == 1) {
		for(int i = 0;i <= 2*n;i++) {
			for(int j = 0;j <= 2*n;j++) {
				dp[i][j] = def[i][j];
			}
		}
	}else {
		calc(x/2);
		for(int i = 0;i <= 2*n;i++) {
			for(int j = 0;j <= 2*n;j++) {
				tmp[i][j] = INF;
			}
		}
		for(int i = 0;i <= 2*n;i++) {
			for(int j = 0;j <= 2*n;j++) {
				for(int k = 0;k <= 2*n;k++) {
					tmp[i][j] = min(tmp[i][j], dp[i][k] + dp[k][j]);
				}
			}
		}
		for(int i = 0;i <= 2*n;i++) {
			for(int j = 0;j <= 2*n;j++) {
				dp[i][j] = tmp[i][j];
			}
		}
		if(x%2) {
			for(int i = 0;i <= 2*n;i++) {
				for(int j = 0;j <= 2*n;j++) {
					tmp[i][j] = INF;
				}
			}			
			for(int i = 0;i <= 2*n;i++) {
				for(int j = 0;j <= 2*n;j++) {
					for(int k = 0;k <= 2*n;k++) {
						tmp[i][j] = min(tmp[i][j], dp[i][k] + def[k][j]);
					}
				}
			}
			for(int i = 0;i <= 2*n;i++) {
				for(int j = 0;j <= 2*n;j++) {
					dp[i][j] = tmp[i][j];
				}
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for(int i = 0;i < n;i++) {
		cin >> a[i];
	}
	for(int i = 0;i < n;i++) {
		cin >> b[i];
	}
	for(int i = 0;i <= 2 *n;i++) {
		for(int j = 0;j <= 2 *n;j++) {
			def[i][j] = INF;
		}
	}
	for(int i = 0;i < (1 << n);i++) {
		int mn = 0, val = 0, balance = 0;
		for(int j = 0;j	< n;j++) {
			if(i & (1 << j)) {
				val += a[j];
				balance++;
			}else {
				val += b[j];
				balance--;
			}
			mn = min(mn, balance);
		}
		for(int j = -mn;j <= 2*n;j++) {
			int k = j + balance;
			if(0 <= k && k <= 2*n) {
				def[j][k] = min(def[j][k], (long long)val);
			}
		}
	}
	calc(m);
	cout << dp[0][0] << endl;
	return 0;
}