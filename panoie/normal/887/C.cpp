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
int a[33], b[33], c[33];
inline bool check(){
	rep(i, 1, 24) if(i%4) if(b[i]!=b[i+1]) return 0;
	return 1;
}
inline void work1(){
	memcpy(c, b, sizeof c);
	c[23]=b[2];
	c[21]=b[4];
	c[2]=b[6];
	c[4]=b[8];
	c[6]=b[10];
	c[8]=b[12];
	c[10]=b[23];
	c[12]=b[21];
	memcpy(b, c, sizeof c);
}
inline void work2(){
	memcpy(c, b, sizeof c);
	c[4]=b[14];
	c[3]=b[16];
	c[14]=b[9];
	c[16]=b[10];
	c[9]=b[19];
	c[10]=b[17];
	c[19]=b[4];
	c[17]=b[3];
	memcpy(b, c, sizeof c);
}
inline void work3(){
	memcpy(c, b, sizeof c);
	c[24]=b[20];
	c[23]=b[19];
	c[20]=b[8];
	c[19]=b[7];
	c[8]=b[16];
	c[7]=b[15];
	c[16]=b[24];
	c[15]=b[23];
	memcpy(b, c, sizeof c);
}
int main() {
	rep(i, 1, 24) read(a[i]);
	memcpy(b, a, sizeof a);
	work1();
	if(check()){
		puts("YES");
		return 0;
	}
	work1();
	work1();
	if(check()){
		puts("YES");
		return 0;
	}
	
	memcpy(b, a, sizeof a);
	work2();
	if(check()){
		puts("YES");
		return 0;
	}
	work2();
	work2();
	if(check()){
		puts("YES");
		return 0;
	}
	
	memcpy(b, a, sizeof a);
	work3();
	if(check()){
		puts("YES");
		return 0;
	}
	work3();
	work3();
	if(check()){
		puts("YES");
		return 0;
	}
	
	puts("NO");
	return 0;
}