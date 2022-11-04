#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>
#include<vector>

using namespace std;
#define ll long long

inline char read() {
	static const int IN_LEN = 1000000;
	static char buf[IN_LEN], *s, *t;
	return (s==t?t=(s=buf)+fread(buf,1,IN_LEN,stdin),(s==t?-1:*s++):*s++);
}
template<class T>
inline void read(T &x) {
	static bool iosig;
	static char c;
	for (iosig=false, c=read(); !isdigit(c); c=read()) {
		if (c == '-') iosig=true;
		if (c == -1) return;
	}
	for (x=0; isdigit(c); c=read()) x=((x+(x<<2))<<1)+(c^'0');
	if (iosig) x=-x;
}
const int OUT_LEN = 10000000;
char obuf[OUT_LEN], *ooh=obuf;
inline void print(char c) {
	if (ooh==obuf+OUT_LEN) fwrite(obuf, 1, OUT_LEN, stdout), ooh=obuf;
	*ooh++=c;
}
template<class T>
inline void print(T x) {
	static int buf[30], cnt;
	if (x==0) print('0');
	else {
		if (x<0) print('-'), x=-x;
		for (cnt=0; x; x/=10) buf[++cnt]=x%10+48;
		while(cnt) print((char)buf[cnt--]);
	}
}
inline void flush() { fwrite(obuf, 1, ooh - obuf, stdout); }

const int N = 200005;
ll ans;
int n, *f, cnt0[N], cnt1[N], F[2][N];
inline int find(int x){ return f[x]==x?x:f[x]=find(f[x]);}
int main() {
	read(n);
	for(int i=1; i<=n; ++i) F[0][i]=F[1][i]=i;
	for(int i=1; i<n; ++i){
		int x, y, z;
		read(x), read(y), read(z);
		f=F[z];
		if(find(x)!=find(y)) f[f[x]]=f[y];
	}
	f=F[0];
	for(int i=1; i<=n; ++i) ++cnt0[find(i)];
	for(int i=1; i<=n; ++i) if(f[i]==i) ans+=(ll)cnt0[i]*(cnt0[i]-1);
	f=F[1];
	for(int i=1; i<=n; ++i) ++cnt1[find(i)];
	for(int i=1; i<=n; ++i) if(f[i]==i) ans+=(ll)cnt1[i]*(cnt1[i]-1);
	for(int i=1; i<=n; ++i) ans+=(cnt0[F[0][i]]-1ll)*(cnt1[F[1][i]]-1);
	return printf("%lld", ans), 0;
}