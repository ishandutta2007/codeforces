#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
typedef unsigned u32;
typedef long long s64;
typedef unsigned long long u64;
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
namespace Input {
	const int N=1<<20;
	char b[N], *s=b, *t=b;
	int getchar() {
		if(s==t) {
			s=b;
			t=b+fread(b, 1, N, stdin);
		}
		return s==t?EOF:*s++;
	}
}
template<class Type> Type read() {
	using Input::getchar;
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

const int N=5e5, M=1<<20;
int n, a[N], b[N], val, ql, qr, tag[M];
std::set<int> seq;
std::multiset<int> gap;
std::pair<int, int> p[N];
std::multiset<std::pair<int, int>> mod;
void build(int o, int l, int r) {
	tag[o]=1e9;
	if(r-l>1) {
		int mid=(l+r)/2;
		build(2*o, l, mid);
		build(2*o+1, mid, r);
	}
}
void cover(int o, int l, int r) {
	if(r<=ql||qr<=l) return;
	if(ql<=l&&r<=qr)
		cmin(tag[o], val);
	else {
		int mid=(l+r)/2;
		cover(2*o, l, mid);
		cover(2*o+1, mid, r);
	}
}
void query(int o, int l, int r, int v) {
	cmin(v, tag[o]);
	if(r-l==1)
		printf("%d ", v);
	else {
		int mid=(l+r)/2;
		query(2*o, l, mid, v);
		query(2*o+1, mid, r, v);
	}
}
void range(int l, int r) {
	if(b[l]&&b[r-1]) return;
	ql=l, qr=r;
	if(b[l]) ql=(l+r)/2;
	if(b[r-1]) qr=(l+r)/2;
	cover(1, 0, n);
}
void erase(int x) {
	auto it=seq.find(x), jt=it, kt=it;
	int p=*--jt, q=*++kt;
	mod.erase({p, x});
	mod.erase({x, q});
	gap.erase(gap.find((x-p-1)/2));
	gap.erase(gap.find((q-x-1)/2));
	mod.emplace(p, q);
	gap.insert((q-p-1)/2);
	seq.erase(x);
}
void insert(int x) {
	auto it=seq.insert(x).first, jt=it, kt=it;
	int p=*--jt, q=*++kt;
	mod.emplace(p, x);
	mod.emplace(x, q);
	gap.insert((x-p-1)/2);
	gap.insert((q-x-1)/2);
	mod.erase({p, q});
	gap.erase(gap.find((q-p-1)/2));
}
int main() {
	int ansc=0;
	n=rd();
	for(int i=0; i<n; ++i) {
		a[i]=rd();
		p[i]={a[i], i};
		b[i]=1;
	}
	if(n==1) {
		printf("0\n%d", a[0]);
		return 0;
	}
	std::sort(p, p+n);
	for(int i=0; i<=n; ++i) seq.insert(i);
	for(int i=1; i<=n; ++i) gap.insert(0);
	build(1, 0, n);
	for(int i=0; i<n; ++i) {
		int x=p[i].second;
		val=p[i].first;
		mod.clear();
		b[x]=0;
		if(x>0) (b[x-1]?erase:insert)(x);
		if(x+1<n) (b[x+1]?erase:insert)(x+1);
		for(auto pr: mod) range(pr.first, pr.second);
		if(i+1==n||val<p[i+1].first) cmax(ansc, *--gap.end());
	}
	printf("%d\n", ansc);
	query(1, 0, n, 1e9);
	return 0;
}