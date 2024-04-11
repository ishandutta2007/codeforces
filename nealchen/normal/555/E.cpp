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
//const u32 P=;
//inline u32 &inc(u32 &a, u32 b) {return (a+=b)<P?a:(a-=P);}
//inline u32 &dec(u32 &a, u32 b) {return (a-=b)&0x80000000?(a+=P):a;}
//inline u32 sum(u32 a, u32 b) {return (a+=b)<P?a:a-P;}
//inline u32 dif(u32 a, u32 b) {return (a-=b)&0x80000000?a+P:a;}
//u64 power(u64 a, int b) {
//	u64 ans=1;
//	for(; b; a=a*a%P, b/=2) if(b&1) ans=ans*a%P;
//	return ans;
//}
const int N=2e5+1, M=N*2;
int n, m, q, to[M], head[N], next[M];
int dfsn, dfn[N], low[N], stack[N], *stack_top=stack, tot, bcc[N];
int size[N], dep[N], pa[N], prefer[N], top[N], root[N];
void dfs(int x, int ban) {
	dfn[x]=low[x]=++dfsn;
	*stack_top++=x;
	for(int i=head[x]; ~i; i=next[i]) {
		if(i==ban) continue;
		if(!dfn[to[i]]) {
			dfs(to[i], i^1);
			cmin(low[x], low[to[i]]);
		} else cmin(low[x], dfn[to[i]]);
	}
	if(dfn[x]==low[x]) {
		++tot;
		do {bcc[*--stack_top]=tot;} while(*stack_top!=x);
	}
}
void dfs1(int x, int f, int d) {
	pa[x]=f, dep[x]=d, size[x]=1, root[x]=f?root[f]:x;
	for(int i=head[x], mx=0; ~i; i=next[i])
		if(to[i]!=f) {
			dfs1(to[i], x, d+1);
			size[x]+=size[to[i]];
			if(cmax(mx, size[to[i]])) prefer[x]=to[i];
		}
}
void dfs2(int x, int t) {
	top[x]=t;
	for(int i=head[x]; ~i; i=next[i]) if(to[i]!=pa[x]) dfs2(to[i], to[i]==prefer[x]?t:to[i]);
}
int lca(int x, int y) {
	while(top[x]!=top[y]) if(dep[top[x]]<dep[top[y]]) y=pa[top[y]]; else x=pa[top[x]];
	return dep[x]<dep[y]?x:y;
}
int cnt[N][2], cur[2];
void solve(int x) {
	int save[2];
	for(int i=0; i<2; ++i) save[i]=cur[i], cur[i]+=cnt[x][i];
	for(int i=head[x]; ~i; i=next[i]) if(to[i]!=pa[x]) solve(to[i]);
	if(save[0]!=cur[0]&&save[1]!=cur[1]) puts("No"), exit(0);
}
int main() {
	n=rd(), m=rd(), q=rd();
	memset(head+1, -1, n*sizeof(int));
	for(int i=0; i<m; ++i) {
		int u=rd(), v=rd();
		to[2*i]=v, next[2*i]=head[u], head[u]=2*i;
		to[2*i+1]=u, next[2*i+1]=head[v], head[v]=2*i+1;
	}
	for(int i=1; i<=n; ++i) if(!dfn[i]) dfs(i, -1);
	memset(head+1, -1, n*sizeof(int));
	for(int i=0; i<m; ++i) {
		int &u=to[2*i+1], &v=to[2*i];
		u=bcc[u], v=bcc[v];
		if(u==v) continue;
		next[2*i]=head[u], head[u]=2*i;
		next[2*i+1]=head[v], head[v]=2*i+1;
	}
	for(int i=1; i<=tot; ++i) if(!size[i]) dfs1(i, 0, 0), dfs2(i, i);
	for(int i=0; i<q; ++i) {
		int s=bcc[rd()], d=bcc[rd()];
		if(root[s]!=root[d]) {
			puts("No");
			return 0;
		}
		int up=lca(s, d);
		++cnt[s][0], ++cnt[d][1], --cnt[up][0], --cnt[up][1];
	}
	for(int i=1; i<=tot; ++i) if(!pa[i]) solve(i);
	puts("Yes");
	return 0;
}