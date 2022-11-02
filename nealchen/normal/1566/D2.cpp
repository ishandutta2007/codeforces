#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
int vis[300][300];
void work() {
	int n, m;
	scanf("%d%d", &n, &m);
	std::vector<int> a(n*m), pos(n*m);
	std::vector<std::pair<int, int>> hub(n*m);
	for(int i=0; i<n*m; ++i) {
		scanf("%d", &a[i]);
		hub[i]={a[i], i};
	}
	std::sort(hub.begin(), hub.end());
	for(int i=0; i<n*m; ++i) pos[hub[i].second]=i;
	for(int i=0; i<n; ++i) memset(vis[i], -1, m*sizeof(int));
	int ans=0;
	for(int i=0; i<n*m; ++i) {
		int x=pos[i]/m, y=pos[i]%m;
		for(int j=0; j<y; ++j) {
			if(vis[x][j]!=-1) ans+=a[vis[x][j]]!=a[i];
		}
		vis[x][y]=i;
	}
	printf("%d\n", ans);
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--) work();
	return 0;
}