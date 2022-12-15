#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int ans[200001],an,mid,l,r,t,n,no,Ans[200001];

struct node
{
	int t,x,po;
}a[200001];

bool cmp(node a,node b) {return a.t<b.t;}

int main()
{
	scanf("%d%d",&n,&t);
	for (int i=1; i<=n; i++) scanf("%d%d",&a[i].x,&a[i].t),a[i].po=i;
	sort(a+1,a+1+n,cmp);
	l=1; r=n; an=0;
	while (l<=r)
	{
		mid=(l+r)>>1; ans[0]=0; no=0;
		for (int i=1; i<=n; i++) 
			if (a[i].x>=mid&&no+a[i].t<=t) no+=a[i].t,ans[++ans[0]]=a[i].po;
		if (ans[0]>=mid) 
		{
			l=mid+1,an=mid;
			Ans[0]=mid;
			for (int i=1; i<=mid; i++) Ans[i]=ans[i];
		} else r=mid-1;
	}
	printf("%d\n%d\n",an,Ans[0]);
	for (int i=1; i<=Ans[0]; i++) printf("%d ",Ans[i]);
	return 0;
}