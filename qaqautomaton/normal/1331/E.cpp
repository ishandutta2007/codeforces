/*
Author: QAQAutomaton
Lang: C++
Code: E.cpp
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int inf;
const double eps=1e-8;
const double pi=acos(-1.0);
template<class T,class T2>int chkmin(T &a,T2 b){return a>b?a=b,1:0;}
template<class T,class T2>int chkmax(T &a,T2 b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T,class T2>T mmin(T a,T2 b){return a<b?a:b;}
template<class T,class T2>T mmax(T a,T2 b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
template<class T>int dcmp(T a,T b){return a>b;}
template<int *a>int cmp_a(int x,int y){return a[x]<a[y];}
#define min mmin
#define max mmax
#define abs aabs
struct __INIT__{
	__INIT__(){
		memset(&inf,0x3f,sizeof(inf));
	}
}__INIT___;
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
	template<typename A>
	inline bool read (A &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;else if(c==EOF)return 0;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
		return 1;
	}
	inline bool read (char &x) {
		while((x=gc())==' '||x=='\n' || x=='\r');
		return x!=EOF;
	}
	inline bool read(char *x){
		while((*x=gc())=='\n' || *x==' '||*x=='\r');
		if(*x==EOF)return 0;
		while(!(*x=='\n'||*x==' '||*x=='\r'||*x==EOF))*(++x)=gc();
		*x=0;
		return 1;
	}
	template<typename A,typename ...B>
	inline bool read(A &x,B &...y){
		return read(x)&&read(y...);
	}
	template<typename A>
	inline bool write (A x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
		return 0;
	}
	inline bool write (char x) {
		putc(x);
		return 0;
	}
	inline bool write(const char *x){
		while(*x){putc(*x);++x;}
		return 0;
	}
	inline bool write(char *x){
		while(*x){putc(*x);++x;}
		return 0;
	}
	template<typename A,typename ...B>
	inline bool write(A x,B ...y){
		return write(x)||write(y...);
	}
	//no need to call flush at the end manually!
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: read;
using io :: putc;
using io :: write;
unsigned long long ls[64]={18446743798898753535ULL,18446739675667234815ULL,18446726481524555775ULL,18446603336222113791ULL,18446462598734741503ULL,18445618173804298239ULL,18444492273899544575ULL,18437736874457958399ULL,18428729675207410687ULL,18410724072789901823ULL,18374818421115191551ULL,18302664073138929791ULL,18303174264586502271ULL,18158654493758062655ULL,17871937017542082591ULL,17872288888198791231ULL,17301809529207390319ULL,16156312178681446599ULL,16168626868288749591ULL,16152371350262513783ULL,13839421397950529747ULL,13860602195796819995ULL,9281989707679400273ULL,9243286738572935647ULL,9363687448391450945ULL,9306547929992921469ULL,104926523869364292ULL,80646992874701271ULL,23897912467521808ULL,54520877445809015ULL,30714995297747220ULL,19269954620621278ULL,134761335568203848ULL,247840564634976618ULL,80432037638439182ULL,128634173610000800ULL,26810559647187127ULL,127719276168610708ULL,9325969766558466805ULL,9297329708437340253ULL,9354117202666062081ULL,9267141669302043069ULL,13838084085312913639ULL,13852615478739468851ULL,16146179046281053063ULL,16147094055406797055ULL,16142167858272534567ULL,17296004486102253967ULL,17870917034013884671ULL,17871233336265933215ULL,18158584193957757247ULL,18302875275756568703ULL,18302664093875568767ULL,18374809628813820159ULL,18410750468551606783ULL,18428729675206362111ULL,18437736874462152703ULL,18444492273899020287ULL,18445618173805871103ULL,18446462598736576511ULL,18446603336222900223ULL,18446726481525604351ULL,18446739675667234815ULL,18446743798898753535ULL};
signed main(){
#ifdef QAQAutoMaton 
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	int x,y;	
	read(x,y);
	write(ls[y]&(1ULL<<x)?"OUT\n":"IN\n");
	return 0;
}