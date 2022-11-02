#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
typedef unsigned u32;
typedef long long s64;
typedef unsigned long long u64;
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar()-48, (c>9)&(c!=253));
	for(a=(b=c==253)?0:c; (c=getchar()-48)<=9; a=a*10+c);
	return b?-a:a;
}
int (*rd)()=read<int>;

const int N=1e5+1;
int l[N], r[N], color[N];
std::vector<std::pair<int, int>> edge[N];
void gg() {
	puts("IMPOSSIBLE");
	exit(0);
}
void dfs(int x, int c) {
	if(color[x]) {
		if(color[x]!=c+1) gg();
		return;
	}
	color[x]=c+1;
	for(auto e: edge[x]) dfs(e.first, c^e.second);
}
int main() {
	int tl=rd(), tr=rd(), n=rd(), m=rd();
	for(int i=1; i<=n; ++i) l[i]=rd(), r[i]=rd();
	while(m--) {
		int u=rd(), v=rd();
		edge[u].emplace_back(v, 1);
		edge[v].emplace_back(u, 1);
	}
	int n1=*std::max_element(l+1, l+n+1), n2=*std::min_element(r+1, r+n+1);
	if(n1+n2<tl) n1=tl-n2;
	if(n1+n2>tr) n2=tr-n1;
	if(n1<0||n2<0||n1+n2<tl||n1+n2>tr) gg();
	for(int i=1; i<=n; ++i) {
		if(n1<l[i]||n1>r[i]) {
			edge[i].emplace_back(0, 1);
			edge[0].emplace_back(i, 1);
		}
		if(n2<l[i]||n2>r[i]) {
			edge[i].emplace_back(0, 0);
			edge[0].emplace_back(i, 0);
		}
	}
	for(int i=0; i<=n; ++i) if(color[i]==0) dfs(i, 0);
	printf("POSSIBLE\n%d %d\n", n1, n2);
	for(int i=1; i<=n; ++i) printf("%d", color[i]);
	puts("");
	return 0;
}