#include<cstdio>
#include<cmath>
using namespace std;
int a1,a2,a3,l,r,len;
int main()
{
	scanf("%d%d",&l,&r);
	a1=(r-l)/2+(l%2==0||r%2==0);
	a2=(r-l)/3+(l%3==0||r%3==0);
	a3=(r-l)/5+(l%5==0||r%5==0);
	if(a1==0&&a2==0&&a3==0)
	{
		len=(int)sqrt(l);
		for(int i=2;i<=len;i++)
		if(l%i==0)
		{
			printf("%d",i);
			return 0;
		}
		printf("%d",l);
		return 0;
	}
	if(a1>=a2&&a1>=a3)printf("2");
	else if(a2>=a1&&a2>=a3)printf("3");
	else printf("5");
	return 0;
}