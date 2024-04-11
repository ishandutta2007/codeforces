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
		//return getchar();
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
const int N = 500005;
int n, tot, x, q, a[N], pos[N], s[N<<2], st[N];
bool und[N<<2];
int gcd(int x, int y){
	return y?gcd(y, x%y):x;
}
void build(int l, int r, int t){
	if(l==r) return (void)(pos[l]=t, s[t]=a[l], und[t]=1);
	int mid=l+r>>1, k=t<<1;
	build(l, mid, k), build(mid+1, r, k|1);
	s[t]=gcd(s[k], s[k|1]);
}
void gt(int l, int r, int t, int L, int R){
	if(L<=l && r<=R) return (void)(st[++tot]=t);
	int mid=l+r>>1, k=t<<1;
	if(L<=mid) gt(l, mid, k, L, R);
	if(R>mid) gt(mid+1, r, k|1, L, R);
}
bool check(int t){
	if(und[t]) return s[t]%x;
	if(s[t<<1]%x && s[t<<1|1]%x) return 0;
	return check(s[t<<1]%x?t<<1:t<<1|1);
}
inline void modify(int f, int v){
	int i=pos[f]; s[i]=v;
	for(i>>=1; i; i>>=1) s[i]=gcd(s[i<<1], s[i<<1|1]);
}
int main() {
	read(n);
	rep(i, 1, n) read(a[i]);
	build(1, n, 1);
	read(q);
	while(q--){
		static int opt, L, R;
		read(opt), read(L), read(R);
		if(opt==1){
			read(x);
			tot=0;
			gt(1, n, 1, L, R);
			int tmp=0, cnt=0;
			rep(i, 1, tot) if(s[st[i]]%x) ++cnt, tmp=st[i];
			if(cnt>1 || cnt && !check(tmp)) puts("NO");
			else puts("YES");
		}
		else modify(L, R);
	}
	
	return 0;
}