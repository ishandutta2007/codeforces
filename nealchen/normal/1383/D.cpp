#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
int n, m, a[251][251], r[251], c[251];
bool nr[250*250+1], nc[250*250+1];
std::vector<std::pair<int, int>> space;
int main() {
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
			scanf("%d", a[i]+j);
			r[i]=std::max(r[i], a[i][j]);
			c[j]=std::max(c[j], a[i][j]);
		}
	}
	for(int i=1; i<=n; ++i) nr[r[i]]=true;
	for(int i=1; i<=m; ++i) nc[c[i]]=true;
	int x=0, y=0, z=0;
	for(int i=n*m; i>=1; --i) {
		if(nr[i] || nc[i]) {
			x+=nr[i];
			y+=nc[i];
			a[x][y]=i;
			if(nr[i]) for(int j=y-1; j>=1; --j) space.push_back({x, j});
			if(nc[i]) for(int j=x-1; j>=1; --j) space.push_back({j, y});
		} else {
			int u, v;
			std::tie(u, v)=space[z++];
			a[u][v]=i;
		}
	}
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j)
			printf("%d%c", a[i][j], " \n"[j==m]);
	}
	return 0;
}