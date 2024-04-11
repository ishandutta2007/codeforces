/*
Author: QAQ-Automaton
LANG: C++
PROG: L.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %lld\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %lld\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const signed inf=0x3f3f3f3f;
const double eps=1e-8;
const double pi=acos(-1.0);
template<class T>ll chkmin(T &a,T b){return a>b?a=b,1:0;}
template<class T>ll chkmax(T &a,T b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T>T mmin(T a,T b){return a<b?a:b;}
template<class T>T mmax(T a,T b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
template<class T>ll dcmp(T a,T b){return a>b;}
template<ll *a>ll cmp_a(ll x,ll y){return a[x]<a[y];}
#define min mmin
#define max mmax
#define abs aabs
namespace io {
	const ll SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; ll f, qr;
	// getchar
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	// prll the remaining part
	inline void flush () {
		fwrite (obuf, 1, oS - obuf, stdout);
		oS = obuf;
	}
	// putchar
	inline void putc (char x) {
		*oS ++ = x;
		if (oS == oT) flush ();
	}
	// input a signed lleger
	inline bool read (signed &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;else if(c==EOF)return 0;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
		return 1;
	}

	inline bool read (long long &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;else if(c==EOF)return 0;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
		return 1;
	}
	inline bool read (char &x) {
		x=gc();
		return x!=EOF;
	}
	inline bool read(char *x){
		while((*x=gc())=='\n' || *x==' '||*x=='\r')if(*x==EOF)return 0;
		while(!(*x=='\n'||*x==' '||*x=='\r'))*(++x)=gc();
		*x=0;
		return 1;
	}
	template<typename A,typename ...B>
	inline bool read(A &x,B &...y){
		return read(x)&&read(y...);
	}
	// prll a signed lleger
	inline bool write (signed x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
		return 0;
	}

	inline bool write (long long x) {
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
priority_queue<pii,vector<pii>,greater<pii> > cars[200005];
typedef pair<ll,pii> piii;
typedef pair<ll,pair<pii,ll> >piiii;
priority_queue<piii,vector<piii>,greater<piii> > willOK;
set<ll> qaq;
ll cnt[200005];
void add(ll x){
	if(!cnt[x])qaq.insert(x);
	++cnt[x];
}
void del(ll x){
	if(!(--cnt[x]))qaq.erase(x);
}
piiii closest(ll x){
	auto i=qaq.lower_bound(x);
	if(i==qaq.end()){ 
		--i;
		return make_pair(abs(*i-x),make_pair(cars[*i].top(),*i));
	}
	if(i==qaq.begin()){
		return make_pair(abs(*i-x),make_pair(cars[*i].top(),*i));
	}
	piiii s=
		make_pair(abs(*i-x),make_pair(cars[*i].top(),*i));
	--i;
	chkmin(s,
		make_pair(abs(*i-x),make_pair(cars[*i].top(),*i)));
	return s;
}
int main(){
#ifdef QAQAutoMaton 
	freopen("L.in","r",stdin);
	freopen("L.out","w",stdout); 
#endif
	ll n,k,m,x,a,b,t,xt=0;
	read(n,k,m);
	for(ll i=1;i<=k;++i){
		read(x);
		cars[x].push(make_pair(0,i));
		add(x);
	}
	for(;m;--m){
		read(t,a,b);	
		ll st=t;
		while(!(willOK.empty()) && willOK.top().x<=t){
			cars[willOK.top().y.x].push(make_pair(willOK.top().x,willOK.top().y.y));
			add(willOK.top().y.x);
			willOK.pop();
		}
		if(qaq.empty()){
			xt=willOK.top().x;
			while(!willOK.empty() && willOK.top().x==xt){
				cars[willOK.top().y.x].push(make_pair(willOK.top().x,willOK.top().y.y));
				add(willOK.top().y.x);
				willOK.pop();
			}
		}
		chkmax(t,xt);
		piiii car=closest(a);
		cars[car.y.y].pop();
		del(car.y.y);
		t+=car.x;
		willOK.push(make_pair(t+abs(b-a),make_pair(b,car.y.x.y)));
		write(car.y.x.y,' ',t-st,'\n');
	}
	return 0;
}