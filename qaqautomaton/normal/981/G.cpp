/*
Author: CNYALI_LK
LANG: C++
PROG: multiset.cpp
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
const ll p=998244353;
const ll d2=499122177;
set<pii> S[204847];
struct smt{
	smt *l,*r;
	ll atag,mtag,sum,ls,rs;
	smt(ll la,ll ra){
		ls=la;rs=ra;
		atag=sum=0;
		mtag=1;
		if(ls!=rs){
			ll mid=(la+ra)>>1;
			l=new smt(la,mid);
			r=new smt(mid+1,ra);
		}else l=r=0;
	}
	#define push_up sum=(l->sum+r->sum)%p
	void put_mtag(ll mu){
		mtag=mtag*mu%p;
		atag=atag*mu%p;
		sum=sum*mu%p;
	}
	void put_atag(ll ad){
		atag=(atag+ad)%p;
		sum=(sum+ad*(rs-ls+1))%p;
	}
	void push_down(){
		l->put_mtag(mtag);	
		l->put_atag(atag);

		r->put_mtag(mtag);	
		r->put_atag(atag);

		mtag=1;atag=0;
	}
	void add(ll la,ll ra,ll w){
		if(la<=ls&&rs<=ra){put_atag(w);return;}
		push_down();
		if(la<=l->rs)l->add(la,ra,w);
		if(r->ls<=ra)r->add(la,ra,w);
		push_up;
	}
	void multi(ll la,ll ra,ll w){
		if(la<=ls&&rs<=ra){put_mtag(w);return;}
		push_down();
		if(la<=l->rs)l->multi(la,ra,w);
		if(r->ls<=ra)r->multi(la,ra,w);
		push_up;
	}
	ll Sum(ll la,ll ra){
		if(la<=ls&&rs<=ra)return sum;
		push_down();
		ll ans=0;
		if(la<=l->rs)ans=(ans+l->Sum(la,ra))%p;
		if(r->ls<=ra)ans=(ans+r->Sum(la,ra))%p;
		return ans;
	}
};
smt *rt;
void split(ll x,ll w){
	set<pii>::iterator s=S[w].upper_bound(make_pair(x,x));
	if(s==S[w].begin())return;
	--s;
	if(s->y>=x){
		pii a=*s;
		S[w].erase(s);	
		S[w].insert(make_pair(a.x,x-1));
		S[w].insert(make_pair(x,a.y));
	}
}
void Adddd(ll l,ll r,ll w){
	split(l,w);
	split(r+1,w);
	set<pii>::iterator s;
	while((s=S[w].lower_bound(make_pair(l,l)))!=S[w].end()){
		if(s->y<=r){
			rt->multi(s->x,s->y,d2);
			rt->add(s->x,s->y,1);
			S[w].erase(s);
		}else break;
	}
}
int main(){
	ll n,q,l,r,w;
	n=read();q=read();
	rt=new smt(1,n);
	for(ll i=1;i<=n;++i)S[i].insert(make_pair(1,n));
	for(;q;--q){
		if(read()==1){
			l=read();r=read();w=read();
			rt->multi(l,r,2);
			Adddd(l,r,w);
		}	
		else{
			l=read();r=read();
			printf("%lld\n",rt->Sum(l,r));
		}

	}
	return 0;
}