#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,x=-1,y=-1;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		printf("? %d %d %d %d\n",i,1,i,n);
		fflush(stdout);
		int a;
		scanf("%d",&a);
		if(a%2)
		{
			if(x==-1) x=i;
			else y=i;
		}
	}
	if(x!=-1&&y==-1) y=n;
	if(x!=-1)
	{
		int l=1,r=n,mid;
		while(l<r)
		{
			mid=(l+r)/2;
			printf("? %d %d %d %d\n",x,1,x,mid);
			fflush(stdout);
			int a;
			scanf("%d",&a);
			if(a%2) r=mid;
			else l=mid+1;
		}
		int ans=l;
		l=1,r=n;
		while(l<r)
		{
			mid=(l+r)/2;
			printf("? %d %d %d %d\n",y,1,y,mid);
			fflush(stdout);
			int a;
			scanf("%d",&a);
			if(a%2) r=mid;
			else l=mid+1;
		}
		printf("! %d %d %d %d\n",x,ans,y,l);
		fflush(stdout);
		return 0;
	}
	x=-1,y=-1;
	for(int i=1;i<n;i++)
	{
		printf("? %d %d %d %d\n",1,i,n,i);
		fflush(stdout);
		int a;
		scanf("%d",&a);
		if(a%2)
		{
			if(x==-1) x=i;
			else y=i;
		}
	}
	if(x!=-1&&y==-1) y=n;
	if(x!=-1)
	{
		int l=1,r=n,mid;
		while(l<r)
		{
			mid=(l+r)/2;
			printf("? %d %d %d %d\n",1,x,mid,x);
			fflush(stdout);
			int a;
			scanf("%d",&a);
			if(a%2) r=mid;
			else l=mid+1;
		}
		int ans=l;
		l=1,r=n;
		while(l<r)
		{
			mid=(l+r)/2;
			printf("? %d %d %d %d\n",1,y,mid,y);
			fflush(stdout);
			int a;
			scanf("%d",&a);
			if(a%2) r=mid;
			else l=mid+1;
		}
		printf("! %d %d %d %d\n",ans,x,l,y);
	}
	return 0;
}