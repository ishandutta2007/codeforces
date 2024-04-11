#include<cstdio>
using namespace std;
int n,k,x,y,sum;
int main()
{
	scanf("%d%d%d",&n,&k,&x);
	for(int i=1;i<=n-k;i++)
	{
		scanf("%d",&y);
		sum+=y;
	}
	for(int i=n-k+1;i<=n;i++)
	{
		scanf("%d",&y);
		sum+=x;
	}
	printf("%d\n",sum);
	return 0;
}