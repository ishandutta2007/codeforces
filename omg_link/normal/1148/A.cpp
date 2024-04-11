#include <stdio.h>
#include <algorithm>
#define MN 100000
typedef long long LL;
LL a,b,c,d;
int main(){
	scanf("%lld%lld%lld",&a,&b,&c);
	c*=2;
	d=std::min(a,b);
	c+=d*2,a-=d,b-=d;
	if(a>0||b>0) c++;
	printf("%lld\n",c);
}