#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
int n;
bool prime(int x)
{
	for(int i=2;i*i<=x;i++)if(x%i==0)return false;
	return true;
}
LL modpow(LL x,int y)
{
	LL res=1;
	while(y)
	{
		if(y&1)res=res*x%n;
		x=x*x%n;
		y>>=1;
	}
	return res;
}
int main()
{
	scanf("%d",&n);
	if(n>=6&&!prime(n))
	{
		puts("NO");
		return 0;
	}
	if(n==1){puts("YES\n1");return 0;}
	else if(n==4){puts("YES\n1\n3\n2\n4");return 0;}
	puts("YES\n1");
	for(int i=2;i<n;i++)printf("%d\n",modpow(i-1,n-2)*i%n);
	printf("%d\n",n);
	return 0;
}