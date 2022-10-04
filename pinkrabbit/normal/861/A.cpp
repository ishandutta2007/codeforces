#include<cstdio>
#include<cmath>
using namespace std;
int n,n2,k,t,f,t2,f2;
int main(){
	scanf("%d%d",&n2,&k); n=n2;
	while(!(n2%2)) n2/=2, ++t;
	while(!(n2%5)) n2/=5, ++f;
	t2=0<k-t?k-t:0;
	f2=0<k-f?k-f:0;
	printf("%I64d",(long long)n*(int)(pow(2,t2)+0.5)*(int)(pow(5,f2)+0.5));
	return 0;
}