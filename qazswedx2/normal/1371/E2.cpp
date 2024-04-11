#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,p,a[100005],cnt[100005];
int main()
{
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int val=max(a[1]-1,a[n]-n),l=1,r=a[n];
	for(int i=n;i>0;i--)
	{
		a[i]-=val;
		if(a[i]<=0) a[i]=1; 
	}
	for(int i=1;i<=n;i++)
		cnt[a[i]]++;
	for(int i=1;i<=n;i++)
		cnt[i]+=cnt[i-1];
	//for(int i=1;i<=n;i++)
	//	printf("i=%d,a=%d\n",i,a[i]);
	for(int i=1;i<=n;i++)
	{
		int nw=lower_bound(cnt+1,cnt+n+1,i)-cnt;
		//printf("i=%d,nw=%d\n",i,nw);
		l=max(l,nw-i+1);
	}
	for(int i=1;i<=n;i++)
	{
		int nw=lower_bound(cnt+1,cnt+n+1,i+p-1)-cnt;
		//printf("i=%d,nw=%d\n",i,nw);
		if(nw<=n) r=min(r,nw-i);
	}
	if(l>r)
	{
		printf("0\n");
		return 0;
	}
	printf("%d\n",r-l+1);
	for(int i=l;i<=r;i++)
		printf("%d ",i+val);
	return 0;
}