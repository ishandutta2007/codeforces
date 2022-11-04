#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>
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

const int N = 105;
int T, cnt[26], a[27];
char s[N];
int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%s", s);
		memset(cnt, 0, sizeof cnt);
		for(int i=0; s[i]; ++i) ++cnt[s[i]-'a'];
		int x=0;
		for(int i=0; i<26; ++i) if(cnt[i]>0) a[++x]=i;
		if(x==2){
			if(a[1]+1==a[2]){
				puts("No answer");
				goto nxt;
			}
			while(cnt[a[1]]--) putchar('a'+a[1]);
			while(cnt[a[2]]--) putchar('a'+a[2]);
		}
		else if(x==3){
			if(a[1]+1==a[2] && a[2]+1==a[3]){
				puts("No answer");
				goto nxt;
			}
			if(a[1]+1==a[2]){
				while(cnt[a[2]]--) putchar('a'+a[2]);
				while(cnt[a[3]]--) putchar('a'+a[3]);
				while(cnt[a[1]]--) putchar('a'+a[1]);
			}
			else{
				while(cnt[a[2]]--) putchar('a'+a[2]);
				while(cnt[a[1]]--) putchar('a'+a[1]);
				while(cnt[a[3]]--) putchar('a'+a[3]);
			}
		}
		else{
			for(int i=2; i<=x; i+=2)
				while(cnt[a[i]]--) putchar('a'+a[i]);
			for(int i=1; i<=x; i+=2)
				while(cnt[a[i]]--) putchar('a'+a[i]);
		}
		puts("");
		nxt:;
	}
	return 0;
}