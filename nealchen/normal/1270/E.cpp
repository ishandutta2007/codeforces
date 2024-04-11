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

struct Edge {
	int u, v;
	s64 d;
	bool operator<(const Edge &o) const {return d<o.d;}
};
const int N=1000;
int n, m, x[N], y[N];
Edge e[N*N];
std::vector<int> ans;
int main() {
	n=rd();
	for(int i=0; i<n; ++i) x[i]=rd(), y[i]=rd();
	while(true) {
		int cnt=0;
		for(int i=0; i<n; ++i) if((x[i]+y[i])%2==0) ++cnt;
		if(cnt>0&&cnt<n) {
			printf("%d\n", cnt);
			for(int i=0; i<n; ++i) if((x[i]+y[i])%2==0) printf("%d ", i+1);
			puts("");
			return 0;
		}
		if(cnt==0) for(int i=0; i<n; ++i) --x[i];
		for(int i=0; i<n; ++i) {
			int u=(x[i]+y[i])/2, v=(x[i]-y[i])/2;
			x[i]=u, y[i]=v;
		}
	}
	return 0;
}