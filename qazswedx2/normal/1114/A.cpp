#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int a,b,c,x,y,z;
int main()
{
	scanf("%d%d%d%d%d%d",&x,&y,&z,&a,&b,&c);
	if(x>a)
	{
		printf("NO");
		return 0;
	}
	else a-=x;
	if(y>a+b)
	{
		printf("NO");
		return 0;
	}
	else
	{
		if(y<=a) a-=y;
		else
		{
			b=b-(y-a);
			a=0;
		}
	}
	if(z>a+b+c) printf("NO");
	else printf("YES");
	return 0;
}