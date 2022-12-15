#include<cstdio>
#include<cstring>

int m,b;
long long ans,x,y,sum;

int main()
{
	scanf("%d%d",&m,&b); ans=0;
	for (int i=0; i<=b; i++)
	{
		x=i; y=m*(b-i);
		sum=(1+x)*x/2*(y+1)+(1+y)*y/2*(x+1);
		if (sum>ans) ans=sum;
	}
	printf("%I64d",ans);
	return 0;
}