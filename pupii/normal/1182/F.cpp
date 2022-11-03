// luogu-judger-enable-o2
#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
il ll f(ll a,ll b,ll c,ll n){
	if(n<0)return 0;
	if(a==0)return (n+1)*(b/c);
	if(a>=c||b>=c)return f(a%c,b%c,c,n)+n*(n+1)/2*(a/c)+(n+1)*(b/c);
	ll m=(a*n+b)/c;
	return m<=0?0:n*m-f(c,c-b-1,a,m-1);
}
il ll F(ll a,ll b,ll c,ll n){
	ll e=0;
	if(b<0){b=-b;ll d=(c+b-1)/c;e-=b*d;b=c*d-b;}
	return e+f(a,b,c,n);
}
il ll exgcd(ll a,ll b,ll&x,ll&y){
	if(!b){x=1,y=0;return a;}
	ll r=exgcd(b,a%b,y,x);
	y-=x*(a/b);return r;
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int qaq=gi();
	while(qaq--){
		int L=gi(),R=gi(),p=gi(),q=gi();
		int l=0,r=q,mid;
		while(l<r){
			mid=(l+r)>>1;
			int _l=q-mid,_r=q+mid;
			if(F(2*p,-_l,2*q,R)-F(2*p,-_r-1,2*q,R)-F(2*p,-_l,2*q,L-1)+F(2*p,-_r-1,2*q,L-1))r=mid;
			else l=mid+1;
		}
		ll ans=2e9;
		ll P=2*p,Q=2*q,x,y,g=exgcd(P,Q,x,y);
		P/=g,Q/=g;
		if((q-l)%g==0){
			ll _x=x*((q-l)/g);
			_x=L/Q*Q+_x%Q;
			while(_x>R)_x-=Q;while(_x<L)_x+=Q;
			ans=std::min(ans,_x);
		}
		if((q+l)%g==0){
			ll _x=x*((q+l)/g);
			_x=L/Q*Q+_x%Q;
			while(_x>R)_x-=Q;while(_x<L)_x+=Q;
			ans=std::min(ans,_x);
		}
		printf("%lld\n",ans);
	}
	return 0;
}