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

const int N=5e4+1;
int n, m, tot, to[2*N], c[N], t[N], real[N];
int dfs_n, dfn[6*N], low[6*N], stack[6*N], *top=stack, out_n, out[6*N];
std::vector<int> e[N], edge[6*N];
std::unordered_map<int, int> last;
void dfs(int u) {
	dfn[u]=low[u]=++dfs_n;
	*top++=u;
	for(int v: edge[u]) {
		if(!dfn[v]) {
			dfs(v);
			cmin(low[u], low[v]);
		} else if(!out[v]) cmin(low[u], dfn[v]);
	}
	if(dfn[u]==low[u]) {
		int v;
		++out_n;
		do {
			v=*--top;
			out[v]=out_n;
		} while(v!=u);
	}
}
bool check(int lim) {
	dfs_n=out_n=0;
	memset(dfn, 0, 6*m*sizeof(int));
	memset(out, 0, 6*m*sizeof(int));
	for(int i=0; i<m; ++i) if(t[i]>lim) edge[m+i].push_back(i);
	for(int i=0; i<6*m; ++i) if(!dfn[i]) dfs(i);
	for(int i=0; i<m; ++i) if(t[i]>lim) edge[m+i].pop_back();
	for(int i=0; i<m; ++i) if(out[i]==out[m+i]) return false;
	return true;
}
int main() {
	n=rd(), m=rd();
	for(int i=0; i<m; ++i) {
		to[2*i+1]=rd(), to[2*i]=rd(), c[i]=rd(), t[i]=real[i]=rd();
		e[to[2*i+1]].push_back(2*i);
		e[to[2*i]].push_back(2*i+1);
	}
	std::sort(real, real+m);
	tot=std::unique(real, real+m)-real;
	for(int i=0; i<m; ++i) t[i]=std::lower_bound(real, real+tot, t[i])-real;
	for(int i=1; i<=n; ++i) {
		last.clear();
		for(int j: e[i]) {
			auto it=last.find(c[j/2]);
			if(it!=last.end()) {
				int &L=it->second;
				if(L==-1) {
					puts("No");
					return 0;
				}
				edge[j/2].push_back(m+L);
				edge[L].push_back(m+j/2);
				L=-1;
			} else last.emplace(c[j/2], j/2);
		}
	}
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<e[i].size(); ++j) {
			int u=e[i][j-1], v=e[i][j];
			edge[2*m+u].push_back(2*m+v);
			edge[4*m+v].push_back(4*m+u);
			edge[m+u/2].push_back(2*m+v);
			edge[m+v/2].push_back(4*m+u);
		}
		for(int j: e[i]) {
			edge[2*m+j].push_back(j/2);
			edge[4*m+j].push_back(j/2);
		}
	}
	int l=0, r=tot;
	if(check(-1)) {
		puts("Yes\n0 0");
		return 0;
	}
	while(l!=r) {
		int mid=(l+r)/2;
		if(check(mid)) r=mid; else l=mid+1;
	}
	if(l==tot) {
		puts("No");
	} else {
		std::vector<int> ans;
		check(l);
		for(int i=0; i<m; ++i) if(out[i+m]<out[i]) ans.push_back(i+1);
		printf("Yes\n%d %d\n", real[l], (int)ans.size());
		for(int x: ans) printf("%d ", x);
		puts("");
	}
	return 0;
}