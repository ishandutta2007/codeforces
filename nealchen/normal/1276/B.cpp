#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
inline bool cmin(auto &a, const auto &b) {return b<a?(a=b, true):false;}
inline bool cmax(auto &a, const auto &b) {return a<b?(a=b, true):false;}
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar()-'0', (c>9)&(c!=253));
	for(a=(b=c==253)?0:c; (c=getchar()-'0')<=9; a=a*10+c);
	return b?-a:a;
}
auto rd=read<int>;
const int N=2e5+5;
std::vector<int> e[N], clt[N*2];
int n, n0, dfn[N], dfclk, low[N], siz[N*2], stk[N], *stktop;
void tarjan(int x, int f) {
	static int low[N], stk[N], *stktop=stk;
	dfn[x]=low[x]=++dfclk;
	*stktop++=x;
	for(int y: e[x]) {
		if(!dfn[y]) {
			tarjan(y, x);
			cmin(low[x], low[y]);
			if(low[y]>=dfn[x]) {
				int u;
				clt[++n0].clear();
				clt[x].push_back(n0);
				clt[n0].push_back(x);
				do {
					u=*--stktop;
					clt[u].push_back(n0);
					clt[n0].push_back(u);
				} while(u!=y);
			}
		} else if(y!=f) cmin(low[x], dfn[y]);
	}
}
void dfs(int x, int fa) {
	siz[x]=(x<=n);
	for(int y: clt[x])
		if(y!=fa) {
			dfs(y, x);
			siz[x]+=siz[y];
		}
}
int main() {
	int t=rd();
	while(t--) {
		n=n0=rd();
		int m=rd(), a=rd(), b=rd();
		long long ans;
		dfclk=0;
		memset(dfn+1, 0, n*sizeof(int));
		stktop=stk;
		for(int i=1; i<=n; ++i) e[i].clear(), clt[i].clear();
		for(int i=0; i<m; ++i) {
			int u=rd(), v=rd();
			e[u].push_back(v);
			e[v].push_back(u);
		}
		tarjan(1, 0);
		dfs(a, 0);
		ans=siz[b]-1;
		dfs(b, 0);
		ans*=siz[a]-1;
		std::cout<<ans<<"\n";
	}
	return 0;
}