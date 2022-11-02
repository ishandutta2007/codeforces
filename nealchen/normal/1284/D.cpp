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
typedef unsigned u32;
typedef long long s64;
typedef unsigned long long u64;
//const u32 P=;
//u32 &inc(u32 &a, u32 b) {return (a+=b)<P?a:(a-=P);}
//u32 &dec(u32 &a, u32 b) {return (a-=b)&0x80000000?(a+=P):a;}
//u32 sum(u32 a, u32 b) {return inc(a, b);}
//u32 dif(u32 a, u32 b) {return dec(a, b);}

struct Lect {
	int sa, ea, sb, eb;
	u64 key;
	bool operator<(const Lect &o) const {return ea<o.ea;}
};
const int N=2e5+5;
int n, mx, my, v[N];
u64 bit[N], ans1, ans2;
Lect le[N];
void solve() {
	std::sort(le, le+n);
	memset(bit+1, 0, mx*sizeof(u64));
	for(int i=0; i<n; ++i) {
		for(int j=le[i].sa+1; j<=mx; j+=j&-j) ans1+=le[i].key*bit[j];
		for(int j=le[i].ea; j; j&=j-1) bit[j]+=le[i].key;
	}
}
int main() {
	srand(time(NULL));
	typedef std::uniform_int_distribution<u64> ran;
	std::mt19937 gen(rand());
	n=rd();
	for(int i=0; i<n; ++i) le[i]={rd(), rd()+1, rd(), rd()+1, ran(0, -1llu)(gen)};
	for(int i=0; i<n; ++i) v[mx++]=le[i].sa, v[mx++]=le[i].ea;
	std::sort(v, v+mx);
	mx=std::unique(v, v+mx)-v;
	for(int i=0; i<n; ++i) {
		le[i].sa=std::lower_bound(v, v+mx, le[i].sa)-v;
		le[i].ea=std::lower_bound(v, v+mx, le[i].ea)-v;
	}
	for(int i=0; i<n; ++i) v[my++]=le[i].sb, v[my++]=le[i].eb;
	std::sort(v, v+my);
	my=std::unique(v, v+my)-v;
	for(int i=0; i<n; ++i) {
		le[i].sb=std::lower_bound(v, v+my, le[i].sb)-v;
		le[i].eb=std::lower_bound(v, v+my, le[i].eb)-v;
	}
	solve();
	std::swap(mx, my);
	for(int i=0; i<n; ++i) {
		std::swap(le[i].sa, le[i].sb);
		std::swap(le[i].ea, le[i].eb);
	}
	std::swap(ans1, ans2);
	solve();
	puts(ans1==ans2?"YES":"NO");
	return 0;
}