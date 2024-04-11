#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;
int n,k,a[100010];
void work(int l,int r,int k)
{
	if(!k)
	{
		sort(a+l,a+r);
		return;
	}
	if(l==r-1)
	{
		puts("-1");
		exit(0);
	}
	int mid=(l+r)>>1;
	k-=2;
	if(k%4==0)
	{
		work(l,mid,k/2);
		work(mid,r,k/2);
	}
	else
	{
		work(l,mid,k/2-1);
		work(mid,r,k/2+1);
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	if(k%2==0)
	{
		puts("-1");
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		a[i]=n-i-1;
	}
	work(0,n,k-1);
	for(int i=0;i<n;i++)
	{
		printf("%d%c",a[i]+1,i==n-1?'\n':' ');
	}
	return 0;
}