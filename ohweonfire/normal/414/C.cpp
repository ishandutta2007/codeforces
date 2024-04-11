#include <cstdio>
using namespace std;
const int maxn=1050005,maxlog=25;
typedef long long LL;
int a[maxn],n,m,q,tmp[maxn];
LL count[maxlog],nn,cur[maxlog];
void merge(int b1,int e1,int b2,int e2,int depth)
{
	int i=b1,j=b2,k=i;
	LL &ans=count[depth];
	while(i<e1&&j<e2)
	{
		if(a[i]<a[j])
			tmp[k++]=a[i++];
		else
		{
			tmp[k++]=a[j++];
			ans+=i-b1;
		}
	}
	while(i<e1)tmp[k++]=a[i++];
	while(j<e2)
	{
		tmp[k++]=a[j++];
		ans+=i-b1;
	}
}
void merge2(int b1,int e1,int b2,int e2,int depth)
{
	int i=b1,j=b2,k=i;
	LL &ans=cur[depth];
	while(i<e1&&j<e2)
	{
		if(a[i]<=a[j])
			tmp[k++]=a[i++];
		else
		{
			tmp[k++]=a[j++];
			ans+=e1-i;
		}
	}
	while(i<e1)tmp[k++]=a[i++];
	while(j<e2)
	{
		tmp[k++]=a[j++];
		ans+=e1-i;
	}
	for(int i=b1;i<e2;i++)
		a[i]=tmp[i];
}
void mergesort(int l,int r,int depth)
{
	if(depth<=0)return;
	int mid=l+r>>1;
	mergesort(l,mid,depth-1);
	mergesort(mid,r,depth-1);
	merge(l,mid,mid,r,depth);
	merge2(l,mid,mid,r,depth);
}
int main()
{
	scanf("%d",&n);
	nn=1ll<<n;
	for(int i=0;i<nn;i++)
		scanf("%d",a+i);
	mergesort(0,nn,n);
	for(int i=0;i<=n;i++)
		count[i]+=cur[i];
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d",&q);
		LL ans=0;
		for(int i=0;i<=n;i++)
		{
			if(i<=q)
				cur[i]=count[i]-cur[i];
			ans+=cur[i];
		}
		printf("%I64d\n",ans);
	}
	return 0;
}