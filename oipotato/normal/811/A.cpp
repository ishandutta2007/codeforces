#include<cstdio>
using namespace std;
int a,b;
int main()
{
	scanf("%d%d",&a,&b);
	for(int i=1;;i++)
	{
		if(a<i)
		{
			printf("Vladik");
			return 0;
		}
		a-=i;
		i++;
		if(b<i)
		{
			printf("Valera");
			return 0;
		}
		b-=i;
	}
	return 0;
}