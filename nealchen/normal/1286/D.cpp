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
const u32 P=998244353;
u32 &inc(u32 &a, u32 b) {return (a+=b)<P?a:(a-=P);}
u32 &dec(u32 &a, u32 b) {return (a-=b)&0x80000000?(a+=P):a;}
u32 sum(u32 a, u32 b) {return inc(a, b);}
u32 dif(u32 a, u32 b) {return dec(a, b);}
u64 power(u64 a, u32 b) {
	u64 res=1;
	for(; b; a=a*a%P, b/=2) if(b%2==1) res=res*a%P;
	return res;
}

struct Event {
	u32 num, den;
	int pos;
	bool face;
	bool operator<(const Event &o) const {return (u64)num*o.den<(u64)den*o.num;}
};
struct Data {
	u32 sum, lp, rp;
};

const int N=1e5+1;
const u64 percent=power(100, P-2);
const Data E={0, 1, 1};

int n, off, x[N], v[N], l[N], r[N], id[N];
u32 p[N];
Data zkw[1<<18];
std::vector<Event> e;
Data operator+(const Data &a, const Data &b) {
	Data res;
	res.sum=((u64)a.sum*b.rp+(u64)b.sum*a.lp)%P;
	res.lp=(u64)a.lp*b.lp%P;
	res.rp=(u64)a.rp*b.rp%P;
	return res;
}
//[l:r]
u32 query(int l, int r) {
	Data resl=zkw[l+=off], resr=E;
	for(r+=off; l^r^1; l/=2, r/=2) {
		if(~l&1) resl=resl+zkw[l^1];
		if( r&1) resr=zkw[r^1]+resr;
	}
	resl=resl+resr;
	return sum(resl.sum, resl.rp);
}
int main() {
	u32 last=0, prob=1, ans=0;
	n=rd();
	for(int i=0; i<n; ++i) x[i]=rd(), v[i]=rd(), p[i]=rd()*percent%P;

	for(off=1; off<=n; off*=2);
	for(int i=0; i<n; ++i) zkw[off+i]={dif(1, p[i]), dif(1, p[i]), p[i]};
	for(int i=n; i<off; ++i) zkw[off+i]=E;
	for(int i=off; --i; ) zkw[i]=zkw[i*2]+zkw[i*2+1];

	for(int i=1; i<n; ++i) {
		u32 gap=x[i]-x[i-1];
		e.push_back({gap, u32(v[i-1]+v[i]), i, true});
		if(v[i-1]<v[i]) e.push_back({gap, u32(v[i]-v[i-1]), i, false});
		if(v[i-1]>v[i]) e.push_back({gap, u32(v[i-1]-v[i]), i, false});
	}
	for(int i=0; i<n; ++i) l[i]=i, r[i]=i+1, id[i]=i;
	std::sort(e.begin(), e.end());
	for(auto ev: e) {
		u32 cur=ev.num*power(ev.den, P-2)%P;
		int p=ev.pos;
		ans=(ans+(u64)dif(cur, last)*prob)%P;
		last=cur;
		if(ev.face) {
			int i=id[p-1], j=id[p];
			prob=prob*power(query(l[i], r[i]), P-2)%P*power(query(l[j], r[j]), P-2)%P;
			if(r[i]-l[i]<r[j]-l[j]) std::swap(i, j);
			l[i]=std::min(l[i], l[j]);
			r[i]=std::max(r[i], r[j]);
			prob=(u64)prob*query(l[i], r[i])%P;
			for(int k=l[j]; k<r[j]; ++k) id[k]=i;
		} else if(v[p-1]<v[p]) {
			int i=id[p];
			prob=prob*power(query(l[i], r[i]), P-2)%P;
			p+=off;
			zkw[p].lp=zkw[p].sum=0;
			while(p/=2) zkw[p]=zkw[p*2]+zkw[p*2+1];
			prob=(u64)prob*query(l[i], r[i])%P;
		} else {
			int i=id[--p];
			prob=prob*power(query(l[i], r[i]), P-2)%P;
			p+=off;
			zkw[p].rp=0;
			while(p/=2) zkw[p]=zkw[p*2]+zkw[p*2+1];
			prob=(u64)prob*query(l[i], r[i])%P;
		}
		if(prob==0) break;
	}
	ans=(ans+(u64)(P-prob)*last)%P;
	printf("%u\n", ans);
	return 0;
}