#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,tans[100005],id;
bool check(int x)
{
	printf("? %d %d\n",x,1);
	for(int i=1;i<=x;i++)
		printf("%d ",i);
	printf("\n%d\n",id);
	fflush(stdout);
	int q;
	scanf("%d",&q);
	return q!=0;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			tans[i]=0;
		id=-1;
		for(int i=2;i<=n;i++)
		{
			printf("? %d %d\n",i-1,1);
			for(int j=1;j<i;j++)
				printf("%d ",j);
			printf("\n%d\n",i);
			fflush(stdout);
			int q=0;
			scanf("%d",&q);
			if(q)
			{
				id=i;
				break;
			}
		}
		tans[id]=1;
		for(int i=id+1;i<=n;i++)
		{
			printf("? 1 1\n%d\n%d\n",id,i);
			fflush(stdout);
			int q=0;
			scanf("%d",&q);
			if(q) tans[i]=1;
		}
		int l=1,r=id,mid;
		while(l<r)
		{
			mid=(l+r)/2;
			if(check(mid)) r=mid;
			else l=mid+1;
		}
		tans[l]=1;
		int ct=0;
		for(int i=1;i<=n;i++)
			if(!tans[i])
				ct++;
		printf("! %d ",ct);
		for(int i=1;i<=n;i++)
			if(!tans[i])
				printf("%d ",i);
		printf("\n");
		fflush(stdout);
	}
	return 0;
}