#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#define meow(args...) fprintf(stderr, args)
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar()-'0', (c>9)&(c!=253));
	for(a=(b=c==253)?0:c; (c=getchar()-'0')<=9; a=a*10+c);
	return b?-a:a;
}
const int N=1e6;
int (*rd)()=read<int>;
bool instk[N], jury[N], solved;
int head[N], to[N], next[N], dfst, dfn[N], low[N], stk[N], *top=stk;
void dfs(int x) {
	dfn[x]=low[x]=++dfst;
	instk[*top++=x]=true;
	for(int i=head[x]; ~i; i=next[i])
		if(!dfn[to[i]]) {
			dfs(to[i]);
			cmin(low[x], low[to[i]]);
		} else if(instk[to[i]]) cmin(low[x], dfn[to[i]]);
	if(low[x]==dfn[x]) {
		int t;
		do {
			instk[t=*--top]=false;
			jury[t]=!solved;
		} while(x!=t);
		solved=true;
	}
}
void work() {
	int n=rd(), m=rd();
	memset(head, -1, n*sizeof(int));
	for(int i=0; i<m; ++i) {
		int a=rd()-1;
		to[i]=rd()-1;
		next[i]=head[a];
		head[a]=i;
	}
	memset(dfn, 0, n*sizeof(int));
	dfst=0;
	solved=false;
	for(int i=0; i<n; ++i) if(!dfn[i]) dfs(i);
	int j=0;
	for(int i=0; i<n; ++i) j+=jury[i];
	if(j!=n) {
		printf("Yes\n%d %d\n", j, n-j);
		for(int i=0; i<n; ++i) if(jury[i]) printf("%d ", i+1);
		puts("");
		for(int i=0; i<n; ++i) if(!jury[i]) printf("%d ", i+1);
		puts("");
	} else puts("No");
}
int main() {
	int t=rd();
	while(t--) work();
	return 0;
}