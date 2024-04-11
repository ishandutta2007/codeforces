#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
bool vis[300][300];
void work() {
	int n, m;
	scanf("%d%d", &n, &m);
	std::vector<std::pair<int, int>> a(n*m);
	for(int i=0; i<n*m; ++i) {
		scanf("%d", &a[i].first);
		a[i].second=-i;
	}
	std::sort(a.begin(), a.end());
	for(int i=0; i<n*m; ++i) {
		a[i].first=-a[i].second;
		a[i].second=i;
	}
	for(int i=0; i<n; ++i) memset(vis[i], 0, m);
	std::sort(a.begin(), a.end());
	int ans=0;
	for(int i=0; i<n*m; ++i) {
		int pos=a[i].second, x=pos/m, y=pos%m;
		for(int j=0; j<y; ++j) ans+=vis[x][j];
		vis[x][y]=true;
	}
	printf("%d\n", ans);
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--) work();
	return 0;
}