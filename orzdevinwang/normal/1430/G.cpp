#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 20;
const int M = (1 << 19);
const int inf = 1e9 + 7;
int n, m, G[N][N], calc[M], dp[M], pre[M], ans[N], P[M];
vector<int> ve[N];
int main() {
	scanf("%d%d", &n, &m);
	L(i, 1, m) {
		int u, v, val; scanf("%d%d%d", &u, &v, &val);
		ve[u].push_back(v), G[u][v] = 1;
		P[1 << (v - 1)] |= (1 << (u - 1));
		int t = (((1 << n) - 1) ^ (1 << (u - 1)) ^ (1 << (v - 1)));
		for(int k = t; ; k = ((k - 1) & t)) {
			calc[k | (1 << (u - 1))] += val;
			if(k == 0) break;
		}
	} 
	L(i, 0, (1 << n) - 1) P[i] = (P[i & -i] | P[i ^ (i & -i)]); 
	fill(dp + 1, dp + (1 << n), inf);
	L(i, 1, (1 << n) - 1) {
		for(int j = i; ; j = ((j - 1) & i)) {
			if(((i ^ j) & P[j]) == P[j] && dp[i ^ j] + calc[i] < dp[i]) dp[i] = dp[i ^ j] + calc[i], pre[i] = (i ^ j);
			if(j == 0) break; 
		}
	}
	for(int k = (1 << n) - 1; k; k = pre[k]) L(i, 1, n) if(k & (1 << (i - 1))) ans[i] ++;
	L(i, 1, n) printf("%d ", ans[i]);
	puts("");
	return 0;
}