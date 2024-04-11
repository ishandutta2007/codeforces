#include <map>
#include <iostream>
#include <cstring>
#include <vector>
#include <cctype> 
#include <cstdio>
#include <string>
#include <ctime>
#include <cmath>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
//
struct zv {
	int start, len;
};
int N, K;
zv a[4001];
bool cmp(zv z1, zv z2) {
	if (z1.start < z2.start) return true; 
	return false;
};
int res = 0;
int dp[4001][4001];
//
int min(int x, int y) {
	if (x < y) return x;
	return y;
}
//
int main() {
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a[i + 1].start, &a[i + 1].len);
	}
	for (int n = 0; n <= N; n++)
		for (int k = 0; k <= K; k++)
			dp[n][k] = 86401;
	dp[0][0] = 1;
	for (int n = 0; n <= N; n++)
		for (int k = 0; k <= K; k++) {
			if (n + 1 > N) {
				res = max(res, 86401 - dp[n][k]); 
			} else {
				if (a[n + 1].start >= dp[n][k]) {
					res = max(res, a[n + 1].start - dp[n][k]);
					dp[n + 1][k] = min(dp[n + 1][k], a[n + 1].start + a[n + 1].len);
				} else {
					dp[n + 1][k] = min(dp[n + 1][k], dp[n][k] + a[n + 1].len);
				}
			}
			if (k < K) {
				dp[n + 1][k + 1] = min(dp[n + 1][k + 1], dp[n][k]);
				if (n + 1 > N) {
					res = max(res, 86401 - dp[n][k]);
				} else {
					res = max(res, a[n + 1].start - dp[n][k]);
				}
			}
		}
	//
	cout << res << endl;
}