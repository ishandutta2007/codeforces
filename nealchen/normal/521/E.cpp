#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar()-48, c>9&c!=253);
	b=c==253;
	for(a=b?0:c; (c=getchar()-48)<=9; a=a*10+c);
	return b?-a:a;
}
auto rd=read<int>;
auto cmin=[](auto &a, const auto &b) {return b<a?(a=b, true):false;};
auto cmax=[](auto &a, const auto &b) {return a<b?(a=b, true):false;};

const int N=2e5;
int n, cnt, u[N], v[N], fa[2*N], siz[N];
std::vector<int> edge[N], bcce[N];

int dfn[N], low[N], tick, stk[N], *top=stk;
void tj(int v, int back) {
	dfn[v]=low[v]=tick++;
	*top++=v;
	for(int u: edge[v])
		if(u!=back) {
			if(dfn[u]==-1) {
				tj(u, v);
				cmin(low[v], low[u]);
				if(low[u]>=dfn[v]) {
					siz[cnt]=1;
					do {
						fa[*--top]=n+cnt;
						++siz[cnt];
					} while(*top!=u);
					fa[n+cnt++]=v;
				}
			} else cmin(low[v], dfn[u]);
		}
}
char vis[N];
std::vector<int> route;
bool dfs(int v) {
	if(vis[v]==2) return false;
	route.push_back(v);
	if(vis[v]==1) return true;
	vis[v]=2;
	for(int u: edge[v]) if(dfs(u)) return true;
	route.pop_back();
	return false;
}
int main() {
	int m;
	n=rd(), m=rd();
	memset(dfn, -1, n*sizeof(int));
	for(int i=0; i<m; ++i) {
		u[i]=rd()-1;
		v[i]=rd()-1;
		edge[u[i]].push_back(v[i]);
		edge[v[i]].push_back(u[i]);
	}
	for(int i=0; i<n; ++i) if(dfn[i]==-1) tj(i, -1), fa[i]=-1;
	for(int i=0; i<m; ++i) {
		int c=fa[u[i]];
		if(c!=fa[v[i]] && (c==-1 || fa[c]!=v[i])) c=fa[v[i]];
		bcce[c-n].push_back(i);
	}
	for(int i=0; i<cnt; ++i)
		if(bcce[i].size()>siz[i]) {
			int x, y;
			std::vector<int> rho;
			for(int j=0; j<n; ++j) edge[j].clear();
			for(int j: bcce[i]) {
				edge[u[j]].push_back(v[j]);
				edge[v[j]].push_back(u[j]);
			}
			x=fa[n+i];
			for(int las=-1, nex; !vis[x]; las=x, x=nex) {
				vis[x]=1;
				rho.push_back(x);
				nex=edge[x][edge[x][0]==las];
			}
			std::reverse(rho.begin(), rho.end());
			while(rho.back()!=x) vis[rho.back()]=0, rho.pop_back();
			int s=rho.size();
			for(int j=0; j<s; ++j) {
				int cur=rho[j], pre=rho[(j+s-1)%s], nex=rho[(j+1)%s];
				std::remove(edge[cur].begin(), edge[cur].end(), pre);
				edge[cur].pop_back();
				std::remove(edge[cur].begin(), edge[cur].end(), nex);
				edge[cur].pop_back();
			}
			for(int j: bcce[i])
				if(!vis[u[j]]||!vis[v[j]]) {
					edge[u[j]].push_back(v[j]);
					edge[v[j]].push_back(u[j]);
				}
			for(int p: rho)
				if(!edge[p].empty()) {
					x=p;
					break;
				}
			vis[x]=0;
			dfs(x);
			y=route.back();
			int l, r;
			for(l=0; rho[l]!=x; ++l);
			for(r=0; rho[r]!=y; ++r);
			printf("YES\n%d", (r-l+s)%s+1);
			for(int j=l; j!=r; j=(j+1)%s) printf(" %d", rho[j]+1);
			printf(" %d\n%d", y+1, (l-r+s)%s+1);
			for(int j=l; j!=r; j=(j+s-1)%s) printf(" %d", rho[j]+1);
			printf(" %d\n%d", y+1, route.size());
			for(int j: route) printf(" %d", j+1);
			puts("");
			return 0;
		}
	puts("NO");
	return 0;
}