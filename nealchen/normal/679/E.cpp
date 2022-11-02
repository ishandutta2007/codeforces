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
const int N=1e5+1, M=1<<18;
int n, q, lb[M], rb[M], ql, qr, ind[M];
s64 qv, bad[10], t[N], min[M], add[M];
bool set[M];
inline void init(int x) {
	ind[x]=1;
	min[x]=*std::lower_bound(bad, bad+10, t[lb[x]])-t[lb[x]];
	add[x]=set[x]=0;
}
inline void pushup(int x) {
	ind[x]=ind[2*x]+ind[2*x+1];
	min[x]=std::min(min[2*x], min[2*x+1]);
}
inline void do_add(int x, s64 v) {
	min[x]-=v;
	add[x]+=v;
}
inline void do_set(int x) {
	add[x]=0;
	set[x]=true;
	ind[x]=0;
	min[x]=bad[9];
}
inline void apply(int x) {
	t[lb[x]]+=add[x];
	add[x]=0;
}
void pushdown(int x) {
	if(set[x]) {
		do_set(2*x);
		do_set(2*x+1);
		set[x]=false;
	}
	do_add(2*x, add[x]);
	do_add(2*x+1, add[x]);
	add[x]=0;
}
void build(int x, int l, int r) {
	lb[x]=l, rb[x]=r;
	if(l==r) return init(x);
	int mid=(l+r)/2;
	build(2*x, l, mid);
	build(2*x+1, mid+1, r);
	pushup(x);
}
void find_follow(int x) {
	if(rb[x]<ql||ind[x]==0) return;
	if(lb[x]==rb[x]) {
		qr=lb[x];
		return apply(x);
	}
	pushdown(x);
	find_follow(x*2);
	if(qr==-1) find_follow(x*2+1);
}
void set_follow(int x) {
	if(ql>rb[x]||qr<lb[x]) return;
	if(ql<=lb[x]&&rb[x]<=qr) return do_set(x);
	pushdown(x);
	set_follow(2*x);
	set_follow(2*x+1);
	pushup(x);
}
void modify(int x) {
	if(lb[x]==rb[x]) {
		t[ql]=qv;
		init(x);
	} else {
		pushdown(x);
		modify(x*2+(ql>rb[x*2]));
		pushup(x);
	}
}
void split(int x) {
	ql=x, qr=-1;
	find_follow(1);
	if(ql!=qr) {
		qv=t[qr];
		modify(1);
	}
}
void update(int x) {
	if(min[x]>=0) return;
	if(lb[x]==rb[x]) {
		apply(x);
		init(x);
	} else {
		pushdown(x);
		update(2*x);
		update(2*x+1);
		pushup(x);
	}
}
void increase(int x) {
	if(ql>rb[x]||qr<lb[x]||ind[x]==0) return;
	if(ql<=lb[x]&&rb[x]<=qr) {
		do_add(x, qv);
		update(x);
	} else {
		pushdown(x);
		increase(2*x);
		increase(2*x+1);
		pushup(x);
	}
}
int main() {
	bad[0]=1;
	for(int i=1; i<10; ++i) bad[i]=bad[i-1]*42;
	n=rd(), q=rd();
	for(int i=1; i<=n; ++i) t[i]=rd();
	build(1, 1, n);
	while(q--) {
		int o=rd();
		if(o==1) {
			ql=rd(), qr=-1;
			find_follow(1);
			printf("%lld\n", t[qr]);
		} else {
			int a=rd(), b=rd(), x=rd();
			if(a>1) split(a-1);
			split(b);
			if(o==2) {
				ql=a, qr=b-1;
				set_follow(1);
				ql=b, qv=x;
				modify(1);
			} else {
				ql=a, qr=b, qv=x;
				do {increase(1);} while(min[1]==0);
			}
		}
	}
	return 0;
}