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
int n, f[N][2], ans;
std::vector<int> e[N];
void dfs(int u, int p) {
	int sec[2]={};
	for(int v: e[u]) {
		if(v!=p) {
			dfs(v, u);
			int tmp=f[v][0];
			if(tmp>f[u][1]) {
				sec[1]=f[u][1];
				f[u][1]=tmp;
			} else cmax(sec[1], tmp);
			cmax(tmp, f[v][1]);
			if(tmp>f[u][0]) {
				sec[0]=f[u][0];
				f[u][0]=tmp;
			} else cmax(sec[0], tmp);
		}
	}
	cmax(ans, f[u][0]+sec[0]+((int)e[u].size()-2));
	cmax(ans, f[u][1]+sec[1]+1);
	f[u][0]+=(int)e[u].size()-2;
	++f[u][1];
}
int main() {
	n=rd();
	for(int i=1; i<n; ++i) {
		int a=rd(), b=rd();
		e[a].push_back(b);
		e[b].push_back(a);
	}
	dfs(1, 0);
	printf("%d\n", ans);
	return 0;
}