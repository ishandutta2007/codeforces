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
//const int P=;
//inline int &inc(int &a, int b) {return (a+=b)<P?a:(a-=P);}
//inline int &dec(int &a, int b) {return (a-=b)<0?(a+=P):a;}
//inline int sum(int a, int b) {return (a+=b)<P?a:a-P;}
//inline int dif(int a, int b) {return (a-=b)<0?a+P:a;}
//u64 power(u64 a, int b) {
//	u64 ans=1;
//	for(; b; a=a*a%P, b/=2) if(b&1) ans=ans*a%P;
//	return ans;
//}

int f[1<<15], size[1<<15];
u64 a[200000];
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int randint(int l, int r) {
	return std::uniform_int_distribution<>(l, r)(rng);
}
int main() {
	for(int i=1; i<(1<<15); ++i) size[i]=size[i&i-1]+1;
	int n=rd(), m=rd(), ans=0;
	u64 solution=0;
	rd();
	for(int i=0; i<n; ++i) {
		char s[61];
		scanf("%s", s);
		for(int j=0; j<m; ++j) a[i]|=(s[j]&1llu)<<j;
	}
	while(clock()<CLOCKS_PER_SEC*2.5) {
		u64 super=a[randint(0, n-1)];
		int p=0, id[60], real[15];
		for(int j=0; j<m; ++j) {
			if(super>>j&1) real[id[j]=p++]=j;
		}
		memset(f, 0, sizeof(int)<<p);
		for(int i=0; i<n; ++i) {
			int cur=0;
			for(int j=0; j<m; ++j) {
				if((super&a[i])>>j&1) cur|=1<<id[j];
			}
			++f[cur];
		}
		for(int i=0, k=1; i<p; ++i, k*=2) {
			for(int j=0; j<(1<<p); ++j) {
				if(j&k) f[j-k]+=f[j];
			}
		}
		for(int i=0; i<(1<<p); ++i) {
			if(f[i]*2>=n && size[i]>ans) {
				ans=size[i];
				solution=0;
				for(int j=0; j<p; ++j) {
					if(i>>j&1) solution|=1llu<<real[j];
				}
			}
		}
	}
	for(int i=0; i<m; ++i) printf("%lld", solution>>i&1);
	puts("");
	return 0;
}