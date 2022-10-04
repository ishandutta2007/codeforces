#include<cstdio>
long long k,d,t,lp,t1,t2;
double ans;
int main(){
	scanf("%lld%lld%lld",&k,&d,&t); t<<=1;
	lp=(k-1)/d*d+d; t1=k<<1, t2=lp-k;
	ans=t/(t1+t2)*lp; t%=t1+t2;
	if(t<=t1) ans+=(double)t/t1*k;
	else ans+=k+(double)(t-t1)/t2*(lp-k);
	printf("%lf",ans);
	return 0;
}