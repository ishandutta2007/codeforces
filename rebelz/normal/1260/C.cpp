#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

namespace FastIO {
	#define SIZE 100000
	inline char nc(){
		#ifdef WIN32
			return getchar();
		#endif
		static char buf[SIZE],*p1=buf+SIZE,*p2=buf+SIZE;
		if(p1==p2) p2=(p1=buf)+fread(buf,1,SIZE,stdin);
		return p1==p2?-1:*p1++;
	}
	inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
	template <class T> inline void read(T &x){
		register double tmp=1;
		register bool sign=0;
		x = 0;
		register char ch=nc();
		for(;ch<'0'||ch>'9';ch=nc()) if(ch=='-') sign=1;
		for(;ch>='0'&&ch<='9';ch=nc()) x=x*10+ch-'0';
		if(ch=='.') for(ch=nc();ch>='0'&&ch<='9';ch=nc()) tmp/=10.0,x+=tmp*(ch-48);
		if(sign) x=-x;
	}
	inline void read(char *s){
		register char ch=nc();
		for(;blank(ch);ch=nc());
		for(;!blank(ch);ch=nc()) *s++=ch;
		*s=0;
	}
	inline void read(char &c){
		for(c=nc();blank(c);c=nc());
	}
	template <class T> inline void print(T x){
		if(x<0) putchar('-'),x=-x;
		if(x>9) print(x/10);
		putchar('0'+x%10);
	}
	template <class T> inline void print(T x,char c){
		print(x),putchar(c);
	}
}
using namespace FastIO;

int a,b,k;

int gcd(int x,int y){return y==0?x:gcd(y,x%y);}

int main(){
	int T; read(T);
	while(T--){
		read(a),read(b),read(k);
		int g=gcd(a,b);
		a/=g,b/=g;
		if(a>b) swap(a,b);
		if(k==1){
			puts("REBEL");
			continue;
		}
		int tmp=(b-2)/a+1;
		if(tmp>=k){
			puts("REBEL");
			continue;
		}
		puts("OBEY");
	}
	return 0;
}