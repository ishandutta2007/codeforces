#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define meow(args...) fprintf(stderr, args)
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
struct Edge {
	int to;
	Edge *next;
};
struct Pair {
	int key, val;
	bool operator<(const Pair &o) const {return key<o.key;}
};
int size[1001], cur, step;
Edge e[1998], *head[1001];
Pair s[1001];
void dfs(int x, int fa) {
	Edge *p;
	size[x]=1;
	for(p=head[x]; p; p=p->next)
		if(p->to!=fa) {
			dfs(p->to, x);
			size[x]+=size[p->to];
		}
}
void answer(int x, int fa, int faw) {
	int w=cur+=step;
	Edge *p;
	printf("%d %d %d\n", x, fa, w-faw);
	for(p=head[x]; p; p=p->next)
		if(p->to!=fa)
			answer(p->to, x, w);
}
int main() {
	int n, i, g, ns=0, sum=0, mindif, par=0;
	Edge *p=e;
	assert(scanf("%d", &n)==1);
	for(i=1; i<n; ++i) {
		int u, v;
		assert(scanf("%d%d", &u, &v)==2);
		*p=(Edge){v, head[u]}, head[u]=p++;
		*p=(Edge){u, head[v]}, head[v]=p++;
	}
	dfs(1, 0);
	for(g=1; g<=n; ++g) {
		bool ok=size[g]*2>=n;
		for(p=head[g]; p&&ok; p=p->next) ok&=size[p->to]>size[g]||size[p->to]*2<=n;
		if(ok) break;
	}
	dfs(g, 0);
	for(p=head[g]; p; p=p->next) s[ns++]=(Pair){size[p->to], p->to};
	std::sort(s, s+ns);
	mindif=(n-1)/2;
	for(i=0; i<ns; ++i) if(cmin(mindif, abs((sum+=s[i].key)-(n-1)/2))) par=i+1;
	step=1;
	for(i=0; i<par; ++i) answer(s[i].val, g, 0);
	step=cur+1;
	cur=0;
	for(i=par; i<ns; ++i) answer(s[i].val, g, 0);
	return 0;
}