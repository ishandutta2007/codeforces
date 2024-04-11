#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
typedef unsigned u32;
typedef long long s64;
typedef unsigned long long u64;
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
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

const int N=1005, T=N*50;
int n, d, tot=1, tr[T][10], pa[T], queue[T];
u32 f[2][T][2];
bool vis[T];
char s[N], x[55], y[55];
u32 solve(const char *x) {
	u32 ans=0;
	auto F=f[0], G=f[1];
	memset(F, 0, 8*tot);
	F[0][1]=1;
	for(int i=1; i<=d; ++i) {
		int c=x[i]-'0';
		std::swap(F, G);
		memset(F, 0, 8*tot);
		for(int j=0; j<tot; ++j) {
			for(int k=0; k<10; ++k) inc(F[tr[j][k]][0], G[j][0]);
			for(int k=0; k<c; ++k) inc(F[tr[j][k]][0], G[j][1]);
			inc(F[tr[j][c]][1], G[j][1]);
		}
	}
	for(int i=0; i<tot; ++i) if(vis[i]) ans=(ans+F[i][0]+F[i][1])%P;
	return ans;
}
int main() {
	int *qhead=queue, *qtail=queue;
	assert(scanf("%s%s%s", s, x+1, y+1)==3);
	n=strlen(s), d=strlen(x+1);
	for(int i=0; i+d/2<=n; ++i) {
		int at=0;
		for(int j=0; j<d/2; ++j) {
			int &to=tr[at][s[i+j]-'0'];
			if(to==0) to=tot++;
			at=to;
		}
		vis[at]=true;
	}
	for(int i=0; i<10; ++i) if(tr[0][i]) *qtail++=tr[0][i];
	while(qhead!=qtail) {
		int u=*qhead++;
		for(int j=0; j<10; ++j) {
			int &v=tr[u][j];
			(v?pa[*qtail++=v]:v)=tr[pa[u]][j];
		}
	}
	for(int i=0; i<tot; ++i) if(vis[i]) std::fill(tr[i], tr[i]+10, i);
	for(int i=d; i>=1; --i)
		if(x[i]=='0') x[i]='9';
		else {
			--x[i];
			break;
		}
	printf("%u\n", dif(solve(y), solve(x)));
	return 0;
}