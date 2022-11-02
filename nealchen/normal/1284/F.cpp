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
//const u32 P=;
//u32 &inc(u32 &a, u32 b) {return (a+=b)<P?a:(a-=P);}
//u32 &dec(u32 &a, u32 b) {return (a-=b)&0x80000000?(a+=P):a;}
//u32 sum(u32 a, u32 b) {return inc(a, b);}
//u32 dif(u32 a, u32 b) {return dec(a, b);}

const int N=2.5e5+1;
int n, climb[18][N], *p1=climb[0], p2[N], dep[N], cnt, dfn[N], dfr[N], up[N];
std::vector<int> t1[N], t2[N];
void dfs1(int u, int p, int d) {
	p1[u]=p;
	dep[u]=d;
	dfn[u]=cnt++;
	for(int v: t1[u]) if(v!=p) dfs1(v, u, d+1);
	dfr[u]=cnt;
}
void dfs2(int u, int p) {
	p2[u]=p;
	for(int v: t2[u]) if(v!=p) dfs2(v, u);
}
int root(int u) {return up[u]==u?u:(up[u]=root(up[u]));}
void solve(int u) {
	for(int v: t2[u])
		if(v!=p2[u]) {
			solve(v);
			int w=root(v);
			if(dfn[u]>dfn[w]&&dfn[u]<dfr[w]) {
				int t=w;
				w=u;
				for(int i=18; i--; )
					if(dep[w]-(1<<i)>dep[t]&&root(climb[i][w])!=root(t))
						w=climb[i][w];
			}
			printf("%d %d %d %d\n", p1[w], w, u, v);
			up[w]=root(p1[w]);
		}
}
int main() {
	n=rd();
	for(int i=1; i<n; ++i) {
		int u=rd(), v=rd();
		t1[u].push_back(v);
		t1[v].push_back(u);
	}
	for(int i=1; i<n; ++i) {
		int u=rd(), v=rd();
		t2[u].push_back(v);
		t2[v].push_back(u);
	}
	for(int i=1; i<=n; ++i) up[i]=i;
	dfs1(1, 0, 0);
	dfs2(1, 0);
	for(int i=1; i<18; ++i)
		for(int j=1; j<=n; ++j)
			climb[i][j]=climb[i-1][climb[i-1][j]];
	printf("%d\n", n-1);
	solve(1);
	return 0;
}