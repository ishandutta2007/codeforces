#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
const int N=1e5+5;
int n, pa[N], f[20];
char a[N], b[N];
bool g[1<<20];
int find(int x) {
	return pa[x]==x?x:(pa[x]=find(pa[x]));
}
void work() {
	scanf("%d%s%s", &n, a, b);
	memset(f, 0, sizeof(f));
	int c=20;
	for(int i=0; i<20; ++i) pa[i]=i;
	for(int i=0; i<n; ++i) {
		int u=a[i]-'a', v=b[i]-'a';
		f[u]|=1<<v;
		u=find(u);
		v=find(v);
		if(u!=v) {
			pa[u]=v;
			--c;
		}
	}
	memset(g, 0, sizeof(g));
	g[0]=true;
	int max=0;
	for(int i=0; i<(1<<20); ++i) {
		if(!g[i]) continue;
		for(int j=0; j<20; ++j) {
			if(~i>>j&1 && (i&f[j])==0) g[i|1<<j]=true;
		}
		max=std::max(max, __builtin_popcount(i));
	}
	printf("%d\n", 40-c-max);
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--) work();
	return 0;
}