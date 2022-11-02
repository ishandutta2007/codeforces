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

int a[101], x[101], y[101], lx, ly, cnt, dx, dy;
void ask(int i) {
	printf("+ %d\n", i);
	fflush(stdout);
	dx=lx;
	dy=ly;
	scanf("%d%d", &lx, &ly);
	++cnt;
	x[cnt]=dx=lx-dx;
	y[cnt]=dy=ly-dy;
}
int inv_choose(int x) {
	int n=1;
	while(n*(n-1)/2<x) ++n;
	assert(x==n*(n-1)/2);
	return n;
}
int main() {
	int n;
	n=rd(), lx=rd(), ly=rd();
	ask(1), ask(2), ask(3), ask(1);
	a[1]=inv_choose(dx)-1;
	a[2]=inv_choose(x[2]);
	a[3]=inv_choose(x[3]);
	int sum=dy-y[1]-1;
	if(a[3]>=2) a[2]=sum-a[3];
	if(a[2]>=2) a[3]=sum-a[2];
	if(sum==0) a[2]=a[3]=0;
	if(sum==1) a[y[2]?2:3]=0;
	for(int i=4; i<n; ++i) {
		ask(i);
		a[i]=(a[i-3]+1)*(a[i-2]+1)==y[i==4?3:i]?0:inv_choose(dx);
	}
	a[n]=(n==4?y[3]:dy)/(a[n-2]+1)-a[n-3]-1;
	printf("!");
	for(int i=1; i<=n; ++i) printf(" %d", a[i]);
	printf("\n");
	fflush(stdout);
	return 0;
}