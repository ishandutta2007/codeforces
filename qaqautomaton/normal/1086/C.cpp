/*
Author: CNYALI_LK
LANG: C++
PROG: 1086C.cpp
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
int k;
char ss[1000005],as[1000005],bs[1000005];
int a[1000005],b[1000005],s[1000005];
int to[31],oldto[31],n,qaq[31],oldqaq[31];
int wmore(int x){
	if(x==n)return 1;
	if(~to[s[x]]){
		if(to[s[x]]<a[x])return 0;
		if(to[s[x]]>a[x])return 1;
		return wmore(x+1);
	}
	for(int i=a[x]+1;i<k;++i)if(!qaq[i]){qaq[to[s[x]]=i]=1;return 1;}
	if(qaq[a[x]])return 0;
	qaq[to[s[x]]=a[x]]=1;
	return wmore(x+1);
}
int wless(int x){
	if(x==n)return 1;
	if(~to[s[x]]){
		if(to[s[x]]>b[x])return 0;
		if(to[s[x]]<b[x])return 1;
		return wless(x+1);
	}
	for(int i=0;i<b[x];++i)if(!qaq[i]){qaq[to[s[x]]=i]=1;return 1;}
	if(qaq[b[x]])return 0;
	qaq[to[s[x]]=b[x]]=1;
	return wless(x+1);
}
int work0(int x){
	if(x==n)return 1;
	if(~to[s[x]]){
		if(to[s[x]]<a[x]||b[x]<to[s[x]])return 0;
		else if(a[x]<to[s[x]] && to[s[x]]<b[x])return 1;
		else{
			if(a[x]==to[s[x]] && to[s[x]]==b[x])return work0(x+1);
			else if(a[x]==to[s[x]])return wmore(x+1);
			else return wless(x+1);
		}
	}
	else{
		if(a[x]>b[x])return 0;
		if(a[x]==b[x]){if(!qaq[a[x]]){qaq[to[s[x]]=a[x]]=1;return work0(x+1);}else return 0;}
		else{
			for(int i=a[x]+1;i<b[x];++i)if(!qaq[i]){qaq[to[s[x]]=i]=1;return 1;}
			for(int i=0;i<k;++i)oldto[i]=to[i],oldqaq[i]=qaq[i];
			if(!qaq[a[x]]){
				qaq[to[s[x]]=a[x]]=1;
				if(wmore(x+1))return 1;
				for(int i=0;i<k;++i)to[i]=oldto[i],qaq[i]=oldqaq[i];
			}
			if(!qaq[b[x]]){
				qaq[to[s[x]]=b[x]]=1;
				if(wless(x+1))return 1;
				for(int i=0;i<k;++i)to[i]=oldto[i],qaq[i]=oldqaq[i];
			}
			return 0;
		}
	}
}
int main(){
#ifdef cnyali_lk
	freopen("1086C.in","r",stdin);
	freopen("1086C.out","w",stdout);
#endif
	int t;
	scanf("%d",&t);
	for(;t;--t){
		scanf("%d\n%s%s%s",&k,ss,as,bs);
		n=strlen(ss);
		for(int i=0;i<n;++i)s[i]=ss[i]-'a',a[i]=as[i]-'a',b[i]=bs[i]-'a';
		for(int i=0;i<k;++i)to[i]=-1,qaq[i]=0;
		if(work0(0)){
			printf("YES\n");
			for(int i=0,j=0;i<k;++i){
				if(to[i]==-1){
					while(qaq[j])++j;
					qaq[to[i]=j]=1;
				}
				putchar(to[i]+'a');
			}
			putchar('\n');
		}
		else printf("NO\n");
	}
	return 0;
}