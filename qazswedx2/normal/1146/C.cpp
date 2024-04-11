#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int ls[1005],rs[1005],t,n,st[1000005],st1[1000005],ans;
void build(int x,int l,int r)
{
	ls[x]=l,rs[x]=r;
	if(l==r) return;
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		memset(ls,0,sizeof(ls));
		memset(rs,0,sizeof(rs));
		scanf("%d",&n);
		build(1,1,n);
		for(int i=1;i<=9;i++)
		{
			int l=(1<<i),r=(1<<i+1)-1,cnt1=0,cnt2=0;
			for(int j=l;j<=r;j++)
			{
				if(!ls[j]) continue;
				for(int k=ls[j];k<=rs[j];k++)
				{
					if(j%2) st[++cnt1]=k;
					else st1[++cnt2]=k;
				}
			}
			if(cnt1==0) break;
			printf("%d %d ",cnt1,cnt2);
			for(int i=1;i<=cnt1;i++)
				printf("%d ",st[i]);
			for(int i=1;i<=cnt2;i++)
				printf("%d ",st1[i]);
			printf("\n");
			fflush(stdout);
			int sum;
			scanf("%d",&sum);
			ans=max(ans,sum);
		}
		printf("-1 %d\n",ans);
		fflush(stdout);
	}
	return 0;
}