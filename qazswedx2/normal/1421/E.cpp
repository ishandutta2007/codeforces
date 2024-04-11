#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,a[500005],c[500005];
ll sum,ans=-1e18;
bool cmp(const int x,const int y)
{
	return a[x]<a[y];
}
int main()
{
	scanf("%d",&n);
	int ct0=0,ct1=0,fl0=0,fl1=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		c[i]=i;
		sum+=a[i];
		if(i%2) ct0++;
		else ct1++;
	}
	if(n==1)
	{
		printf("%d\n",a[1]);
		return 0;
	}
	if(n%3==1) ans=max(ans,sum);
	sort(c+1,c+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(c[i]%2) ct0--,fl0=1;
		else ct1--,fl1=1;
		if(ct0==0&&fl1==0||ct1==0&&fl0==0)
		{
			sum-=2*a[c[i+1]];
		//	printf("i=%d\n",i);
		}
		else sum-=2*a[c[i]];
		//printf("i=%d,sum=%d\n",i,sum);
		if((i+n)%3==1) ans=max(ans,sum);
		if(ct0==0&&fl1==0||ct1==0&&fl0==0)
			sum+=2*a[c[i+1]],sum-=2*a[c[i]];
	}
	printf("%lld\n",ans);
	return 0;
}