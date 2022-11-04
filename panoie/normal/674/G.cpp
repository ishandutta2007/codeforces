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
const int K = 6, N = 150005;
int n, m, p, L, R, a[N], cov[N<<2];
struct st{
	int a[K], b[K];
	inline st operator +(const st &rhs)const{
		st ass=*this;
		rep(i, 1, p) if(rhs.a[i]){
			rt j=1;
			for(; j<=p; ++j) if(ass.a[j]==rhs.a[i]) break;
			if(j<=p) ass.b[j]+=rhs.b[i];
			else{
				rt mn=1E9;
				for(j=1; j<=p; ++j) mn=min(mn, ass.b[j]);
				if(mn>=rhs.b[i]) for(j=1; j<=p; ++j) ass.b[j]-=rhs.b[i];
				else{
					for(j=1; j<=p; ++j) ass.b[j]-=mn;
					for(j=1; j<=p; ++j) if(!ass.b[j]){
						ass.a[j]=rhs.a[i], ass.b[j]=rhs.b[i]-mn;
						break;
					}
				}
			}
		}
		return ass;
	}
}s[N<<2];
void build(int l, int r, int t){
	if(l==r) return (void)(s[t].a[1]=a[l], s[t].b[1]=1);
	int mid=l+r>>1, k=t<<1;
	build(l, mid, k), build(mid+1, r, k|1);
	s[t]=s[k]+s[k|1];
}
void change(int l, int r, int t, int val){
//	printf("%d %d %d %d\n", l, r, L, R);
	if(L<=l && r<=R){
		cov[t]=val, memset(s+t, 0, K<<3);
		s[t].a[1]=val, s[t].b[1]=r-l+1;
		return;
	}
	int mid=l+r>>1, k=t<<1;
	if(cov[t])
		cov[k]=cov[k|1]=cov[t],
		memset(s+k, 0, K<<4), s[k].a[1]=cov[t], s[k].b[1]=mid-l+1,
		s[k|1].a[1]=cov[t], s[k|1].b[1]=r-mid,
		cov[t]=0;
	if(L<=mid) change(l, mid, k, val);
	if(R>mid) change(mid+1, r, k|1, val);
	s[t]=s[k]+s[k|1];
}
st query(int l, int r, int t){
	if(L<=l && r<=R) return s[t];
	int mid=l+r>>1, k=t<<1;
	if(cov[t])
		cov[k]=cov[k|1]=cov[t],
		memset(s+k, 0, K<<4), s[k].a[1]=cov[t], s[k].b[1]=mid-l+1,
		s[k|1].a[1]=cov[t], s[k|1].b[1]=r-mid,
		cov[t]=0;
	if(R<=mid) return query(l, mid, k);
	if(L>mid) return query(mid+1, r, k|1);
	return query(l, mid, k)+query(mid+1, r, k|1);
}
int main() {
	read(n), read(m), read(p);
	p=100/p;
	rep(i, 1, n) read(a[i]);
	build(1, n, 1);
	while(m--){
		static int opt;
		read(opt), read(L), read(R);
		if(opt==1){
			static int x;
			read(x);
			change(1, n, 1, x);
		}
		else{
			st tmp=query(1, n, 1);
			print(p);
			rep(i, 1, p) print(' '), print(tmp.a[i]);
			print('\n');
		}
	}
	return flush(), 0;
}