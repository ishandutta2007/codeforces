#include<cstdio>
int a,b,c,m,p;
long long ans;
int main(){
	scanf("%d%d%d%d",&a,&b,&c,&m);
	for(int i=0;i<=m;++i){
		int x=ans;
		ans+=1ll*(i+1)*(i+2)/2;
		p=(a+i-b-c)/2+1; p=p<i+1?p:i+1;
		if(a+i>=b+c) ans-=1ll*p*(p+1)/2;
		p=(b+i-a-c)/2+1; p=p<i+1?p:i+1;
		if(b+i>=a+c) ans-=1ll*p*(p+1)/2;
		p=(c+i-b-a)/2+1; p=p<i+1?p:i+1;
		if(c+i>=b+a) ans-=1ll*p*(p+1)/2;
	}
	printf("%lld",ans);
	return 0;
}