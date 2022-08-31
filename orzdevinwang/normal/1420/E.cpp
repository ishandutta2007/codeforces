// George1123 /qiang, SegmentTree /no 
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 84;
const int M = N * (N - 1) / 2;
int m, n, f[N], g[N], cnt, dp[2][M][N << 1], ans[M]; // dp[][][] : sum 
// = a, = b 
// sum += ax - bx + x^2 - x
//  sum  
int get(int x) { return x * (x - 1) / 2; }
int main() {
	scanf("%d", &m), n = 1;
	L(i, 1, m) {
		scanf("%d", &f[i]);
		if(f[i] == 1) ++n;
		else g[n] ++, ++cnt;
	}
	memset(dp[1], 15, sizeof(dp[1]));
	dp[1][0][g[1] + cnt] = 0;
	L(t, 2, n) {
		int now = (t & 1);
		memset(dp[now], 15, sizeof(dp[now]));
		L(i, 0, get(m)) {
			L(j, -cnt, cnt) {
				int gg = dp[now ^ 1][i][j + cnt]; // j - k >= 0 k <= j
				if(gg > get(cnt)) continue;
				L(k, 0, cnt) dp[now][i + k][g[t] - k + cnt] = min(dp[now][i + k][g[t] - k + cnt], gg + get(j + k));
				L(k, 0, min(cnt - g[t], j)) dp[now][i + abs(k)][g[t] + k + cnt] = min(dp[now][i + k][g[t] + k + cnt], gg + get(j - k));
			}
		}
	}
	L(i, 0, get(m)) ans[i] = 1e9;
	L(i, 0, get(m)) L(j, 0, cnt) ans[i] = min(ans[i], dp[n & 1][i][j + cnt] + get(j));
	L(i, 1, get(m)) ans[i] = min(ans[i], ans[i - 1]);
	L(i, 0, get(m)) printf("%d ", get(cnt) - ans[i]);
	puts("");
	return 0;
}