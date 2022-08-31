#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1005, M = 105;
int n, m, c[N], sum;
long double dp[M][M * N], pre[M * N];
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cout.precision(15), cout << fixed;
	cin >> n >> m;
	if(m == 1) return cout << 1 << '\n', 0;
	dp[0][0] = 1;
	L(i, 1, n) {
		cin >> c[i], sum += c[i];
		L(j, 0, i * m) pre[j] = dp[i - 1][j];
		L(j, 1, i * m) pre[j] += pre[j - 1];
		L(j, 1, i * m) {
			dp[i][j] = pre[j - 1] - (j - m - 1 < 0 ? 0 : pre[j - m - 1]);
			if(j >= c[i]) dp[i][j] -= dp[i - 1][j - c[i]];
			dp[i][j] /= m - 1;
		}
	}
	long double ns = 0;
	L(j, 0, sum - 1) 
		ns += dp[n][j];
	cout << ns * (m - 1) + 1 << '\n';
	return 0;
}