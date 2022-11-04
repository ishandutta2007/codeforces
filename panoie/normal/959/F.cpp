#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#include<math.h>
using namespace std;
#define ll long long
#define rt register int
#define Rep(i,x,y) for(rt i=(x);i<(y);++i)
#define per(i,x,y) for(rt i=(x);i>=(y);--i)
#define rep(i,x,y) for(rt i=(x);i<=(y);++i)
#define travel(i,x) for(rt i=h[x];i;i=pre[i])
namespace fast_IO {
	inline char read() {
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
const int N = 100005, P = 1000000007;
int n, q, a[N], ans[N], p[N];
struct query{
	int l, x, id;
	inline bool operator <(const query &rhs)const{ return l<rhs.l;}
}b[N];
struct gay{
	int cnt, a[20];
	inline void insert(int x){
		if(cnt<20){
			per(i, 19, 0) if(x>>i&1) if(a[i]) x^=a[i]; else{
				a[i]=x, ++cnt;
				break;
			}
		}
	}
	inline bool check(int x){
		per(i, 19, 0) if(x>>i&1) if(a[i]) x^=a[i]; else return 0;
		return 1;
	}
}g;
int main() {
	read(n), read(q);
	p[0]=1;
	rep(i, 1, n) p[i]=(p[i-1]<<1)%P;
	rep(i, 1, n) read(a[i]);
	rep(i, 1, q) read(b[i].l), read(b[i].x), b[i].id=i;
	sort(b+1, b+q+1);
	rt j=1;
	rep(i, 1, n){
		g.insert(a[i]);
		while(b[j].l==i) ans[b[j].id]=(g.check(b[j].x)?p[i-g.cnt]:0), ++j;
	}
	rep(i, 1, q) print(ans[i]), print('\n');
	return flush(), 0;
}