#include <map>
#include <set>
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
long long n, l, k;
double p[205];
int su[205];
int pi;
double ans = 0.0;
double dp[205][205][420];
//
int main() {
	//freopen("Input.txt", "r", stdin);
	//freopen("Output.txt", "w", stdout);
	//
	scanf("%d %d %d", &n, &l, &k);
	dp[0][0][205+min(k, n)]=1.0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &pi);
		p[i + 1] = (pi+0.0) / 100.0;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &pi);
		su[i + 1] = pi;
	}
	for (int i = 1; i <= n; i++) {
		for (int win = 0; win <= n; win++)
			for (int can = 1; can < 410; can++)
				if (su[i] == -1) {
					dp[i][win + 1][can - 1] += p[i] * dp[i-1][win][can];
					dp[i][win][can] += (1.0-p[i]) * dp[i-1][win][can];
				} else {
					int can2 = can + su[i];
					if (can2 > 409) can2 = 409;
					dp[i][win + 1][can2] += p[i] * dp[i - 1][win][can];
					dp[i][win][can] += (1.0 - p[i]) * dp[i - 1][win][can];
				}
	}
	for (int win = l; win <= n; win++)
		for (int can = 205; can <= 409; can++)
			ans += dp[n][win][can];
	printf("%.15lf\n", ans);
}