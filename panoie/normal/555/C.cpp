#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<set>
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
const int N = 20000005;
int n, m;
struct node{
	int s;
	node *lson, *rson;
}T[N], *root1=T, *root2=T, *tot=T;
node *New(){
	++tot;
	tot->lson=tot->rson=T;
	tot->s=0;
	return tot;
}
void change(int l, int r, node *&t, int L, int R, int val){
//	printf("%d %d %d %d\n", l, r, L, R);
	if(t==T) t=New();
	if(L<=l && r<=R) return (void)(t->s=max(t->s, val));
	int mid=l+r>>1;
	if(L<=mid) change(l, mid, t->lson, L, R, val);
	if(R>mid) change(mid+1, r, t->rson, L, R, val);
}
int query(int l, int r, node *t, int pos){
	if(t==T) return 0;
	if(l==r) return t->s;
	int mid=l+r>>1;
	return max(t->s,(pos<=mid?query(l, mid, t->lson, pos):query(mid+1, r, t->rson, pos)));
}
set<int> vis;
int main() {
	read(n), read(m);
	rep(i, 1, m){
		static int x, y, ass;
		static char ch;
		read(x), read(y);
		while(!isupper(ch=read()));
		if(vis.count(x)){
			print('0'), print('\n');
			continue;
		}
		if(ch=='U'){
			ass=query(1, n, root1, x);
			print(y-ass), print('\n');
			change(1, n, root2, ass+1, y, x);
		}
		else{
			ass=query(1, n, root2, y);
			print(x-ass), print('\n');
			change(1, n, root1, ass+1, x, y);
		}
		vis.insert(x);
	}
	flush();
	return 0;
}