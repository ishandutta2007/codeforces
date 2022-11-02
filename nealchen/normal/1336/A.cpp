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
const int N=2e5+1;
int n, k, f[N], siz[N], dep[N], v[N], hub[N];
std::vector<int> e[N];
void dfs(int x) {
	siz[x]=1;
	dep[x]=dep[f[x]]+1;
	for(int y: e[x]) {
		if(y!=f[x]) {
			f[y]=x;
			dfs(y);
			siz[x]+=siz[y];
		}
	}
	v[x]=dep[x]-siz[x];
}
int main() {
	n=rd(), k=rd();
	for(int i=1; i<n; ++i) {
		int x=rd(), y=rd();
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1);
	for(int i=0; i<n; ++i) hub[i]=i+1;
	std::nth_element(hub, hub+k, hub+n, [](int x, int y) {return v[x]>v[y];});
	long long ans=0;
	for(int i=0; i<k; ++i) ans+=v[hub[i]];
	printf("%lld\n", ans);
	return 0;
}