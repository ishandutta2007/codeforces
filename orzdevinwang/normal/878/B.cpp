#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 2e5 + 7;
int n, sum, m, k, a[N], col[N], g[N], tot;
ll ans = 0;
int main() {
	scanf("%d%d%d", &n, &k, &m);
	L(i, 1, n) scanf("%d", &a[i]);
	L(i, 1, n) {
		if(a[i] != col[tot]) ++tot, col[tot] = a[i], g[tot] = 1;
		else ++ g[tot];
		g[tot] %= k;
		if(tot && !g[tot]) --tot;
	}
	g[tot] %= k;
	if(tot && !g[tot]) --tot;

	L(i, 1, tot) sum += g[i];
	ans = (ll) sum * m;
	L(i, 1, (tot + 1) / 2) {
		if(col[i] == col[tot - i + 1]) {
			if(i == (tot + 1) / 2) {
				assert(tot % 2 == 1);
				int ys = (ll) g[i] * m % k;
				if(ys == 0) return puts("0"), 0;
				printf("%d\n", sum - g[i] + ys);
				return 0;
			}
			else {
				if(g[i] + g[tot - i + 1] == k) ans -= (ll) (m - 1) * k;
				else {
					int tmp = (g[i] + g[tot - i + 1]) / k * k;
					ans -= (ll) tmp * (m - 1);
					break;
				}
			}
		}
		else break;
	}
	printf("%lld\n", ans);
	return 0;
}