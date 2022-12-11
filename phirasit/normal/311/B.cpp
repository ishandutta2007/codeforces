#include <stdio.h>
#include <vector>
#include <limits.h>
#include <algorithm>

#define N 100010
#define K 110

using namespace std;

typedef struct {
	long long m, c;
}Line;

vector<long long> V;
vector<Line> curve[K];

long long dp[N][K];
long long S[N];

int dis[N];
int n, m, p;

double find_x(Line L1, Line L2) {
	double dm = L1.m - L2.m, dc = L2.c - L1.c;
	return dc / dm;
}
void add(int j, long long c, long long m) {
	Line L;
	L.c = c;
	L.m = m;
	int sz = curve[j].size();
	while(sz >= 2 && find_x(L, curve[j][sz-1]) <= find_x(L, curve[j][sz-2])) {
		curve[j].pop_back();
		sz--;
	}
	curve[j].push_back(L);
}
long long calc(Line L, long long x) {
	return x * L.m + L.c;
}
long long query(int j, long long v) {
	int a = 0, b = curve[j].size() - 1;
	while(a < b) {
		int mid = (a + b) / 2;
		if(calc(curve[j][mid], v) <= calc(curve[j][mid+1], v)) {
			b = mid;
		}else {
			a = mid + 1;
		}
	}
	return calc(curve[j][a], v);
}
int main() {
	scanf("%d%d%d", &n, &m, &p);
	dis[1] = 0;
	for(int i = 2;i <= n;i++) {
		scanf("%d", &dis[i]);
		dis[i] += dis[i-1];
	}
	for(int i = 0;i < m;i++) {
		int h, t;
		scanf("%d%d", &h, &t);
		V.push_back(t - dis[h]);
	}
	sort(V.begin(), V.end());
	for(int i = 0;i < m;i++) {
		S[i] = V[i] + (i == 0 ? 0 : S[i-1]);
	}
	for(int j = 0;j <= p;j++) {
		add(j, 0, 0);
	}
	for(int i = 0;i < m;i++) {
		for(int j = 1;j <= p;j++) {
			dp[i][j] = V[i] * (i+1) - S[i] + query(j-1, V[i]);
			add(j, dp[i][j] + S[i], -(i+1));
		}
	}
	printf("%I64d\n", dp[m-1][p]);
	return 0;
}
/*
dp[i][j] = min k < i (dp[k][j-1] + V[i] * (i - k) - (S[i] - S[k]))
dp[i][j] = V[i] * i - S[i] + min k < i (dp[k][j-1] + S[k] - k * V[i])
*/