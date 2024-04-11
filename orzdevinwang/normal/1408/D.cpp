#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j; i <= k; i++) 
#define R(i, j, k) for(int i = j; i >= k; i--)
#define ll long long
#define db double
using namespace std;
const int N = 2e3 + 7;
const int MAXN = 2e6;
int T, n, m, a[N], b[N], c[N], d[N], ans = 1e9;
int cnt[MAXN + 10]; // up i must go cnt[i] step
int main() {
	scanf("%d%d", &n, &m);
	L(i, 1, n) scanf("%d%d", &a[i], &b[i]);
	L(i, 1, m) scanf("%d%d", &c[i], &d[i]);
	L(i, 1, n) L(j, 1, m) {
		int la = c[j] - a[i];
		int lb = d[j] - b[i];
		if(la >= 0) cnt[la] = max(cnt[la], lb + 1);
	}
	R(i, MAXN, 1) cnt[i - 1] = max(cnt[i - 1], cnt[i]);
	L(i, 0, MAXN) ans = min(ans, i + cnt[i]);
	printf("%d\n", ans);
	return 0;
}