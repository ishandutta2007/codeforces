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
			x = (x + (x << 2) << 1) + (c ^ '0');
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
const int N = 100005, M = 400005;
int a[N], mx[M], n, m, P, L, R;
ll s[M];
#define update s[t]=s[k]+s[k|1], mx[t]=max(mx[k], mx[k|1])
void build(int l, int r, int t){
	if(l==r) return (void)(mx[t]=s[t]=a[l]);
	int mid=l+r>>1, k=t<<1;
	build(l, mid, k), build(mid+1, r, k|1);
	update;
}
void change(int l, int r, int t){
	if(l==r) return (void)(mx[t]=(s[t]%=P));
	int mid=l+r>>1, k=t<<1;
	if(L<=mid && mx[k]>=P) change(l, mid, k);
	if(R>mid && mx[k|1]>=P) change(mid+1, r, k|1);
	update;
}
void modify(int l, int r, int t){
	if(l==r) return (void)(mx[t]=s[t]=P);
	int mid=l+r>>1, k=t<<1;
	if(L<=mid) modify(l, mid, k); else modify(mid+1, r, k|1);
	update;
}
ll query(int l, int r, int t){
	if(L<=l && r<=R) return s[t];
	int mid=l+r>>1, k=t<<1;
	return (L<=mid?query(l, mid, k):0)+(R>mid?query(mid+1, r, k|1):0);
}
int main() {
//	freopen("mod.in", "r", stdin);
//	freopen("mod.out", "w", stdout);
	read(n), read(m);
	rep(i, 1, n) read(a[i]);
	build(1, n, 1);
	while(m--){
		static int opt;
		read(opt);
		if(opt==1) read(L), read(R), print(query(1, n, 1)), print('\n');
		else if(opt==2) read(L), read(R), read(P), change(1, n, 1);
		else read(L), read(P), modify(1, n, 1);
//		rep(i, 1, n) L=R=i, printf("%lld ", query(1, n, 1)); puts("");
	}
	flush();
	return 0;
}