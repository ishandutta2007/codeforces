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

const int N=2e5+5;
int n, a[N], b[N], pa[N], dep[N], dis[N];
std::vector<int> edge[N];
void gg() {
	puts("-1");
	exit(0);
}
void dfs(int u, int f=0) {
	pa[u]=f;
	dep[u]=dep[f]+1;
	for(int v: edge[u]) if(v!=f) dfs(v, u);
}
void dfs2(int u, int f=0, int d=0) {
	dis[u]=d;
	for(int v: edge[u]) if(v!=f) dfs2(v, u, d+1);
}
int main() {
	int s, t;
	n=rd();
	for(int i=1; i<=n; ++i) if((a[i]=rd())==0) s=i;
	for(int i=1; i<=n; ++i) if((b[i]=rd())==0) t=i;
	for(int i=1; i<n; ++i) {
		int u=rd(), v=rd();
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dep[0]=-1;
	dfs(t);
	dfs2(s);
	for(int i=s; i!=t; i=pa[i]) std::swap(a[i], a[pa[i]]);

	int mindep=n, p=0;
	for(int i=1; i<=n; ++i) if(a[i]!=b[i]&&cmin(mindep, dep[i])) p=i;
	if(p==0) {
		printf("0 %d\n", dep[s]);
		return 0;
	}
	p=pa[p];
	assert(p!=0);

	int u=0, v=0;
	for(int i=1; i<=n; ++i) if(a[i]!=b[i]||i==p) {
		int deg=0;
		for(int j: edge[i]) if(a[j]!=b[j]||j==p) ++deg;
		if(deg==1) {
			if(v) gg();
			if(u) v=u;
			u=i;
		} else if(deg!=2) gg();
	}

	std::vector<int> aa, bb, index(n+1);
	int len=dep[u]+dep[v]-2*dep[p];
	if(u>v) std::swap(u, v);
	for(int i=u; i!=p; i=pa[i]) aa.push_back(a[i]), bb.push_back(b[i]);
	for(int i=v; i!=p; i=pa[i]) aa.push_back(a[i]), bb.push_back(b[i]);
	std::reverse(aa.begin()+dep[u]-dep[p], aa.end());
	std::reverse(bb.begin()+dep[u]-dep[p], bb.end());
	for(int i=0; i<len; ++i) index[aa[i]]=i;
	for(int i=1; i<len; ++i) if(index[bb[i]]!=(index[bb[0]]+i)%len) gg();

	printf("%d %d %lld\n", u, v, std::min((len-index[bb[0]]-1ll)*(len+1)+dis[u]+dep[v], (index[bb[0]]-1ll)*(len+1)+dis[v]+dep[u])+1);
	return 0;
}