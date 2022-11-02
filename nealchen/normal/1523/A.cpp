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

char s[1005], t[1005];
void work() {
	int n=rd(), m=rd();
	scanf("%s", s);
	for(int i=0;i<m;++i){
		memcpy(t,s,n);
		for(int j=0;j<n;++j) if((j>0&&s[j-1]=='1')+(j+1<n&&s[j+1]=='1')==1) t[j]='1';
		if(memcmp(s,t,n)==0)break;
		memcpy(s,t,n);
	}
	puts(s);
}

int main() {
	int t=rd();
	while(t--)work();
	return 0;
}