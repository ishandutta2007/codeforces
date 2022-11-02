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

const int N=3e5+1;
int a[N], ans[N], bit[N];
std::vector<std::pair<int, int*>> qid[N];
int main() {
	int n, q;
	n=rd(), q=rd();
	for(int i=1; i<=n; ++i) a[i]=rd();
	for(int i=1; i<=q; ++i) {
		int x=rd(), y=rd();
		qid[n-y].emplace_back(x+1, ans+i);
	}
	int level=31^__builtin_clz(n);
	for(int i=1; i<=n; ++i) {
		if(a[i]<=i) {
			int targ=i-a[i], p=0;
			for(int j=level; j>=0; --j) {
				int q=p+(1<<j);
				if(q<=n && bit[q]<targ) targ-=bit[p=q];
			}
			for(p=std::max(p, n-i)+1; p<=n; p+=p&-p) ++bit[p];
		}
		for(auto j: qid[i]) {
			for(int k=n-j.first+1; k; k&=k-1) *j.second+=bit[k];
		}
	}
	for(int i=1; i<=q; ++i) printf("%d\n", ans[i]);
	return 0;
}