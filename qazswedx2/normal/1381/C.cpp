#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,X,Y,a[100005],b[100005],vis[100005],tans[100005],tt,vis2[100005];
int mx,id,vis3[100005];
bool cmp(const int x,const int y)
{
	return (a[x]==id)<(a[y]==id);
}
bool cmp2(const int x,const int y)
{
	return a[x]<a[y];
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&X,&Y);
		Y-=X;
		for(int i=1;i<=n+1;i++)
			vis[i]=vis2[i]=vis3[i]=b[i]=0;
		tt=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),vis[a[i]]=1;
		int nw=1;
		while(vis[nw]) nw++; 
		for(int i=1;i<=n+1;i++)
			vis[i]=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[a[i]]+1<=(n-X)/2)
			{
				vis[a[i]]++;
				tans[tt++]=i;
			}
		}
		if(tt<n-X)
		{
			tt=0;
			for(int i=1;i<=n+1;i++)
				vis[i]=0;
			for(int i=1;i<=n;i++)
			{
				if(vis[a[i]]+1<=n-X-(Y+1)/2)
				{
					vis[a[i]]++;
					tans[tt++]=i;
				}
			}
			if(tt<n-X)
			{
				printf("NO\n");
				continue;
			}
			tt=min(tt,n-X);
			mx=0,id=0;
		//	printf("ttans=");
			for(int i=0;i<tt;i++)
			{
				vis2[tans[i]]++;
				vis3[a[tans[i]]]++;
		//		printf("%d ",tans[i]);
			}
			for(int i=1;i<=n+1;i++)
				if(mx<vis3[i]) mx=vis3[i],id=i;
		//	printf("\n");
		//	printf("mx=%d,id=%d\n",mx,id);
			for(int i=1;i<=n;i++)
				if(!vis2[i])
					b[i]=a[i];
			sort(tans,tans+tt,cmp);
			for(int i=0;i<tt;i++)
			{
		//	printf("i=%d,tans=%d,qwq=%d\n",i,tans[i],tans[(i+mx)%tt]);
				if(i<(Y+1)/2)
				{
					b[tans[i]]=a[tans[(i+mx)%tt]];
					if(i!=Y/2) b[tans[(i+mx)%tt]]=a[tans[i]];
				}
			}
			for(int i=1;i<=n;i++)
				if(!b[i]) b[i]=nw;
			printf("YES\n");
			for(int i=1;i<=n;i++)
				printf("%d ",b[i]);
			printf("\n");
			continue;
		}
		tt=min(tt,n-X);
	//	printf("tans=");
		for(int i=0;i<tt;i++)
		{
			vis2[tans[i]]=1;
	//		printf("%d ",tans[i]);
		}
	//	printf("\n");
		for(int i=1;i<=n;i++)
			if(!vis2[i])
				b[i]=a[i];
		sort(tans,tans+tt,cmp2);
		for(int i=0;i<tt;i++)
		{
			if(i<Y) b[tans[i]]=a[tans[(i+(n-X)/2)%tt]];
			else b[tans[i]]=nw;
		}
		printf("YES\n");
		for(int i=1;i<=n;i++)
			printf("%d ",b[i]);
		printf("\n");
	}
	return 0;
}