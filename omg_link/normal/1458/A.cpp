#include <stdio.h>
#include <algorithm>
#define MN 200000
typedef long long LL;

int n,m;
LL a[MN+5],b[MN+5],g,min=0x7fffffffffffffff;

LL gcd(LL x,LL y){
	return y?gcd(y,x%y):x;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		min = std::min(min,a[i]);
	}
	g = std::abs(a[2]-a[1]);
	for(int i=2;i<=n-1;i++)
		g = gcd(g,std::abs(a[i+1]-a[i]));
	for(int i=1;i<=m;i++){
		scanf("%lld",&b[i]);
		if(n==1)
			printf("%lld ",b[i]+min);
		else
			printf("%lld ",gcd(g,b[i]+min));
	}
}