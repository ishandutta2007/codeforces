#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
using namespace std;
#define ll long long
#define rt register int
#define reep(i,x,y) for(rt i=(x);i<(y);++i)
#define per(i,x,y) for(rt i=(x);i>=(y);--i)
#define rep(i,x,y) for(rt i=(x);i<=(y);++i)
#define travel(i,x) for(rt i=h[x];i;i=pre[i])
namespace fast_IO {
	inline char read() {
//		return getchar();
		static const int IN_LEN = 1000000;
		static char buf[IN_LEN], *s, *t;
		if (s == t) {
			t = (s = buf) + fread(buf, 1, IN_LEN, stdin);
			if (s == t) return -1;
		}
		return *s++;
	}
	template<class T>
	inline void read(T &x) {
		static bool iosig;
		static char c;
		for (iosig = false, c = read(); !isdigit(c); c = read()) {
			if (c == '-') iosig = true;
			if (c == -1) return;
		}
		for (x = 0; isdigit(c); c = read())
			x = ((x + (x << 2)) << 1) + (c ^ '0');
		if (iosig) x = -x;
	}
	const int OUT_LEN = 10000000;
	char obuf[OUT_LEN], *ooh = obuf;
	inline void print(char c) {
		if (ooh == obuf + OUT_LEN) fwrite(obuf, 1, OUT_LEN, stdout), ooh = obuf;
		*ooh++ = c;
	}
	template<class T>
	inline void print(T x) {
		static int buf[30], cnt;
		if (x == 0) {
			print('0');
		}
		else {
			if (x < 0) print('-'), x = -x;
			for (cnt = 0; x; x /= 10) buf[++cnt] = x % 10 + 48;
			while (cnt) print((char)buf[cnt--]);
		}
	}
	inline void flush() {
		fwrite(obuf, 1, ooh - obuf, stdout);
	}
}
using namespace fast_IO;
const int N = 1000005;
int n, a[N], f[N], pre[N], suc[N];
double ans;
ll p[66];
inline bool cmp(int x, int y){ return a[x]<a[y];}
int main() {
//	freopen("drink.in", "r", stdin);
//	freopen("drink.out", "w", stdout);
	read(n);
	p[0]=1;
	rep(i, 1, 60) p[i]=p[i-1]<<1;
	rep(i, 1, n) read(a[i]), f[i]=i;
	rep(i, 0, n+1) pre[i]=i-1, suc[i]=i+1;
	sort(f+1, f+n+1, cmp);
	rep(sb, 1, n){
		int i=f[sb];
		double tmp=0, cnt=0;
		for(rt j=suc[i], tot=1; tot<=60 && j!=n+2; j=suc[j], ++tot)
			tmp+=(double)(j-pre[j])/p[tot];
		for(rt j=pre[i], tot=1; tot<=60 && ~j; j=pre[j], ++tot)
			cnt+=(suc[j]-j)*tmp, tmp/=2;
		suc[pre[i]]=suc[i];
		pre[suc[i]]=pre[i];
		ans+=cnt*a[i];
//		printf("%d %.15lf\n", i, cnt/((ll)n*n));
	}
	printf("%.15lf", ans/((ll)n*n));
	return 0;
}