#include<cstdio>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int num=0;
	rep(i,n)
	{
		if(num+i*5+k>240){printf("%d\n",i-1);return 0;}
		num+=i*5;
	}
	printf("%d\n",n);
	return 0;
}