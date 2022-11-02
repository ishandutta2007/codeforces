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
int (*rd)()=read<int>;
typedef unsigned u32;
typedef long long s64;
typedef unsigned long long u64;

struct Node {
	int max;
	Node *par, *tr[26];
};
const int N=1e6+5;
int n, lv, climb[20][N], tick, dfn[N], dfr[N], off, max[1<<21], f[N];
char s[N];
Node node[N];
std::vector<int> child[N];
void dfs(int u) {
	dfn[u]=++tick;
	for(int i=0; i<child[u].size(); ++i) dfs(child[u][i]);
	dfr[u]=tick;
}
int sol(int u, int len) {
	int res=0;
	u=n-u;
	for(int i=lv; i>=0; --i) {
		int v=climb[i][u];
		if(node[v].max>=len) u=v;
	}
	for(int l=dfn[u]-1+off, r=dfr[u]+1+off; l^r^1; l>>=1, r>>=1) {
		if(~l&1) cmax(res, max[l^1]);
		if( r&1) cmax(res, max[r^1]);
	}
	return res;
}
int main() {
	assert(scanf("%d%s", &n, s)==2);
	int tot=n;
	for(int i=1; i<=n; ++i) {
		int c=s[n-i]-'a';
		Node *me=node+i, *p=node+i-1, *q, *r;
		me->max=i;
		for(; p&&p->tr[c]==NULL; p=p->par) p->tr[c]=me;
		if(p==NULL) {
			me->par=node;
			continue;
		}
		q=p->tr[c];
		if(q->max==p->max+1) {
			me->par=q;
			continue;
		}
		r=node+(++tot);
		*r=*q;
		r->max=p->max+1;
		q->par=me->par=r;
		for(; p&&p->tr[c]==q; p=p->par) p->tr[c]=r;
	}
	for(int i=1; i<=tot; ++i) {
		climb[0][i]=node[i].par-node;
		child[climb[0][i]].push_back(i);
	}
	lv=31-__builtin_clz(tot);
	for(int i=1; i<=lv; ++i)
		for(int j=1; j<=tot; ++j)
			climb[i][j]=climb[i-1][climb[i-1][j]];
	dfs(0);
	off=1<<32-__builtin_clz(tot+2);
	int ans=0;
	for(int i=n, r=n; i--; ) {
		while(r-i>1) {
			int len=r-i-1;
			if(sol(i, len)>=len||sol(i+1, len)>=len) break;
			--r;
			for(int j=dfn[n-r]+off; cmax(max[j], f[r]); j/=2);
		}
		cmax(ans, f[i]=r-i);
	}
	printf("%u\n", ans);
	return 0;
}