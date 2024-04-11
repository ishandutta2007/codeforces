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

const int N=1e6+1;
int n, a[N], deg[N], q[N];
int main() {
	for(int t=rd(); t--; ) {
		n=rd();
		memset(deg+1, 0, n*sizeof(int));
		int *head=q, *tail=q;
		for(int i=1; i<=n; ++i) ++deg[a[i]=i-rd()];
		for(int i=1; i<=n; ++i) if(deg[i]==0) *tail++=i;
		while(head!=tail) {
			int u=*head++;
			if(--deg[a[u]]==0) *tail++=a[u];
		}
		int s=0;
		for(int i=1; i<=n; ++i) if(deg[i]) ++s;
		printf("%d\n", s);
		for(int i=1; i<=n; ++i) if(deg[i]) printf("%d ", i);
		puts("");
	}
	return 0;
}