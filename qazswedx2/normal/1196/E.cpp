#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,a,b,fl;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		fl=1;
		if(a>b)
		{
			fl=0;
			swap(a,b);
		}
		if(b>3*a+1)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		if(a==b)
		{
			for(int i=1;i<=a+b;i++)
				printf("%d %d\n",1,i);
			continue;
		}
		for(int i=1;i<=2*a+1;i++)
			printf("%d %d\n",2+fl,i);
		for(int i=2;i<=2*min(a,b-a-1);i+=2)
			printf("%d %d\n",1+fl,i);
		for(int i=2;i<=2*(b-2*a-1);i+=2)
			printf("%d %d\n",3+fl,i);
	}
	return 0;
}