#include<bits/stdc++.h>
#define N 210000
#define re register
using namespace std;
int n, m, k, f[N][10], deg[N], used[N], cnt[N];
int can[10][10][10][10];
int sy[N], Ans;
struct edge{
	int fr, to, val;
} e[N];
bool cheak(int sa, int sb, int ga, int gb) {
	for(re int i = 1; i <= n; i++) used[i] = 0; 
	for(re int i = 1; i <= n; i++) 
		if(deg[i] == sa) {
			if(used[e[f[i][sb]].to] == 1) return 1;
			used[e[f[i][sb]].to] = 1;
		}
	if(sa == ga && sb == gb) return 0;
	for(re int i = 1; i <= n; i++) 
		if(deg[i] == ga) {
			if(used[e[f[i][gb]].to] == 1) return 1;
			used[e[f[i][gb]].to] = 1;
		}
	return 0;
}
void dfs(int x) {
	if(x == k + 1) {
		for(re int i = 1; i <= k; i++)
			for(re int j = i; j <= k; j++) 
				if(can[i][sy[i]][j][sy[j]]) return;
		Ans++;
		return;
	}
	for(re int i = 1; i <= x; i++) sy[x] = i, dfs(x + 1);
} 
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(re int i = 1; i <= m; i++) {
		scanf("%d%d%d", &e[i].fr, &e[i].to, &e[i].val);
		f[e[i].fr][++cnt[e[i].fr]] = i;
		deg[e[i].fr]++;
	}
	for(re int sa = 1; sa <= k; sa++) 
		for(re int sb = 1; sb <= sa; sb++) 
			for(re int ga = sa; ga <= k; ga++) 
				for(re int gb = 1; gb <= ga; gb++) 
					can[sa][sb][ga][gb] = cheak(sa, sb, ga, gb);
	dfs(1);
	printf("%d\n", Ans);
	return 0;
}