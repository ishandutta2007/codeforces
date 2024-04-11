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

struct Segment {
	int l, r;
};
const int N=5e5+1;
int n, m, to[2*N], head[N], next[2*N], pa[N], dep[N], size[N], prefer[N], top[N], clk, real[N], dfn[N], mindep[N], k, f[N];
bool vis[N], res, rev[N];

namespace DSU {
	int pa[N], w[N];
	void find(int u) {
		int v=pa[u];
		if(u!=v) {
			find(v);
			pa[u]=pa[v];
			w[u]^=w[v];
		}
	}
	void merge(int u, int v, int c) {
		find(u);
		find(v);
		c^=w[u]^w[v];
		u=pa[u];
		v=pa[v];
		if(u==v&&c) {
			puts("-1");
			exit(0);
		}
		pa[u]=v;
		w[u]=c;
	}
};

void dfs1(int u) {
	dep[u]=dep[pa[u]]+1;
	size[u]=1;
	for(int i=head[u], *p=&head[u], mx=0; i; i=next[i]) {
		if(to[i]!=pa[u]) {
			pa[to[i]]=u;
			dfs1(to[i]);
			size[u]+=size[to[i]];
			if(cmax(mx, size[to[i]])) prefer[u]=to[i];
			p=next+i;
		} else
			*p=next[i];
	}
}
void dfs2(int u) {
	real[dfn[u]=++clk]=u;
	if(prefer[u]) {
		top[prefer[u]]=top[u];
		dfs2(prefer[u]);
	}
	for(int i=head[u]; i; i=next[i]) {
		if(to[i]!=prefer[u]) {
			top[to[i]]=to[i];
			dfs2(to[i]);
		}
	}
}
int lca(int u, int v) {
	while(top[u]!=top[v]) {
		if(dep[top[u]]>dep[top[v]])
			u=pa[top[u]];
		else
			v=pa[top[v]];
	}
	return dep[u]<dep[v]?u:v;
}
Segment operator&(const Segment &a, const Segment &b) {
	return (Segment){std::max(a.l, b.l), std::min(a.r, b.r)};
}
Segment operator|(const Segment &a, const Segment &b) {
	return (Segment){std::min(a.l, b.l), std::max(a.r, b.r)};
}
bool check(int k) {
	std::vector<int> e;
	for(int i=n; i>=1; --i) {
		int u=real[i];
		Segment s1{1, k}, s2{k, 1};
		e.clear();
		for(int j=head[u]; j; j=next[j]) {
			int v=to[j];
			if(!vis[v]) continue;
			if(DSU::pa[v]==DSU::pa[u]) {
				rev[v] = DSU::w[u]^DSU::w[v];
				if(rev[v])
					s1=s1&(Segment){1, k-f[v]};
				else
					s1=s1&(Segment){f[v]+1, k};
			} else
				e.emplace_back(v);
		}
		std::sort(e.begin(), e.end(), [](int x, int y) {return DSU::pa[x]<DSU::pa[y];});
		int d=e.size();
		for(int l=0, r=0; l<d; l=r) {
			Segment s3{1, k};
			for(int v=e[l], w; r<d && (w=e[r], DSU::pa[v]==DSU::pa[w]); ++r) {
				if(DSU::w[v]==DSU::w[w])
					s3=s3&(Segment){f[w]+1, k};
				else
					s3=s3&(Segment){1, k-f[w]};
			}
			if(s3.l>s3.r) return false;
			if(s3.l>k+1-s3.l) s3={k+1-s3.r, k+1-s3.l};
			s1=s1&((Segment){s3.l, k+1-s3.l}|(Segment){k+1-s3.r, s3.r});
			if(s3.r<k+1-s3.r) s2=s2|(Segment){s3.r+1, k-s3.r};
		}
		if(s1.l>s1.r ||	(s2.l<=s1.l&&s1.r<=s2.r)) return false;
		if(s2.l<=s1.l && s1.l<=s2.r) f[u]=s2.r+1; else f[u]=s1.l;
		for(int l=0, r=0; l<d; l=r) {
			Segment s3{1, k};
			int v=e[l];
			for(int w; r<d && (w=e[r], DSU::pa[v]==DSU::pa[w]); ++r) {
				if(DSU::w[v]==DSU::w[w])
					s3=s3&(Segment){f[w]+1, k};
				else
					s3=s3&(Segment){1, k-f[w]};
			}
			bool bb = f[u]<s3.l||f[u]>s3.r;
			if(bb) s3={k+1-s3.r, k+1-s3.l};
			for(int j=l; j<r; ++j) {
				int w=e[j];
				rev[w]=DSU::w[v]^DSU::w[w]^bb;
			}
		}
	}
	return true;
}
int main() {
	n=rd();
	m=rd();
	for(int i=1, j=2; i<n; ++i) {
		int u=rd(), v=rd();
		to[j]=v;
		next[j]=head[u];
		head[u]=j++;
		to[j]=u;
		next[j]=head[v];
		head[v]=j++;
	}
	dfs1(1);
	top[1]=1;
	dfs2(1);
	for(int i=1; i<=n; ++i) DSU::pa[i]=i;
	for(int i=1; i<=n; ++i) mindep[i]=dep[i];
	for(int i=1; i<=m; ++i) {
		int a=rd(), b=rd(), c=lca(a, b);
		cmin(mindep[a], dep[c]);
		cmin(mindep[b], dep[c]);
		if(a!=c&&b!=c) DSU::merge(a, b, 1);
	}
	for(int i=n; i>=1; --i) {
		int u=real[i];
		for(int j=head[u]; j; j=next[j]) {
			int v=to[j];
			cmin(mindep[u], mindep[v]);
			if(mindep[v]<dep[u]) DSU::merge(u, v, 0);
		}
		vis[u] = mindep[u]<dep[u];
	}
	for(int i=1; i<=n; ++i) DSU::find(i);
	int l=1, r=n;
	while(l<r) {
		int mid=(l+r)/2;
		if(check(mid)) r=mid; else l=mid+1;
	}
	check(l);
	for(int i=2; i<=n; ++i) {
		int u=real[i];
		rev[u]^=rev[pa[u]];
	}
	printf("%d\n", l);
	for(int i=1; i<=n; ++i)
		printf("%d%c", rev[i]?l-f[i]+1:f[i], " \n"[i==n]);
	return 0;
}