#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<set>
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
int n, z, ans, a[N];
inline bool check(int mid){
	for(int i=1; i<=mid; ++i) if(a[n-mid+i]-a[i]<z) return 0;
	return 1;
}
int main() {
	read(n), read(z);
	for(int i=1; i<=n; ++i) read(a[i]);
	sort(a+1, a+n+1);
	int l=0, r=n/2;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)) ans=mid, l=mid+1; else r=mid-1;
	}
	return printf("%d", ans), 0;
}