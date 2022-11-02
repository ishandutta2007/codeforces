#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
template<class Type1, class Type2> inline bool cmin(Type1 &a, const Type2 &b) {return b<a?(a=b, true):false;}
template<class Type1, class Type2> inline bool cmax(Type1 &a, const Type2 &b) {return a<b?(a=b, true):false;}
int read() {
	int a=0;
	unsigned char c;
	while((c=getchar()-'0')>9);
	while(a=a*10+c, (c=getchar()-'0')<=9);
	return a;
}
const int N=1e5+5, S=1<<18;
int n, k, ans, l[S], r[S];
long long p[N], q[N], min[S], max[S], val[S], tag[S], bit[S];
std::vector<int> child[N], where;
long long bit_par_sum(int x) {
	long long res=0;
	for(; x; x&=x-1) res+=bit[x];
	return res;
}
void bit_inc(int x, long long v) {
	for(; x<=n; x+=x&-x) bit[x]+=v;
}
void do_inc(int i, long long v) {
	tag[i]+=v;
	max[i]+=v;
	val[i]+=v;
}
void pushdown(int i) {
	if(tag[i]) {
		do_inc(i*2, tag[i]);
		do_inc(i*2+1, tag[i]);
		tag[i]=0;
	}
}
long long eval(int i, long long pmax) {
	if(l[i]==r[i]) return pmax+min[i];
	pushdown(i);
	return max[i*2]<=pmax?std::min(pmax+min[i*2], eval(i*2+1, pmax)):std::min(eval(i*2, pmax), val[i]);
}
void pushup(int i) {
	max[i]=std::max(max[i*2], max[i*2+1]);
	min[i]=std::min(min[i*2], min[i*2+1]);
	val[i]=eval(i*2+1, max[i*2]);
}
void build(int i, int ll, int rr) {
	l[i]=ll, r[i]=rr;
	if(ll==rr) {
		min[i]=-q[ll];
		max[i]=q[ll];
	} else {
		int mid=(ll+rr)/2;
		build(i*2, ll, mid);
		build(i*2+1, mid+1, rr);
		pushup(i);
	}
}
void increase_suffix(int i, int ql, long long qv) {
	if(ql>r[i]) return;
	if(ql<l[i]) return do_inc(i, qv);
	if(l[i]==r[i]) {
		tag[i]-=qv;
		return do_inc(i, qv);
	}
	pushdown(i);
	increase_suffix(i*2, ql, qv);
	increase_suffix(i*2+1, ql, qv);
	pushup(i);
}
int find_ok(int l) {
	int r=n;
	while(l<r) {
		int mid=(l+r+1)/2;
		if(bit_par_sum(mid)<=k) l=mid; else r=mid-1;
	}
	return l;
}
void extract(int i, int ql, int qr) {
	if(ql>r[i]||qr<l[i]) return;
	if(ql<=l[i]&&qr>=r[i]) return where.push_back(i);
	pushdown(i);
	extract(i*2, ql, qr);
	extract(i*2+1, ql, qr);
}
int find_last(int i, long long pmax) {
	while(l[i]!=r[i]) {
		pushdown(i);
		long long qmax=std::max(pmax, max[i*2]);
		if(eval(i*2+1, qmax)<=k) {
			i=i*2+1;
			pmax=qmax;
		} else i*=2;
	}
	return l[i];
}
void dfs(int x) {
	int last=x;
	long long lmax[100];
	where.clear();
	extract(1, x+1, find_ok(x+1)+1);
	lmax[0]=-1e18;
	for(int i=1; i<where.size(); ++i) lmax[i]=std::max(lmax[i-1], max[where[i-1]]);
	for(int i=where.size(); i--; )
		if(eval(where[i], lmax[i])<=k) {
			cmax(ans, find_last(where[i], lmax[i])-x);
			break;
		}
	for(int y: child[x]) {
		increase_suffix(1, x, p[y]-p[last]);
		bit_inc(x, p[y]-p[last]);
		dfs(last=y);
	}
	if(!child[x].empty()) {
		increase_suffix(1, x, p[x]-p[last]);
		bit_inc(x, p[x]-p[last]);
	}
}
int main() {
	static int d[N], a[N];
	std::vector<int> stack;
	n=read(), k=read();
	for(int i=1; i<n; ++i) d[i]=read();
	for(int i=1; i<=n; ++i) a[i]=read();
	for(int i=1; i<n; ++i) p[i]=p[i-1]+a[i]-d[i];
	for(int i=1; i<=n; ++i) q[i]=q[i-1]+a[i]-d[i-1];
	p[n]=-1e18;
	stack.push_back(n);
	for(int i=n; i--; ) {
		while(p[i]<=p[stack.back()]) stack.pop_back();
		child[stack.back()].push_back(i);
		stack.push_back(i);
	}
	build(1, 1, n);
	for(int i: child[n]) dfs(i);
	printf("%d\n", ans);
	return 0;
}