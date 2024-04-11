#include<cstdio>
long long n,lst,now,lf,lg,f,g;
long long Max(long long p1,long long p2){return p1>p2?p1:p2;}
int main(){
	scanf("%lld%lld",&n,&lst);
	for(long long i=2;i<=n;++i){
		scanf("%lld",&now);
		if(lst<now) f=Max(lg,lf+now-lst), g=Max(lf,lg);
		else if(lst>now) g=Max(lf,lg+lst-now), f=Max(lf,lg);
		else f=g=Max(lf,lg);
		lst=now; lf=f, lg=g;
	}
	printf("%lld",Max(lf,lg));
	return 0;
}