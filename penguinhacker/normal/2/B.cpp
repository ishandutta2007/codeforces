#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, fct[1000][1000][2], dp[1000][1000][2];
char last[1000][1000][2];

void backtrack(int k, int i=n-1, int j=n-1) {
	if (i==0&&j==0)
		return;
	if (last[i][j][k]=='R')
		backtrack(k, i, j-1);
	else
		backtrack(k, i-1, j);
	cout << last[i][j][k];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int where=0;
	cin >> n;
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j) {
			int k;
			cin >> k;
			if (!k) {
				where=i;
				continue;
			}
			while (k%2==0) {
				++fct[i][j][0];
				k/=2;
			}
			while(k%5==0) {
				++fct[i][j][1];
				k/=5;
			}
		}
	for (int k=0; k<2; ++k) {
		dp[0][0][k]=fct[0][0][k];
		for (int i=1; i<n; ++i) {
			dp[0][i][k]=dp[0][i-1][k]+fct[0][i][k];
			last[0][i][k]='R';
			dp[i][0][k]=dp[i-1][0][k]+fct[i][0][k];
			last[i][0][k]='D';
		}
		for (int i=1; i<n; ++i) {
			for (int j=1; j<n; ++j) {
				dp[i][j][k]=dp[i-1][j][k]+fct[i][j][k];
				last[i][j][k]='D';
				if (dp[i][j-1][k]+fct[i][j][k]<dp[i][j][k]) {
					dp[i][j][k]=dp[i][j-1][k]+fct[i][j][k];
					last[i][j][k]='R';
				}
			}
		}
	}

	if (!where||min(dp[n-1][n-1][0], dp[n-1][n-1][1])==0) {
		cout << min(dp[n-1][n-1][0], dp[n-1][n-1][1]) << '\n';
		if (dp[n-1][n-1][0]<=dp[n-1][n-1][1])
			backtrack(0);
		else
			backtrack(1);
	}
	else {
		cout << "1\n";
		for (int i=0; i<where; ++i)
			cout << 'D';
		for (int i=0; i<n-1; ++i)
			cout << 'R';
		for (int i=where; i<n-1; ++i)
			cout << 'D';
	}
	return 0;
}