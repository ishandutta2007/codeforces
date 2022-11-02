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

const int N=2e5+5;
int n, q, cnt[N], next[N];
u32 P, pw[N], hash[N];
char t[N];
bool is_prime(u32 n) {
	if(n==1) return false;
	for(u32 i=2; (u64)i*i<=n; ++i) if(n%i==0) return false;
	return true;
}
u32 gethash(int l, int len) {
	int r=l+len-1;
	if(cnt[l-1]==cnt[r]) return 0;
	int p=next[l];
	return (hash[r]+(P-hash[p]+0llu+((p-l)&1))*pw[cnt[r]-cnt[p]])%P;
}
int main() {
	std::mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count());
	do {
		P=std::uniform_int_distribution<>(8e8, 1.2e9)(gen);
	} while(!is_prime(P));
	scanf("%d%s%d", &n, t+1, &q);
	pw[0]=1;
	for(int i=1; i<=n; ++i) pw[i]=pw[i-1]*2%P;
	for(int i=1; i<=n; ++i) cnt[i]=cnt[i-1]+(t[i]=='0');
	for(int i=n; i>=1; --i) next[i]=t[i]=='0'?i:next[i+1];
	for(int i=1, j=0; i<=n; ++i) {
		if(t[i]=='1') {
			hash[i]=hash[i-1];
			j^=1;
		} else {
			hash[i]=(hash[i-1]*2+j)%P;
			j=0;
		}
	}
	while(q--) {
		int l1=rd(), l2=rd(), len=rd();
		if(cnt[l1+len-1]-cnt[l1-1]!=cnt[l2+len-1]-cnt[l2-1]) {
			puts("No");
			continue;
		}
		puts(gethash(l1, len)==gethash(l2, len)?"Yes":"No");
	}
	return 0;
}