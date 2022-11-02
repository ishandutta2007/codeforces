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

const int N=1e5+5;
int tot=1;

struct Query {long long *res; int c, k;};
struct Tree {
	int dfscnt, pa[N], dfsorder[N], dfn[N], dfr[N];
	std::vector<int> child[N];
	void init() {
		for(int i=2; i<=tot; ++i) child[pa[i]].push_back(i);
		dfs(1);
	}
	void dfs(int u) {
		dfsorder[dfn[u]=dfscnt++]=u;
		for(int v: child[u]) dfs(v);
		dfr[u]=dfscnt;
	}
};
int trans[N][26], end[N], b, blockcnt[N][333], tag[333], cnt[N], sum[333];
char pool[2*N], *s[N];
Tree trie, fail;
long long ans[N];
std::vector<Query> query[N];
void make() {
	static int queue[N];
	int *qhead=queue, *qtail=queue;
	for(int i=0; i<26; ++i) {
		int &v=trans[1][i];
		(v?fail.pa[*qtail++=v]:v)=1;
	}
	while(qhead!=qtail) {
		int u=*qhead++;
		for(int i=0; i<26; ++i) {
			int &v=trans[u][i];
			(v?fail.pa[*qtail++=v]:v)=trans[fail.pa[u]][i];
		}
	}
}
void inc2(int u, int v) {
	cnt[u]+=v;
	sum[u/b]+=v;
}
void inc1(int u) {
	u=fail.dfsorder[u];
	inc2(trie.dfn[u], 1);
	inc2(trie.dfr[u], -1);
}
int main() {
	int n=rd(), q=rd();
	char *mem=pool;
	for(int i=1; i<=n; ++i) {
		int at=1;
		assert(scanf("%s", s[i]=mem)==1);
		mem+=strlen(s[i])+1;
		for(int j=0; s[i][j]; ++j) {
			int &to=trans[at][s[i][j]-'a'];
			if(to==0) trie.pa[to=++tot]=at;
			at=to;
		}
		end[i]=at;
	}
	for(int i=0; i<q; ++i) {
		int l=rd(), r=rd(), k=rd();
		query[l-1].push_back({ans+i, -1, k});
		query[r].push_back({ans+i, 1, k});
	}
	make();
	trie.init();
	fail.init();
	b=sqrt(tot);
	for(int i=1; i<=n; ++i)
		for(int j=end[i]; j; j=trie.pa[j])
			++blockcnt[i][fail.dfn[j]/b];
	for(int i=1; i<=n; ++i) {
		int l=fail.dfn[end[i]], r=fail.dfr[end[i]];
		if(l/b!=r/b) {
			while(l%b!=0) inc1(l++);
			while(r%b!=0) inc1(--r);
			for(int i=l/b; i<r/b; ++i) ++tag[i];
		} else {
			for(int i=l; i<r; ++i) inc1(i);
		}
		for(auto qry: query[i]) {
			int r=trie.dfn[end[qry.k]]+1;
			long long res=0;
			while(r%b!=0) res+=cnt[--r];
			for(int j=0; j<r/b; ++j) res+=sum[j];
			for(int j=0; j<tot/b; ++j) res+=(long long)tag[j]*blockcnt[qry.k][j];
			*qry.res+=qry.c*res;
		}
	}
	for(int i=0; i<q; ++i) printf("%lld\n", ans[i]);
	return 0;
}