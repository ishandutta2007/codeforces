#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#define meow(args...) fprintf(stderr, args)
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
const int N=2e5, S=1<<19;
int n, p[N], l[S], r[S];
long long s[N], sum[S];
long long read() {
	long long a=0;
	unsigned char c;
	while((c=getchar()-'0')>9);
	while(a=a*10+c, (c=getchar()-'0')<=9);
	return a;
}
void build(int i, int ll, int rr) {
	l[i]=ll, r[i]=rr;
	if(ll==rr) sum[i]=ll; else {
		int mid=(ll+rr)/2;
		build(i<<1, ll, mid);
		build(i<<1|1, mid+1, rr);
		sum[i]=sum[i<<1]+sum[i<<1|1];
	}
}
void rm(int i, int q) {
	if(l[i]==r[i]) sum[i]=0; else {
		rm(i<<1|q>r[i<<1], q);
		sum[i]=sum[i<<1]+sum[i<<1|1];
	}
}
int qry(int i, long long wh) {
	if(l[i]==r[i]) return l[i];
	if(wh<sum[i<<1]) return qry(i<<1, wh); else return qry(i<<1|1, wh-sum[i<<1]);
}
int main() {
	assert(scanf("%d", &n)==1);
	for(int i=0; i<n; ++i) s[i]=read();
	build(1, 1, n);
	for(int i=n; i--; ) {
		p[i]=qry(1, s[i]);
		rm(1, p[i]);
	}
	for(int i=0; i<n; ++i) printf("%d ", p[i]);
	printf("\n");
	return 0;
}