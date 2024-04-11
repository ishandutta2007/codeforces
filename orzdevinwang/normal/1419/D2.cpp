#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = j; i <= k; i++)
#define R(i, j, k) for(int i = j; i >= k; i--) 
using namespace std;
const int N = 2e5 + 7;
int T, n, v, a[N], g[N], now, ve[N], tot, cnt;
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	for(int i = 2; i <= n; i += 2) 
		g[i] = a[++now], a[now] = 0;
	for(int i = 1; i <= n; i += 2) {
		while(now < n && a[now + 1] <= g[i + 1]) ++ now;
		++now;
		if(now <= n) g[i] = a[now], a[now] = 0;
	}
	for(int i = 1; i <= n; i++) if(a[i]) ve[++tot] = a[i];
	for(int i = 1; i <= n; i++) if(!g[i]) g[i] = ve[tot--];
	for(int i = 2; i <= n; i += 2) if(g[i] < g[i - 1] && g[i] < g[i + 1]) cnt++;
	printf("%d\n", cnt); 
	for(int i = 1; i <= n; i++) printf("%d ", g[i]);
	return 0;
}