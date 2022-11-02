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

int res[505];
int main() {
	int n=rd(), k=rd();
	for(int i=1; i<=k+1; ++i) {
		printf("?");
		for(int j=1; j<=k+1; ++j) if(j!=i) printf(" %d", j);
		puts("");
		fflush(stdout);
		rd(), res[i]=rd();
	}
	std::sort(res+1, res+k+2, std::greater<int>());
	int ans;
	for(ans=1; ans<k&&res[ans+1]==res[1]; ++ans);
	printf("! %d\n", ans);
	fflush(stdout);
	return 0;
}