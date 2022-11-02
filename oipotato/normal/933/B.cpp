#include<cstdio>
#include<algorithm>
#include<set>
#include<queue>
#include<vector>
using namespace std;
long long p,a[100010];
int k,tot;
int main()
{
	scanf("%lld%d",&p,&k);
	for(;;)
	{
		if(!p)
		{
			break;
		}
		if(tot%2==0)
		{
			a[++tot]=p%k;
			p/=k;
		}
		else
		{
			a[++tot]=k-p%k;
			if(p/k*k==p)
			{
				a[tot]=0;
			}
			p=(p-1)/k+1;
		}
	}
	printf("%d\n",tot);
	for(int i=1;i<tot;i++)
	{
		printf("%lld ",a[i]);
	}
	printf("%lld\n",a[tot]);
	return 0;
}