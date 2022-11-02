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

const int N=1e5+1;
int n, deg[N], x;
std::vector<int> e[N];
void dfs(int u, int f, int d) {
	if(e[u].size()==1) x|=d;
	for(int v: e[u]) if(v!=f) dfs(v, u, d+1);
}
int main() {
	n=rd();
	for(int i=1; i<n; ++i) {
		int a=rd(), b=rd();
		e[a].push_back(b);
		e[b].push_back(a);
	}
	int r;
	for(r=1; e[r].size()!=1; ++r);
	dfs(r, 0, 0);
	int max=n-1;
	for(int i=1; i<=n; ++i) {
		if(e[i].size()==1) ++deg[e[i][0]];
	}
	for(int i=1; i<=n; ++i) {
		if(e[i].size()==1 && deg[e[i][0]]>1) {
			--max;
			--deg[e[i][0]];
		}
	}
	printf("%d %d\n", x&1?3:1, max);
	return 0;
}