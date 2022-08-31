#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[1000005],b[1000005],vis[1000005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		a[u]=v,a[v]=u;
		if(u>v) b[u]=b[v]=1;
	}
	int l=1,r=2*n,ans=0;
	while(l<=r)
	{
		vis[l]=vis[a[l]]=1;
		int ct0=0,ct1=0,ll=l,rr=a[l];
		if(b[l]) ct1++;
		else ct0++;
		while(r>rr||l<ll)
		{
			while(r>rr)
			{
				if(!vis[r])
				{
					vis[r]=vis[a[r]]=1;
					if(b[r]) ct0++;
					else ct1++; 
					if(a[r]<ll||a[r]>rr)
					{
						printf("-1\n");
						return 0;
					}
					ll=a[r];
				}
				r--;
			}
			while(l<ll)
			{
				if(!vis[l])
				{
					vis[l]=vis[a[l]]=1;
					if(b[l]) ct1++;
					else ct0++;
					if(a[l]>rr||a[l]<ll)
					{
						printf("-1\n");
						return 0;
					}
					rr=a[l];
				}
				l++;
			}
		}
		ans+=min(ct0,ct1);
		l=ll+1,r=rr-1;
	}
	printf("%d\n",ans);
	return 0;
}