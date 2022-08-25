/*
Author: CNYALI_LK
LANG: C++
PROG: 1086D.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
using namespace std;
const double eps=1e-8;
const double pi=acos(-1.0);
typedef long long ll;
typedef pair<int,int> pii;
template<class T>int chkmin(T &a,T b){return a>b?a=b,1:0;}
template<class T>int chkmax(T &a,T b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T>T mmin(T a,T b){return a<b?a:b;}
template<class T>T mmax(T a,T b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
template<class T>int dcmp(T a,T b){return a>b;}
template<int *a>int cmp_a(int x,int y){return a[x]<a[y];}
#define min mmin
#define max mmax
#define abs aabs
namespace io {
    const int SIZE = (1 << 21) + 1;
    char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
    // getchar
    #define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
    // print the remaining part
    inline void flush () {
        fwrite (obuf, 1, oS - obuf, stdout);
        oS = obuf;
    }
    // putchar
    inline void putc (char x) {
        *oS ++ = x;
        if (oS == oT) flush ();
    }
    // input a signed integer
    inline void read (int &x) {
        for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
        for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
    }
    inline void read (char &x) {
        x=gc();
    }
    inline void read(char *x){
        while((*x=gc())=='\n' || *x==' '||*x=='\r');
        while(!(*x=='\n'||*x==' '||*x=='\r'))*(++x)=gc();
    }
    template<typename A,typename ...B>
    inline void read(A &x,B &...y){
        read(x);read(y...);
    }
    // print a signed integer
    inline void write (int x) {
        if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
        while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
        while (qr) putc (qu[qr --]);
    }
    inline void write (char x) {
        putc(x);
    }
    inline void write(const char *x){
        while(*x){putc(*x);++x;}
    }
    inline void write(char *x){
        while(*x){putc(*x);++x;}
    }
    template<typename A,typename ...B>
    inline void write(A x,B ...y){
        write(x);write(y...);
    }
    //no need to call flush at the end manually!
    struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: read;
using io :: putc;
using io :: write;
/*
 * P win R win S win P
 * */
set<int> R,P,S;
int n,q,p;	
char s[200005];

struct BIT{
	int a[200005];
	void add(int x,int y){
		for(;x<=n;x+=x&-x)a[x]+=y;
	}
	int sum(int x){
		int y=0;
		for(;x;x&=x-1)y+=a[x];
		return y;
		
	}
};
BIT Rb,Pb,Sb;
void insert(int x){
	if(s[x]=='R'){R.insert(x);Rb.add(x,1);}
	if(s[x]=='P'){P.insert(x);Pb.add(x,1);}
	if(s[x]=='S'){S.insert(x);Sb.add(x,1);}
}
void remove(int x){
	if(s[x]=='R'){R.erase(x);Rb.add(x,-1);}
	if(s[x]=='P'){P.erase(x);Pb.add(x,-1);}
	if(s[x]=='S'){S.erase(x);Sb.add(x,-1);}
}
int query(){
	int ans=n;
	
	if(S.empty());
	else
	if(P.empty()){if(!R.empty())ans-=S.size();}
	else if(!R.empty()){
	/*S After  the first R and before the first P GG*/
		if(*R.begin()<*P.begin())
		ans+=Sb.sum(*R.begin())-Sb.sum(*P.begin());
	/*S After  the last P and before the last R GG*/
		if(*P.rbegin()<*R.rbegin())
		ans+=Sb.sum(*P.rbegin())-Sb.sum(*R.rbegin());
	}
	if(P.empty());
	else
	if(R.empty()){if(!S.empty())ans-=P.size();}
	else if(!S.empty()){
	/*P After  the first S and before the first R GG*/
		if(*S.begin()<*R.begin())
		ans+=(Pb.sum(*S.begin())-Pb.sum(*R.begin()));
	/*P After  the last R and before the last S GG*/
		if(*R.rbegin()<*S.rbegin())
		ans+=(Pb.sum(*R.rbegin())-Pb.sum(*S.rbegin()));
	}
	if(P.empty());
	if(R.empty());
	else
	if(S.empty()){if(!P.empty())ans-=R.size();}
	else if(!P.empty()){
	/*R After  the first P and before the first S GG*/
		if(*P.begin()<*S.begin())
		ans+=(Rb.sum(*P.begin())-Rb.sum(*S.begin()));
	/*R After  the last S and before the last P GG*/
		if(*S.rbegin()<*P.rbegin())
		ans+=(Rb.sum(*S.rbegin())-Rb.sum(*P.rbegin()));
	}
	return ans;
}
int main(){
#ifdef cnyali_lk
	freopen("1086D.in","r",stdin);
	freopen("1086D.out","w",stdout);
#endif
	char c;
	scanf("%d%d\n%s",&n,&q,s+1);
	for(int i=1;i<=n;++i){
		insert(i);
	}
	printf("%d\n",query());
	for(;q;--q){
		scanf("%d %c",&p,&c);
		remove(p);
		s[p]=c;
		insert(p);
		printf("%d\n",query());
	}
	return 0;
}