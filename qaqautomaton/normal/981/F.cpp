/*
Author: CNYALI_LK
LANG: C++
PROG: queue.cpp
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
template<class T>T mmax(T a,T b){return a>b?a:b;} template<class T>T aabs(T a){return a<0?-a:a;}
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
ll a[233333],b[666666];
ll n;
ll L;
ll more(ll x){
	ll l=1,r=n+n+n,mid;
	while(l<=r){
		mid=(l+r)>>1;	
		if(b[mid]<x)l=mid+1;
		else r=mid-1;
	}
	return r+1; }

ll Less(ll x){
	ll l=1,r=n+n+n,mid;
	while(l<=r){
		mid=(l+r)>>1;	
		if(b[mid]<=x)l=mid+1;
		else r=mid-1;
	}
	return l-1;
}
ll chk(ll w){
	ll low=0,high=n+n+n;
	for(ll i=1;i<=n;++i){
		while(b[low+i]<a[i]-w)++low;
		while(b[high+i]>a[i]+w)--high;
	}
	return low<=high;

}
ll fpm(ll a,ll b){
	ll p=20000909,c=1;
	while(b){
		if(b&1)c=(ll)a*c%p;
		a=(ll)a*a%p;
		b>>=1;
	}
	return c;
}
int main(){
//	freopen("queue.in","r",stdin);
//	freopen("queue.out","w",stdout);
	n=read();L=read();
	for(ll i=1;i<=n;++i)a[i]=read()+L;
	sort(a+1,a+n+1);
	b[0]=-1;
	b[n*3+1]=L*4;
	for(ll i=1;i<=n;++i){b[i]=read();b[i+n]=b[i]+L;b[i+n+n]=b[i]+L+L;}
	sort(b+1,b+n+n+n+1);

	ll l,r,mid;
	r=L;
	l=0;
	while(l<=r){
		mid=(l+r)>>1;
		if(chk(mid))r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",r+1);

	return 0;
}