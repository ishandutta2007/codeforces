#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
const int N=2e5+5;
int head[N], next[2*N], to[2*N], pa[N], ans;
bool dfs(int x) {
	int cnt=0;
	for(int i=head[x]; i; i=next[i]) {
		if(to[i]!=pa[x]) {
			pa[to[i]]=x;
			cnt+=dfs(to[i]);
		}
	}
	if(cnt==0) return true;
	ans+=cnt-1;
	return false;
}
void work() {
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) head[i]=0;
	for(int i=1, j=2; i<n; ++i) {
		auto add_edge=[&j](int x, int y) {next[j]=head[x], to[j]=y, head[x]=j++;};
		int u, v;
		scanf("%d%d", &u, &v);
		add_edge(u, v);
		add_edge(v, u);
	}
	ans=1;
	dfs(1);
	printf("%d\n", ans);
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--) work();
	return 0;
}