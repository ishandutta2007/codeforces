#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
int n, x[2500], y[2500];
double dp[2500][2500][2];
double dis(int a, int b) {
	return sqrt((ll)(x[a] - x[b]) * (x[a] - x[b]) + (ll)(y[a] - y[b]) * (y[a] - y[b]));
}
int f(int x) { return x % n; }
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
	for (int i = 0; i < n; i++) dp[i][i][0] = dp[i][i][1] = 0.0;
	for (int i = 1; i < n; i++)
		for (int j = 0; j < n; j++) {
			dp[j][f(j + i)][0] = max(dp[f(j + 1)][f(j + i)][0] + dis(j, f(j + 1)), dp[f(j + 1)][f(j + i)][1] + dis(j, f(j + i)));
			dp[j][f(j + i)][1] = max(dp[j][f(j + i - 1)][0] + dis(j, f(j + i)), dp[j][f(j + i - 1)][1] + dis(f(j + i), f(j + i - 1)));
		}
	double mx = -1;
	for (int i = 0; i < n; i++) mx = max(max(dp[f(i + 1)][i][0], dp[f(i + 1)][i][1]), mx);
	cout.precision(12);
	cout << mx << endl;
}