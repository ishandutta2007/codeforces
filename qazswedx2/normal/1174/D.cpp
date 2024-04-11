#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,x,a[1000005],tans[1000005],len=0;
int main()
{
	scanf("%d%d",&n,&x);
	a[x]=1;
	for(int i=1;i<(1<<n);i++)
	{
		if(!a[i])
		{
			a[i]=a[i^x]=1;
			tans[++len]=i;
		}
	}
	for(int i=len;i>1;i--)
		tans[i]^=tans[i-1];
	printf("%d\n",len);
	for(int i=1;i<=len;i++)
		printf("%d ",tans[i]);
	return 0;
}