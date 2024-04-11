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

const int N=2e5+5;
int n, dn, pa[N], dep[N], dfn[N], dfr[N], en, el[N], st[19][2*N], *eu=st[0], off, zkw[1<<19];
s64 val[N], tick[1<<18];
std::vector<int> e[N], ve[N];
void dfs(int x, int p, int d) {
	pa[x]=p, dep[x]=d;
	dfn[x]=++dn;
	eu[el[x]=en++]=x;
	for(int y: e[x]) if(y!=p) dfs(y, x, d+1), eu[en++]=x;
	dfr[x]=dn;
}
int lca(int x, int y) {
	x=el[x], y=el[y];
	if(x>y) std::swap(x, y);
	int lv=31-__builtin_clz((++y)-x);
	x=st[lv][x], y=st[lv][y-(1<<lv)];
	return dep[x]<dep[y]?x:y;
}
int dis(int x, int y) {return dep[x]+dep[y]-2*dep[lca(x, y)];}
void upd(int x) {
	for(x+=off; x/=2; ) zkw[x]=zkw[2*x+(tick[zkw[2*x]]>tick[zkw[2*x+1]])];
}
void mdf(int x, s64 y) {if(cmin(val[x], y)) tick[x]=val[x], upd(x);}
int main() {
	n=rd();
	for(int i=1; i<n; ++i) {
		int u=rd(), v=rd();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, 0, 0);
	for(int i=1; (1<<i)<=en; ++i)
		for(int j=0; (1<<i)+j<=en; ++j) {
			int u=st[i-1][j], v=st[i-1][j+(1<<(i-1))];
			st[i][j]=dep[u]<dep[v]?u:v;
		}
	for(off=1; off<=n; off*=2);
	memset(tick, 63, off*sizeof(s64));
	memset(val+1, 63, n*sizeof(s64));
	for(int i=0; i<off; ++i) zkw[off+i]=i;
	for(int i=off; --i; ) zkw[i]=zkw[2*i];
	int q=rd();
	while(q--) {
		int k=rd(), m=rd();
		std::vector<std::pair<int, int>> virus(k);
		std::vector<int> important(m), vir;
		for(auto &p: virus) {
			vir.push_back(p.first=rd());
			p.second=rd();
		}
		for(auto &i: important) vir.push_back(i=rd());
		std::sort(vir.begin(), vir.end(), [](int x, int y) {return dfn[x]<dfn[y];});
		int size=vir.size();
		for(int i=1; i<size; ++i) vir.push_back(lca(vir[i-1], vir[i]));
		std::sort(vir.begin(), vir.end(), [](int x, int y) {return dfn[x]<dfn[y];});
		vir.resize(size=std::unique(vir.begin(), vir.end())-vir.begin());
		std::vector<int> stack;
		for(int i: vir) {
			while(!stack.empty()&&dfr[stack.back()]<dfn[i]) stack.pop_back();
			if(!stack.empty()) {
				int u=stack.back();
				ve[i].push_back(u);
				ve[u].push_back(i);
			}
			stack.push_back(i);
		}
		for(int i=0; i<k; ++i) mdf(virus[i].first, i);
		for(int i=1; i<=size; ++i) {
			int u=zkw[1], vid=val[u]%k;
			tick[u]=tick[0];
			upd(u);
			for(int v: ve[u]) mdf(v, ((dis(virus[vid].first, v)-1)/virus[vid].second+1)*k+vid);
		}
		for(int i=0; i<m; ++i) printf("%lld%c", val[important[i]]%k+1, " \n"[i==m-1]);
		for(int i: vir) tick[i]=val[i]=tick[0], ve[i].clear();
	}
	return 0;
}