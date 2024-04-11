#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,a[1000005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		int nw=-1,fl=1,mn=n+1,ft=0;
		for(int i=1;i<=n;i++)
		{
			if(nw==mn-1)
			{
				nw=-1;
				mn=ft;
			}
			if(nw!=-1&&nw!=a[i]-1)
			{
				fl=0;
				break;
			}
			if(nw==-1) ft=a[i];
			nw=a[i];
		}
		if(fl) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}