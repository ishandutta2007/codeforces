/*
Author: CNYALI_LK
LANG: C++
PROG: c.cpp
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
const double eps=1e-8;
const double pi=acos(-1.0);
typedef long long ll;
typedef pair<ll,ll> pii;
template<class T>ll chkmin(T &a,T b){return a>b?a=b,1:0;}
template<class T>ll chkmax(T &a,T b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T>T mmin(T a,T b){return a<b?a:b;}
template<class T>T mmax(T a,T b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
#define min mmin
#define max mmax
#define abs aabs
ll read(){
	ll s=0,base=1;
	char c;
	while(!isdigit(c=getchar()))if(c=='-')base=-base;
	while(isdigit(c)){s=s*10+(c^48);c=getchar();}
	return s*base;
}
const ll p=1000000009;
ll fpm(ll a,ll b){
	ll c=1;
	while(b){
		if(b&1)c=c*a%p;
		a=a*a%p;
		b>>=1;
	}
	return c;
}
const ll sq5=616991993;
const ll inv2=(p+1)>>2;
const ll invsq5=723398404;
const ll A=308495997;
const ll B=691504013;
ll a[302424];
ll aqz[302424],ax[302424],bqz[302424],bx[302424];
struct SMT{
	SMT *l,*r;
	ll adda,addb,sum,ls,rs;
	void push_up(){
		sum=(l->sum+r->sum)%p;
	}
	SMT(ll lx,ll rx){
		ls=lx;rs=rx;
		adda=addb=0;
		if(lx==rx){
			sum=a[lx];
			l=r=0;
		}
		else{
			ll mid=(ls+rs)>>1;
			l=new SMT(ls,mid);
			r=new SMT(mid+1,rs);
			push_up();
		}
	}
	void put_tag(ll u,ll v){
		adda=(adda+u)%p;
		addb=(addb+v)%p;
		sum=(sum+u*aqz[rs-ls+1]+v*bqz[rs-ls+1])%p;
	}
	void push_down(){
		l->put_tag(adda,addb);
		r->put_tag(adda*ax[l->rs-l->ls+1]%p,addb*bx[l->rs-l->ls+1]%p);
		adda=addb=0;
	}
	void Add(ll lx,ll rx,ll &u,ll &v){
		if(lx<=ls&&rs<=rx){
			put_tag(u,v);
			u=u*ax[rs-ls+1]%p;
			v=v*bx[rs-ls+1]%p;
		}
		else{
			push_down();
			if(lx<=l->rs)l->Add(lx,rx,u,v);
			if(r->ls<=rx)r->Add(lx,rx,u,v);
			push_up();
		}
	}
	ll Sum(ll lx,ll rx){
		if(lx<=ls&&rs<=rx)return sum;
		push_down();
		ll ans=0;
		if(lx<=l->rs)ans=ans+l->Sum(lx,rx);
		if(r->ls<=rx)ans=ans+r->Sum(lx,rx);
		return ans%p;
	}
};
SMT *rt;
int main(){
#ifdef cnyali_lk
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
#endif
	ll n,m,l,r,u,v;
	n=read();m=read();
	ax[0]=bx[0]=1;
	for(ll i=1;i<=n;++i){
		a[i]=read();
		ax[i]=ax[i-1]*A%p;
		aqz[i]=(aqz[i-1]+ax[i])%p;
		bx[i]=bx[i-1]*B%p;
		bqz[i]=(bqz[i-1]+bx[i])%p;
	}
	rt=new SMT(1,n);
	for(ll i=1;i<=m;++i){
		if(read()==1){
			l=read();r=read();
			v=p-(u=invsq5);
			rt->Add(l,r,u,v);
		}
		else{
			l=read();r=read();
			printf("%lld\n",rt->Sum(l,r));
		}
	}
	return 0;
}