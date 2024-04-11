#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1000, M=1e9+7;
int n, k;
ll dp[mxN+1][mxN+1][5];

/* we only care about a[i] and a[i-1]
 * case 0: a[i]!=i-1 and a[i-1]!=i and a[i]!=i
 * case 1: a[i]=i-1
 * case 2: a[i-1]=i
 * case 3: a[i]=i-1 and a[i-1]=i
 * case 4: a[i]=i
 */

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	dp[1][0][0]=1;
	dp[2][0][4]=dp[2][2][3]=1;
	for (int i=2; i<n; ++i) {
		for (int j=0; j<=i; ++j) {
			for (int k=0; k<5; ++k)
				dp[i][j][k]%=M;
			dp[i+1][j][4]=dp[i][j][0]+dp[i][j][1]+dp[i][j][2]+dp[i][j][3]+dp[i][j][4]; // a[i+1]=i+1
			if (dp[i][j][0]) {
				dp[i+1][j+1][2]+=dp[i][j][0]; // swap(a[i], a[i+1])
				dp[i+1][j+1][1]+=dp[i][j][0]; // swap(i, i+1)
				dp[i+1][j][0]+=(i-j-2)*dp[i][j][0];
				dp[i+1][j-1][0]+=j*dp[i][j][0];
			}
			if (dp[i][j][1]) {
				dp[i+1][j][2]+=dp[i][j][1];
				dp[i+1][j+1][1]+=dp[i][j][1];
				dp[i+1][j][0]+=(i-j-1)*dp[i][j][1];
				dp[i+1][j-1][0]+=(j-1)*dp[i][j][1];
			}
			if (dp[i][j][2]) {
				dp[i+1][j+1][2]+=dp[i][j][2];
				dp[i+1][j][1]+=dp[i][j][2];
				dp[i+1][j][0]+=(i-j-1)*dp[i][j][2];
				dp[i+1][j-1][0]+=(j-1)*dp[i][j][2];
			}
			if (dp[i][j][3]) {
				dp[i+1][j][2]+=dp[i][j][3];
				dp[i+1][j][1]+=dp[i][j][3];
				dp[i+1][j][0]+=(i-j)*dp[i][j][3];
				dp[i+1][j-1][0]+=(j-2)*dp[i][j][3];
			}
			if (dp[i][j][4]) {
				dp[i+1][j+2][3]+=dp[i][j][4];
				dp[i+1][j][0]+=(i-j-1)*dp[i][j][4];
				dp[i+1][j-1][0]+=j*dp[i][j][4];
			}
		}
	}
	cout << (dp[n][k][0]+dp[n][k][1]+dp[n][k][2]+dp[n][k][3]+dp[n][k][4])%M;
	return 0;
}