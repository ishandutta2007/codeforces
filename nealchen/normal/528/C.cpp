#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
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
auto rd=read<int>;
typedef unsigned u32;
typedef long long s64;
typedef unsigned long long u64;

const int N=1e5+1, M=5e5;
int n, e, deg[N], to[M], head[N], next[M];
bool vis[M/2], rev;
void add(int u, int v) {
	++deg[u], ++deg[v];
	to[e]=v, next[e]=head[u], head[u]=e++;
	to[e]=u, next[e]=head[v], head[v]=e++;
}
void dfs(int u) {
	for(int &i=head[u]; i!=-1; )
		if(!vis[i/2]) {
			int j=i;
			i=next[i];
			vis[j/2]=true;
			dfs(to[j]);
			printf("%d %d\n", to[j^!rev], to[j^rev]);
			rev^=1;
		} else i=next[i];
}
int main() {
	n=rd();
	memset(head+1, -1, n*sizeof(int));
	for(int m=rd(); m--; ) add(rd(), rd());
	for(int i=1, j; ; i=j+1) {
		while(i<=n&&deg[i]%2==0) ++i;
		for(j=i+1; j<=n&&deg[j]%2==0; ++j);
		if(j<=n) add(i, j); else break;
	}
	if(e%4==2) add(1, 1);
	printf("%d\n", e/2);
	dfs(1);
	return 0;
}