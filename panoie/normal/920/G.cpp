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
const int N = 1000005;
int cnt, T, sb, p, k, a[12], s[N], prime[N];
ll calc(ll num, int x=1, ll pi=1){
	if(abs(pi)>num) return 0; 
	if(x==cnt+1) return pi>0?num/pi:-(num/-pi);
	return calc(num, x+1, -pi*a[x])+calc(num, x+1, pi);
}
int main() {
	rep(i, 2, 1000000){
		if(!s[i]) s[i]=i, prime[++cnt]=i;
		for(rt j=1; j<=cnt && i*prime[j]<=1000000; ++j){
			s[i*prime[j]]=prime[j];
			if(i%prime[j]==0) break;
		}
	}
	read(T);
	while(T--){
		read(sb), read(p), read(k);
		cnt=0;
		for(rt i=p, last=0; i!=1; i/=(last=s[i])) if(s[i]!=last) a[++cnt]=s[i];
		k+=calc(sb);
//		printf("%d\n", cnt);
//		printf("%lld\n", calc(sb));
		ll l=1, r=1E11, ass=0;
		while(l<=r){
			ll mid=l+r>>1;
			if(calc(mid)>=k) r=mid-1, ass=mid; else l=mid+1;
		}
		print(ass), print('\n');
	}
	return flush(), 0;
}