#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct pt
{
	int val,id;
	bool operator<(const pt x) const
	{
		return val<x.val;
	}
}p[1000005];
int n,a[15],b[1000005],vis[1000005],t,ct;
void ins(int x)
{
	x=p[x].id;
	if(!vis[x]) ct++;
	vis[x]++;
}
void del(int x)
{
	x=p[x].id;
	vis[x]--;
	if(!vis[x]) ct--;
}
int main()
{
	for(int i=1;i<=6;i++)
		scanf("%d",&a[i]);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		for(int j=1;j<=6;j++)
		{
			p[++t].id=i;
			p[t].val=b[i]-a[j];
		}
	}
	sort(p+1,p+t+1);
	int ans=1e9;
	for(int l=1,r=0;l<=t;l++)
	{
		while(ct<n&&r<t)
		{
			ins(++r);
		}
	/*	printf("l=%d,r=%d,ct=%d\n",l,r,ct);
		for(int i=1;i<=n;i++)
			printf("%d ",vis[i]);
		printf("\n");*/
		if(ct<n) break;
		ans=min(ans,p[r].val-p[l].val);
		del(l);
	}
	printf("%d\n",ans);
	return 0;
}