/*
Author: CNYALI_LK
LANG: C++
PROG: CF580D.cpp
*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#define up(a,b,c) for (ll a(b),end##a(c);a<=end##a;++a)
#define down(a,c,b) for (ll a(b),end##a(c);a>=end##a;--a)
#define uup(a,c,b) for (ll a(b),end##a(c);a<=end##a;++a)
#define udown(a,b,c) for (ll a(b),end##a(c);a>=end##a;--a)
#define endl '\n'
#define debug(...) fprllf(stderr,__VA_ARGS__)
using namespace std;
const double eps=1e-8;
const double PI=acos(-1.0);
typedef long long ll;
struct inout{
	static const ll ibufl=1<<25;
	static const ll obufl=1<<25;
	char in_buf[ibufl],out_buf[obufl],*inf=in_buf,*ouf=out_buf;
	void init(){
		fread(in_buf,1,ibufl,stdin);
	}
	inout& operator >>(ll &a){
		ll fh=1;
		while(!(isdigit(*inf)||*inf=='-'))++inf;
		if(*inf=='-')fh=-1,++inf;
		a=0;
		while(isdigit(*inf)){a=a*10+*inf-'0';++inf;}
		a*=fh;
		return *this;
	}
	inout& operator >>(char &a){
		while(*inf==' '||*inf=='\n')++inf;
		a=*inf;
		++inf;
		return *this;
	}
	inout& operator >>(char *a){
		while(*inf==' '||*inf=='\n')++inf;
		while(!(*inf==' '||*inf=='\n'||*inf=='\0')){*a=*inf;++inf;++a;}
		*a='\0';
		return *this;
	}

	inout& operator >>(double &a){
		ll fh=1;
		double s;
		while(!(isdigit(*inf)||*inf=='-'||*inf=='.'))++inf;
		if(*inf=='-')fh=-1,++inf;
		a=0;
		while(isdigit(*inf)){a=a*10+*inf-'0';++inf;}
		if(*inf=='.'){
			s=0.1;
			++inf;
			while(isdigit(*inf)){
				a+=s*(*inf-'0');
				++inf;
				s*=0.1;
			}
		}
		if(*inf=='E'||*inf=='e'){
			ll ss;
			++inf;
			*this>>ss;
			if(ss>0){
				while(ss){
					--ss;
					a*=10;
				}
			}
			if(ss<0){
				while(ss){
					++ss;
					a/=10;
				}
			}
			
		}
		a*=fh;
		return *this;
	}
	void writell(ll x){
		if(x/10)writell(x/10);
		*ouf=x%10+'0';
		++ouf;
	}
	inout& operator <<(ll a){
		
		if(a<0){*ouf='-';++ouf;a=-a;}
		writell(a);
		return *this;
	}
	static const ll sz=7;
	inout& operator <<(char a){
		*ouf=a;++ouf;
		return *this;
	}
	inout& operator <<(char *a){
		while(*a){
			*ouf=*a;
			++ouf;
			++a;
		}
		return *this;
	}
	inout& operator <<(double a){
		if(a<-eps){*ouf='-';++ouf;a=-a;}
		writell((ll)a);
		a-=(ll)a;
		*ouf='.';
		++ouf;
		up(i,1,sz){
			a=a*10;
			*ouf=(ll)a+'0';
			++ouf;
			a-=(ll)a;
		}
		return *this;
	}
	void out(){
		fwrite(out_buf,1,ouf-out_buf,stdout);
		ouf=out_buf;
	}
};
inout io;
template<class T>void chkmin(T &a,T b){a=a<b?a:b;}
template<class T>void chkmax(T &a,T b){a=a>b?a:b;}
ll g[23][23],a[23],f[1<<20][20];
ll lowbit(ll x){return x&(-x);}
ll count(ll x){
	ll tot=0;
	while(x){
		x-=lowbit(x);
		++tot;
	}
	return tot;
}
int main(){
#ifdef cnyali_lk
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	io.init();
	ll n,m,k,s,u,v,w;
	io>>n>>m>>k;
	s=1<<n;
	--s;
	up(i,1,n)io>>a[i];
	up(i,1,k){
		io>>u>>v>>w;
		g[v][u]=w;
	}
	up(i,0,s){
		up(j,1,n){
			if(i&(1<<(j-1))){
				ll t=i^(1<<(j-1));
				f[i][j]=0;
				up(k,1,n)if(t&(1<<(k-1))){
					chkmax(f[i][j],f[t][k]+g[j][k]);
				}
				f[i][j]+=a[j];
				
			}	
			else f[i][j]=0;
		}
	}
	ll ans=0;
	up(i,0,s)if(count(i)==m)up(j,1,n)if(i&(1<<(j-1)))chkmax(ans,f[i][j]);
	io<<ans<<endl;
	io.out();
	return 0;
}