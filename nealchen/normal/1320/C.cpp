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

const int N=2e5+5, M=1<<19;
int n, m, p, a[N], ca[N], b[N], cb[N], lb[M], rb[M], tag[M], max[M];
std::pair<int, int> we[N], as[N];
std::vector<std::pair<int, int>> mon[N];
void build(int i, int l, int r) {
	lb[i]=l, rb[i]=r;
	if(r-l==1) {
		max[i]=-cb[l];
	} else {
		int mid=(l+r)/2;
		build(2*i, l, mid);
		build(2*i+1, mid, r);
		max[i]=std::max(max[2*i], max[2*i+1]);
	}
}
void increase(int i, int l, int v) {
	if(rb[i]<=l) return;
	if(lb[i]>=l) {
		tag[i]+=v;
		max[i]+=v;
	} else {
		increase(2*i, l, v);
		increase(2*i+1, l, v);
		max[i]=std::max(max[2*i], max[2*i+1])+tag[i];
	}
}
int main() {
	int ans=-2.1e9;
	n=rd(), m=rd(), p=rd();
	for(int i=0; i<n; ++i) we[i]={rd(), rd()};
	for(int i=0; i<m; ++i) as[i]={rd(), rd()};
	std::sort(we, we+n);
	std::sort(as, as+m);
	int top=0;
	for(int i=0; i<n; ++i) {
		while(top&&ca[top-1]>=we[i].second) --top;
		std::tie(a[top], ca[top])=we[i], ++top;
	}
	n=top;
	top=0;
	for(int i=0; i<m; ++i) {
		while(top&&cb[top-1]>=as[i].second) --top;
		std::tie(b[top], cb[top])=as[i], ++top;
	}
	m=top;
	for(int i=0; i<p; ++i) {
		int x=rd(), y=rd(), z=rd();
		x=std::upper_bound(a, a+n, x)-a;
		if(x==n) continue;
		y=std::upper_bound(b, b+m, y)-b;
		if(y==m) continue;
		mon[x].emplace_back(y, z);
	}
	build(1, 0, m);
	for(int i=0; i<n; ++i) {
		for(auto j: mon[i]) increase(1, j.first, j.second);
		cmax(ans, max[1]-ca[i]);
	}
	printf("%d\n", ans);
	return 0;
}