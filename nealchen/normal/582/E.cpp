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
const u32 P=1e9+7;
inline u32 &inc(u32 &a, u32 b) {return (a+=b)<P?a:(a-=P);}
inline u32 &dec(u32 &a, u32 b) {return (a-=b)&0x80000000?(a+=P):a;}
inline u32 sum(u32 a, u32 b) {return (a+=b)<P?a:a-P;}
inline u32 dif(u32 a, u32 b) {return (a-=b)&0x80000000?a+P:a;}
u64 power(u64 a, int b) {
	u64 ans=1;
	for(; b; a=a*a%P, b/=2) if(b&1) ans=ans*a%P;
	return ans;
}

const int N=502, M=65536;
char s[N];

u32 ff[M], fg[M], fh[M];
u32 *solve(int l, int r) {
	u32 *f=new u32[M];
	memset(f, 0, sizeof(fg));
	if(r-l==1) {
		for(int i=0; i<4; ++i) {
			if(s[l]=='?'||s[l]=='A'+i) {
				int func=0;
				for(int j=0; j<16; ++j) func|=(j>>i&1)<<j;
				++f[func];
			}
			if(s[l]=='?'||s[l]=='a'+i) {
				int func=0;
				for(int j=0; j<16; ++j) func|=(~j>>i&1)<<j;
				++f[func];
			}
		}
	} else {
		int cnt=0, mid;
		for(mid=l; mid==l||cnt!=0; ++mid) cnt+=(s[mid]=='(')-(s[mid]==')');
		u32 *g=solve(l+1, mid-1), *h=solve(mid+2, r-1);
		if(s[mid]!='|') {
			memcpy(fg, g, sizeof(fg));
			for(int i=0; i<16; ++i)
				for(int j=1<<i, k=1<<i; j<M; j=(j+1)|k) inc(fg[j-k], fg[j]);
			memcpy(fh, h, sizeof(fh));
			for(int i=0; i<16; ++i)
				for(int j=1<<i, k=1<<i; j<M; j=(j+1)|k) inc(fh[j-k], fh[j]);
			for(int i=0; i<M; ++i) ff[i]=(u64)fg[i]*fh[i]%P;
			for(int i=0; i<16; ++i)
				for(int j=1<<i, k=1<<i; j<M; j=(j+1)|k) dec(ff[j-k], ff[j]);
			for(int i=0; i<M; ++i) inc(f[i], ff[i]);
		}
		if(s[mid]!='&') {
			memcpy(fg, g, sizeof(fg));
			for(int i=0; i<16; ++i)
				for(int j=1<<i, k=1<<i; j<M; j=(j+1)|k) inc(fg[j], fg[j-k]);
			memcpy(fh, h, sizeof(fh));
			for(int i=0; i<16; ++i)
				for(int j=1<<i, k=1<<i; j<M; j=(j+1)|k) inc(fh[j], fh[j-k]);
			for(int i=0; i<M; ++i) ff[i]=(u64)fg[i]*fh[i]%P;
			for(int i=0; i<16; ++i)
				for(int j=1<<i, k=1<<i; j<M; j=(j+1)|k) dec(ff[j], ff[j-k]);
			for(int i=0; i<M; ++i) inc(f[i], ff[i]);
		}
		delete[] g;
		delete[] h;
	}
	u32 sum=0;
	for(int i=0; i<M; ++i) inc(sum, f[i]);
	return f;
}
int main() {
	int v[16];
	assert(scanf("%s", s)==1);
	u32 *f=solve(0, strlen(s)), ans=0;
	memset(v, -1, sizeof(v));
	for(int n=rd(); n--; ) {
		int a=rd(), b=rd(), c=rd(), d=rd();
		v[a+2*b+4*c+8*d]=rd();
	}
	for(int i=0; i<M; ++i) {
		bool ok=true;
		for(int j=0; j<16; ++j) ok&=v[j]!=(~i>>j&1);
		if(ok) inc(ans, f[i]);
	}
	printf("%u\n", ans);
	return 0;
}