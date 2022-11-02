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

struct Ans {s64 a, b, c;};
bool f[64][2][4];
Ans cho[64][2][4];
void work() {
	u64 s=0, x=0;
	for(int n=rd(); n--; ) {
		int a=rd();
		s+=a, x^=a;
	}
	memset(f, 0, sizeof(f));
	int si=s&1, xi=x&1;
	for(int u=0; u<4; ++u)
		if((si+u)%2==0) {
			if(f[0][xi^(u&1)][(si+u)/2]&&(u>=1)>=cho[0][xi^(u&1)][(si+u)/2].a) continue;
			f[0][xi^(u&1)][(si+u)/2]=true;
			cho[0][xi^(u&1)][(si+u)/2]=(Ans){u>=1, u>=2, u>=3};
		}
	for(int i=1; i<59; ++i) {
		si=s>>i&1, xi=x>>i&1;
		for(int j=0; j<2; ++j)
			for(int k=0; k<4; ++k)
				for(int u=0; u<4; ++u)
					if(f[i-1][j][k]&&(si+u+k-j)%2==0) {
						bool &F=f[i][xi^(u&1)][(si+u+k)/2];
						Ans &A=cho[i][xi^(u&1)][(si+u+k)/2], B={(s64)(u>=1)<<i|cho[i-1][j][k].a, (s64)(u>=2)<<i|cho[i-1][j][k].b, (s64)(u>=3)<<i|cho[i-1][j][k].c};
						if(F&&B.a>A.a) continue;
						F=true, A=B;
					}
	}
	printf("3\n%lld %lld %lld\n", cho[58][0][0].a, cho[58][0][0].b, cho[58][0][0].c);
}
int main() {
	int t=rd();
	while(t--) work();
	return 0;
}