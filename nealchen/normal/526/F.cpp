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

const int N=3e5+1, C=2*N;
u64 fs[64];
template<class CompF> struct RMQ {
	int *a, st[13][N/64];
	u64 save[N];
	CompF cmp;
	void load(int n, int *a) {
		static int stack[N];
		int *top=stack, m=0;
		u64 cur=0;
		this->a=a;
		for(int i=0; i<n; ++i) {
			cur=cur*2+1;
			while(top!=stack&&!cmp(a[top[-1]], a[i])) {
				int d=i-*--top;
				if(d<64) cur-=1llu<<d;
			}
			*top++=i;
			save[i]=cur;
		}
		for(int l=0, r; (r=l+64)<=n; l=r, ++m) st[0][m]=tiny(l, r-1);
		for(int i=1; (1<<i)<=m; ++i)
			for(int j=0; (1<<i)+j<=m; ++j) {
				int u=st[i-1][j], v=st[i-1][j+(1<<(i-1))];
				st[i][j]=cmp(a[u], a[v])?u:v;
			}
	}
	int tiny(int l, int r) {
		return r-63+__builtin_clzll(save[r]&fs[r-l]);
	}
	int query(int l, int r) {
		int lb=l/64, rb=r/64, res, upd;
		if(lb==rb) return tiny(l, r);
		res=tiny(l, lb*64+63);
		upd=tiny(rb*64, r);
		if(cmp(a[upd], a[res])) res=upd;
		if(++lb<rb) {
			int lv=31-__builtin_clz(rb-lb);
			upd=st[lv][lb];
			if(cmp(a[upd], a[res])) res=upd;
			upd=st[lv][rb-(1<<lv)];
			if(cmp(a[upd], a[res])) res=upd;
		}
		return res;
	}
};

int p[N], q[N], l[C], r[C], type[C], fail[C];
std::vector<int> child[C];
RMQ<std::less<int>> pmin;
RMQ<std::greater<int>> pmax, qmax;
bool is_consecutive(int l, int r) {return p[pmax.query(l, r)]-p[pmin.query(l, r)]==r-l;}
int main() {
	static int stack[N];
	int n, tot, *top=stack;
	fs[0]=1;
	for(int i=1; i<64; ++i) fs[i]=fs[i-1]*2+1;
	n=tot=rd();
	for(int i=1; i<=n; ++i) {
		int r=rd(), c=rd();
		p[r]=c, q[c]=r;
	}
	pmin.load(n+1, p);
	pmax.load(n+1, p);
	qmax.load(n+1, q);
	for(int i=1; i<=n; ++i) {
		int u=i;
		l[i]=r[i]=i;
		while(top!=stack) {
			int v=top[-1];
			if(v>n&&type[v]==0&&is_consecutive(l[child[v].back()], r[u])) {
				--top;
				child[v].push_back(u);
				r[v]=r[u];
				u=v;
				continue;
			}
			bool solved=false;
			for(; v; v=fail[v]) {
				int vl=p[pmin.query(l[v], r[u])], vr=p[pmax.query(l[v], r[u])];
				solved|=vr-vl==r[u]-l[v];
				if(solved||q[qmax.query(vl, vr)]>r[u]) break;
			}
			if(solved) {
				++tot;
				l[tot]=l[v], r[tot]=r[u];
				do {child[tot].push_back(*--top);} while(*top!=v);
				std::reverse(child[tot].begin(), child[tot].end());
				child[tot].push_back(u);
				type[tot]=child[tot].size()>=4;
				u=tot;
			} else {
				fail[u]=v;
				break;
			}
		}
		*top++=u;
	}
	long long ans=tot;
	for(int i=n+1; i<=tot; ++i) if(type[i]==0) ans+=child[i].size()*(child[i].size()-1llu)/2-1;
	printf("%lld\n", ans);
	return 0;
}