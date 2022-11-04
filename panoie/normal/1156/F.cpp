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

const int N = 5005, P = 998244353;
int n, ans, a[N], inv[N], f[N][N], g[N][N];
int main() {
	read(n);
	inv[1]=1;
	for(int i=2; i<=n; ++i) inv[i]=(ll)(P-P/i)*inv[P%i]%P;
	for(int i=1; i<=n; ++i) read(a[i]);
	sort(a+1, a+n+1);
	f[0][0]=g[0][0]=1;
	for(int i=1; i<=n; ++i){
		int L=i, R=i;
		while(L>1 && a[L-1]==a[i]) --L;
		while(R<n && a[R+1]==a[i]) ++R;
		g[i][0]=g[i-1][0];
		for(int j=1; j<=i; ++j){
			if(i==L) f[i][j]=(ll)g[L-1][j-1]*inv[n-j+1]%P*(R-i+1)%P;
			else ans=(ans+(ll)(g[i-1][j-1]-g[L-1][j-1]+P)*inv[n-j+1])%P;
			g[i][j]=(g[i-1][j]+f[i][j])%P;
		}
	}
	return printf("%d", ans), 0;
}