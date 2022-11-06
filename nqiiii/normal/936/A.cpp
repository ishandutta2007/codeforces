#include<cstdio>
typedef long long ll;
ll k,d,t,ans;
int main(){
	scanf("%lld%lld%lld",&k,&d,&t); t*=2;
	ll tm=k/d*d; if(tm<k) tm+=d;
	ll v=k*2+(tm-k); ans+=t/v*tm; t%=v;
	if(t<=k*2) printf("%.10lf",ans+t/2.0);
	else printf("%.10lf",0.0+ans+k+(t-k*2));
}