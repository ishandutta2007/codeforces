/*
Author: CNYALI_LK
LANG: C++
PROG: CF86D.cpp
*/
#include<bits/stdc++.h>
#define up(a,b,c) for (ll a(b),a##end(c);a<=a##end;++a)
#define down(a,c,b) for (ll a(b),a##end(c);a>=a##end;--a)
#define uup(a,c,b) for (ll a(b),a##end(c);a<=a##end;++a)
#define udown(a,b,c) for (ll a(b),a##end(c);a>=a##end;--a)
#define endl '\n'
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
const double eps=1e-8;
const double PI=acos(-1.0);
typedef long long ll;
template<class T>void chkmin(T &a,T b){a=a<b?a:b;}
template<class T>void chkmax(T &a,T b){a=a>b?a:b;}
template<class T>T sqr(T a){return a*a;}
template<class T>T mmin(T a,T b){return a<b?a:b;}
template<class T>T mmax(T a,T b){return a>b?a:b;}
struct inout{
	static const ll ibufl=1<<25;
	static const ll obufl=1<<25;
	char in_buf[ibufl],out_buf[obufl],*inf,*ouf;
	ll no;
	operator bool(){
		return !no;
	}
	inout(){
		inf=in_buf;ouf=out_buf;
		no=0;
	}
	void init(){
		fread(in_buf,1,ibufl,stdin);
	}
	inout& operator >>(ll &a){
		ll fh=1;
		while(!(isdigit(*inf)||*inf=='-'||*inf=='\0'))++inf;
		if(*inf=='\0'){
			no=1;
			a=0;
			return *this;
		}
		if(*inf=='-')fh=-1,++inf;
		a=0;
		while(isdigit(*inf)){a=a*10+*inf-'0';++inf;}
		a*=fh;
		return *this;
	}
	inout& operator >>(char &a){
		while(*inf==' '||*inf=='\n')++inf;
		if(*inf=='\0'){
			no=1;
			a=0;
			return *this;
		}

		a=*inf;
		++inf;
		return *this;
	}
	inout& operator >>(char *a){
		while(*inf==' '||*inf=='\n')++inf;
		if(*inf=0){
			a='\0';
			no=1;
			return *this;
		}
		while(!(*inf==' '||*inf=='\n'||*inf=='\0')){*a=*inf;++inf;++a;}
		*a='\0';
		return *this;
	}

	inout& operator >>(double &a){
		ll fh=1;
		double s;
		while(!(isdigit(*inf)||*inf=='-'||*inf=='.'||*inf=='\0'))++inf;
		if(*inf=='\0'){
			a=0;
			no=1;
			return *this;
		}
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
struct ques{
	ll l,r,t;
};
ques ask[201010];
ll askl(ques a,ques b){return a.l<b.l||a.l==b.l&&a.r<b.r;}
ll askr(ques a,ques b){return a.r<b.r||a.r==b.r&&a.l<b.l;}
ll a[201010],sum[1001010],tot,ans[201010];
void add(ll x){tot+=x*(sum[x]*2+1);++sum[x];}
void rm(ll x){tot-=x*(sum[x]*2-1);--sum[x];}
int main(){
#ifdef cnyali_lk
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	io.init();
	ll n,s,l,r,m;
	io>>n>>m;
	up(i,1,n)io>>a[i];
	up(i,1,m){
		io>>ask[i].l>>ask[i].r;
		ask[i].t=i;
	}
	sort(ask+1,ask+m+1,askl);
	l=1,r=1000;
	ll mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(sqr(mid)<=m)l=mid+1;
		else r=mid-1;
	}
	s=l-1;
	for(ll i=1,j=s;i<=m;i+=s,j=mmin(j+s,m)){sort(ask+i,ask+j+1,askr);}
	l=ask[1].l;
	r=ask[1].r;
	up(i,l,r){
		add(a[i]);
	}
	ans[ask[1].t]=tot;
	up(i,2,m){
		while(l>ask[i].l){--l;add(a[l]);}
		while(r<ask[i].r){++r;add(a[r]);}
		while(l<ask[i].l){rm(a[l]);++l;}
		while(r>ask[i].r){rm(a[r]);--r;}	
		ans[ask[i].t]=tot;
	}
	up(i,1,m)io<<ans[i]<<endl;

	io.out();
	return 0;
}