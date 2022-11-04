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
		return getchar();
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
const int N = 300005;
int n, m, L, R, a[N], f[1000005];
bool w[N<<2];
ll s[N<<2];
void build(int l, int r, int t){
	if(l==r) return (void)(s[t]=a[l], w[t]=(f[s[t]]==s[t]));
	int mid=l+r>>1, k=t<<1;
	build(l, mid, k), build(mid+1, r, k|1);
	s[t]=s[k]+s[k|1], w[t]=w[k]&&w[k|1];
}
void change(int l, int r, int t){
	if(l==r){
		s[t]=f[s[t]];
		w[t]=(f[s[t]]==s[t]);
		return;
	}
	int mid=l+r>>1, k=t<<1;
	if(L<=mid && !w[k]) change(l, mid, k);
	if(R>mid && !w[k|1]) change(mid+1, r, k|1);
	s[t]=s[k]+s[k|1], w[t]=w[k]&&w[k|1];
}
ll query(int l, int r, int t){
	if(L<=l && r<=R) return s[t];
	int mid=l+r>>1, k=t<<1;
	return (L<=mid?query(l, mid, k):0)+(R>mid?query(mid+1, r, k|1):0);
}
int main() {
	read(n), read(m);
	rep(i, 1, n) read(a[i]);
	build(1, n, 1);
	rep(i, 1, 1000000) for(rt j=i; j<=1000000; j+=i) ++f[j];
	while(m--){
		static int opt;
		read(opt), read(L), read(R);
		if(opt==1) change(1, n, 1);
		else print(query(1, n, 1)), print('\n');
	}
	return flush(), 0;
}