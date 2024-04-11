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

const int N=2005;
int n, p[N], c[N], res[N], size[N];
std::vector<int> e[N], list;
void gg() {
	puts("NO");
	exit(0);
}
void dfs(int u) {
	size[u]=1;
	if(c[u]>=list.size()) gg();
	res[u]=list[c[u]];
	list.erase(list.begin()+c[u]);
	for(int v: e[u]) {
		dfs(v);
		size[u]+=size[v];
	}
	if(size[u]<=c[u]) gg();
}
int main() {
	int root;
	n=rd();
	for(int i=1; i<=n; ++i) {
		p[i]=rd(), c[i]=rd();
		if(p[i]==0) root=i; else e[p[i]].push_back(i);
	}
	for(int i=1; i<=n; ++i) list.push_back(i);
	dfs(root);
	puts("YES");
	for(int i=1; i<=n; ++i) printf("%d%c", res[i], " \n"[i==n]);
	return 0;
}