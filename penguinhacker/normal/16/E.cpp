#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=18;
int n;
double mat[mxN][mxN];
double dp[1<<mxN], ans[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			cin >> mat[i][j];
		}
	}
	dp[0]=1;
	for (int mask=0; mask<(1<<n); ++mask) {
		if (__builtin_popcount(mask)>n-2) {
			if (__builtin_popcount(mask)==n-1) {
				int x=mask^((1<<n)-1);
				ans[__builtin_ctz(x)]=dp[mask];
			}
			continue;
		}
		vector<int> alive; alive.reserve(n);
		for (int i=0; i<n; ++i) {
			if (!(mask&(1<<i))) {
				alive.push_back(i);
			}
		}
		for (int i: alive) {
			double add=0;
			for (int j: alive) {
				add+=mat[j][i];
			}
			add*=2*dp[mask]/(alive.size()-1)/(alive.size());
			dp[mask|(1<<i)]+=add;
		}
	}
	cout << fixed << setprecision(6);
	for (int i=0; i<n; ++i) {
		cout << ans[i] << " ";
	}
	return 0;
}