#include<cstdio>
#include<algorithm>
#define rg register
typedef long long ll;
ll bin[1005];ll lim,n;
ll p[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000ll,100000000000ll};
ll ans=0;
int solve(int w){
	static ll x,l,r;
	x=w*p[lim]+bin[lim];l=std::max(1ll,x-n),r=std::min(n,x-1);
	if(l<=r)return (r-l+1)/2;
	else return 0;
}
int main(){
	scanf("%lld",&n);
	for(rg int i=1;i<=10;i++)bin[i]=bin[i-1]*10+9;
	if(n<=4){printf("%I64d\n",n*(n-1)/2);return 0;}
	for(lim=1;lim<=10;lim++)
		if(n*2<bin[lim]){lim--;break;}
	for(rg int i=0;i<1000;i++)ans+=solve(i);
	printf("%I64d\n",ans);
	return 0;
}