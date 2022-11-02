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
int n;
std::vector<int> e[N];
std::vector<std::pair<int, int>> ans;
void dfs(int u, int p, int t) {
	int deg=e[u].size();
	ans.emplace_back(u, t);
	if(t<deg) {
		for(int v: e[u]) {
			if(v!=p) {
				dfs(v, u, ++t);
				ans.emplace_back(u, t);
				if(t==deg) ans.emplace_back(u, t=0);
			}
		}
	} else {
		ans.emplace_back(u, t-=deg);
		for(int v: e[u]) {
			if(v!=p) {
				dfs(v, u, ++t);
				ans.emplace_back(u, t);
			}
		}
	}
}
int main() {
	n=rd();
	int mx=0;
	for(int i=1; i<n; ++i) {
		int u=rd(), v=rd();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1; i<=n; ++i) cmax(mx, e[i].size());
	dfs(1, 0, 0);
	ans.pop_back();
	printf("%d\n", (int)ans.size());
	for(auto p: ans) printf("%d %d\n", p.first, p.second);
	return 0;
}