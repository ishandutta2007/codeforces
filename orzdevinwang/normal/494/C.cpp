#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e5 + 7;
const int M = 5005;
const int inf = 1e9 + 7;
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
	while('0' <= ch && ch <= '9') x = x * 10 + (ch ^ '0'), ch = getchar();
	return x * f;
}
int n, m, a[N];
struct node {
	int l, r; 
	db p;
} f[N];
int arr[N], mx[N], tot, maxa, delta;
db dp[M][M << 1];
vector<int> e[N];
int main() {
	n = read(), m = read();
	L(i, 1, n) a[i] = read(), maxa = max(maxa, a[i]);
	L(i, 1, n) {
		if(a[i] < maxa - 5000) a[i] = 0;
		else a[i] = a[i] + 5000 - maxa;
	}
	delta = maxa - 5000, maxa = 10000;
	L(i, 1, m) {
		f[i].l = read(), f[i].r = read() + 1, scanf("%lf", &f[i].p);
		arr[++tot] = f[i].l, arr[++tot] = f[i].r;
	}
	arr[++tot] = 1, arr[++tot] = n + 1;
	sort(arr + 1, arr + tot + 1);
	tot = unique(arr + 1, arr + tot + 1) - arr - 1;
	L(i, 1, m) 
		f[i].l = lower_bound(arr + 1, arr + tot + 1, f[i].l) - arr, 
		f[i].r = lower_bound(arr + 1, arr + tot + 1, f[i].r) - arr;
	L(i, 1, tot - 1) L(j, arr[i], arr[i + 1] - 1) mx[i] = max(mx[i], a[j]);
	sort(f + 1, f + m + 1, [&](node aa, node bb) {
		return aa.l == bb.l ? aa.r > bb.r : aa.l < bb.l;
	});
	f[0].l = 1, f[0].r = tot;
	L(i, 1, m) R(j, i - 1, 0) if(f[j].l <= f[i].l && f[i].r <= f[j].r) {
		e[j].push_back(i);
		break;
	}
	R(i, m, 0) {
		int maxn = 0;
		L(j, f[i].l, f[i].r - 1) maxn = max(maxn, mx[j]);
		dp[i][maxn] = 1;
		for(int v : e[i]) {
			db qza = 0, qzb = 0;
			L(j, 0, maxa) {
				qza += dp[i][j], qzb += dp[v][j];
				dp[i][j] = qza * dp[v][j] + qzb * dp[i][j] - dp[v][j] * dp[i][j];
			}
		}
		if(i) R(j, maxa, 0) dp[i][j + 1] += f[i].p * dp[i][j], dp[i][j] = dp[i][j] * (1 - f[i].p);
	}
	db ans = 0;
	L(i, 0, maxa) ans += dp[0][i] * i;
	printf("%.10lf\n", ans + delta);
	return 0;
}