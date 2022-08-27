#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j; i <= k; i++) 
#define R(i, j, k) for(int i = j; i >= k; i--)
#define ll long long
#define db double
using namespace std;
const int N = 2e5 + 7;
int n, m, a[N], b[N], f[N], cnt;
ll ans;
int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
struct edge {
	int fr, to, val;
} e[N];
bool cmp(edge aa, edge bb) {
	return aa.val > bb.val;
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n + m; i++) f[i] = i;
	L(i, 1, n) scanf("%d", &a[i]);
	L(i, 1, m) scanf("%d", &b[i]);
	L(i, 1, n) {
		int pp;
		scanf("%d", &pp);
		while(pp--) e[++cnt].fr = i + m, scanf("%d", &e[cnt].to), e[cnt].val = a[i] + b[e[cnt].to], ans += e[cnt].val;
	}
	sort(e + 1, e + cnt + 1, cmp);
	L(i, 1, cnt) if(find(e[i].fr) != find(e[i].to)) f[find(e[i].fr)] = e[i].to, ans -= e[i].val; 
	printf("%lld\n", ans);
	return 0;
}