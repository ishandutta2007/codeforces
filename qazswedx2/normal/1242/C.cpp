#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
struct pt
{
	int x,y;
	pt(int x=0,int y=0):x(x),y(y){}
};
int n,a[105][5005],len[105],vis[105],b[100005],c[100005][15][2],bt,f[100005],g[100005][15][2];
int nxt[105];
ll sum,tsum[105];
map<int,pt> mp;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&len[i]);
		for(int j=1;j<=len[i];j++)
		{
			scanf("%d",&a[i][j]);
			mp[a[i][j]]=pt(i,j);
			sum+=a[i][j];
			tsum[i]+=a[i][j];
		}
	}
	if(sum%n!=0)
	{
		printf("No\n");
		return 0;
	}
	sum/=n;
	for(int i=1;i<=n;i++)
	{
		tsum[i]-=sum;
		if(tsum[i]>1e9||tsum[i]<-1e9)
		{
			printf("No\n");
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=len[i];j++)
		{
			for(int k=1;k<=n;k++)	
				vis[k]=0;
			int nx=i,ny=j;
			vis[i]=j;
			while(1)
			{
				int val=a[nx][ny]-tsum[nx];
				if(!mp.count(val)) break;
				pt tnw=mp[val];
				if(tnw.x==i&&tnw.y==j)
				{
					nxt[i]=nx;
					++bt;
					//printf("bt=%d\n");
					for(int k=1;k<=n;k++)
						if(vis[k])
						{
							b[bt]|=(1<<(k-1));
							c[bt][k][0]=vis[k];
							c[bt][k][1]=nxt[k];
							//printf("k=%d,vis=%d,nxt=%d\n",k,vis[k],nxt[k]);
						}
					break;
				}
				if(vis[tnw.x]) break;
				vis[tnw.x]=tnw.y;
				nxt[tnw.x]=nx;
				nx=tnw.x,ny=tnw.y;
			}
		}
	}
	for(int i=1;i<=bt;i++)
	{
		f[b[i]]=1;
		for(int j=1;j<=n;j++)
		{
			g[b[i]][j][0]=c[i][j][0];
			g[b[i]][j][1]=c[i][j][1];
		}
	}
	f[0]=1;
	for(int i=1;i<(1<<n);i++)
	{
		if(f[i]) continue;
		for(int j=i;j;j=(j-1)&i)
			if(f[j]&&f[i-j])
			{
				f[i]=1;
				for(int k=1;k<=n;k++)
				{
					g[i][k][0]=g[j][k][0]+g[i-j][k][0];
					g[i][k][1]=g[j][k][1]+g[i-j][k][1];
				}
				break;
			}
	}
	if(f[(1<<n)-1])
	{
		printf("Yes\n");
		for(int i=1;i<=n;i++)
		{
			printf("%d %d\n",a[i][g[(1<<n)-1][i][0]],g[(1<<n)-1][i][1]);
		}
	}
	else printf("No\n");
	return 0;
}