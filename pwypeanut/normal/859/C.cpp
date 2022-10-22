#include <bits/stdc++.h>
using namespace std;

int N;
long long arr[55];
pair<long long, long long> dp[55][2];

pair<long long, long long> f(int x, int p) {
	if (dp[x][p] != make_pair(-1ll, -1ll)) return dp[x][p];
	if (x == N) return make_pair(0, 0);
	if (p == 0) {
		pair<long long, long long> a = f(x+1, p);
		a.second += arr[x];
		pair<long long, long long> b = f(x+1, !p);
		b.first += arr[x];
		if (a.first > b.first) return dp[x][p] = a;
		else return dp[x][p] = b;
	} else {
		pair<long long, long long> a = f(x+1, p);
		a.first += arr[x];
		pair<long long, long long> b = f(x+1, !p);
		b.second += arr[x];
		if (a.second > b.second) return dp[x][p] = a;
		else return dp[x][p] = b;
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%lld", &arr[i]);
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < 2; j++) {
			dp[i][j] = make_pair(-1, -1);
		}
	}
	printf("%lld %lld\n", f(0, 1).first, f(0, 1).second);
	
}