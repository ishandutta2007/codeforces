#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
int f[1000005];
int find(int x)
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void link(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y) return;
	f[x]=y;
}
int t,n,m,a[1000005],b[1000005],c[1000005],sum[1000005],tans[1000005],pn=2e5;
vector<int> val[1000005];
inline int lowbit(int x)
{
	return x&-x;
}
void modify(int x,int v)
{
	for(int i=x;i<=pn;i+=lowbit(i))
		sum[i]=max(sum[i],v);
}
void modify2(int x)
{
	for(int i=x;i<=pn;i+=lowbit(i))
		sum[i]=0;//1e9;
}
int query(int x)
{
	int ans=0;//1e9;
	for(int i=x;i;i-=lowbit(i))
		ans=max(ans,sum[i]);
	return ans;
}
int main()
{
	//for(int i=0;i<=pn;i++)
	//	sum[i]=1e9;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<=n+3;i++)
			f[i]=i;
		sort(a+1,a+n+1);
	/*	for(int i=1;i<=n;i++)
			printf("%d ",a[i]);
		printf("\n");*/
		for(int i=1;i<=m;i++)
		{
			val[i].clear();
			int k;
			ll sum=0;
			scanf("%d",&k);
			for(int j=0;j<k;j++)
			{
				int x;
				scanf("%d",&x);
				val[i].push_back(x);
				sum+=x;
			}
			b[i]=(sum+k-1)/k;
		}
		int nw=0,ct=0;
		for(int i=1;i<=m;i++)
		{
			int u=lower_bound(a+1,a+n+1,b[i])-a;
		//	printf("i=%d,u=%d,b=%d,a=%d,ct=%d\n",i,u,b[i],a[u],ct); 
			u=find(u);
			if(u<=n)
				link(u,u+1);
			else ct++;
			c[i]=u;
		}
		int inf=2e9;
		a[n+1]=inf;
		for(int i=1;i<=n;i++)
			if(f[i]==i) nw=a[i];
		for(int i=m;i>0;i--)
		{
			int q=1e9;
			tans[i]=max(a[c[i]],nw);
			if(c[i]<=n)
			{
				tans[i]=max(tans[i],query(a[c[i]]));
				//if(q<=m) tans[i]=tans[q];
			}
			modify(b[i],tans[i]);
		}
		for(int i=1;i<=m;i++)
		{
			ll sum=0;
			int sz=val[i].size();
			for(int j=0;j<sz;j++)
				sum+=val[i][j];
			if(ct>=2)
			{
				for(int j=0;j<sz;j++)
					printf("0");
				continue; 
			}
			else if(ct==1)
			{
				if(tans[i]<inf)
				{
					for(int j=0;j<sz;j++)
						printf("0");
				}
				else
				{
					for(int j=0;j<sz;j++)
						if(1ll*nw*(sz-1)>=sum-val[i][j])
							printf("1");
						else printf("0");
				}
				continue;
			}
			for(int j=0;j<sz;j++)
				if(1ll*tans[i]*(sz-1)>=sum-val[i][j])
					printf("1");
				else printf("0");
		}
		printf("\n");
		for(int i=m;i>0;i--)
			modify2(b[i]);
	}
	return 0; 
}