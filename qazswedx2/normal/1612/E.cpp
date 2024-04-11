#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,val=2e5,a[200005][2],c[200005],tans[200005],tmp[200005];
bool cmp(const int x,const int y)
{
	return c[x]>c[y];
}
int main()
{
	scanf("%d",&n);
	int m=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i][0],&a[i][1]);
		m=max(m,a[i][1]);
	}
	ll ans1=-1,ans2=0,id=-1;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
			if(a[j][1]>=i)
				c[a[j][0]]++;
		for(int j=1;j<=val;j++)
			tmp[j]=j;
		nth_element(tmp+1,tmp+i,tmp+val+1,cmp);
		ll sum=0;
		for(int j=1;j<=i;j++)
			sum+=c[tmp[j]];
	//	printf("sum=%lld,i=%d\n",sum,i);
		if(sum*ans2>ans1*i)
		{
			id=i;
			ans1=sum,ans2=i;
			for(int j=1;j<=i;j++)
				tans[j]=tmp[j];
		}
	}
	sort(tmp+1,tmp+val+1,cmp);
/*	for(int i=1;i<=20;i++)
		printf("%d ",c[i]);
	printf("\n");*/
//	reverse(tmp+1,tmp+val+1);
	ll sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=c[tmp[i]];
	//	printf("sum=%lld,i=%d\n",sum,i);
		if(i>m&&sum*ans2>ans1*i)
		{
			id=i;
			ans1=sum,ans2=i;
		}
	}
	printf("%lld\n",id);
	for(int i=1;i<=id;i++)
		if(id<=m) printf("%d ",tans[i]);
		else printf("%d ",tmp[i]);
	printf("\n");
	return 0;
}