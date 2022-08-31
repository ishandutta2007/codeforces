#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a,b,c,d,e,f;
int main()
{
	scanf("%d%d%d%d%d%d",&a,&d,&c,&b,&e,&f);
	c=min(c,d);
	if(f>e)
	{
		if(b<c) c=b,a=0;
		else a=min(a,b-c);
	}
	else
	{
		if(b<a) a=b,c=0;
		else c=min(c,b-a);
	}
	printf("%I64d",1ll*a*e+1ll*c*f);
	return 0;
}