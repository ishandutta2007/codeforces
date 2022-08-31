#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
using namespace std;
int tt,n,m,a[100005],b[100005];
int c[100005],d[100005],ct,dt;
bitset<500005> dp[505];
int vis[100005];
int tmp[100005],tmp2[100005],tp1,tp2;
bool solve(int *f,int *g,int &t,int fl)
{
	int sum=0;
	for(int i=1;i<=n;i++)
		sum+=f[i];
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
		dp[i]=dp[i-1]|(dp[i-1]<<f[i]);
	if(sum%2==1||!dp[n][sum/2]) return 0;
	int nw=sum/2;
	tp1=tp2=0;
	for(int i=n;i>0;i--)
		if(!dp[i-1][nw])
		{
			tmp[++tp1]=f[i];
			nw-=f[i];
		}
		else tmp2[++tp2]=f[i];
//printf("fl=%d,tp1=%d,tp2=%d\n",fl,tp1,tp2);
	t=0;
	if((tp1<tp2)^fl)
	{
		for(int i=1;i<=tp1;i++)
			g[++t]=tmp[i];
		for(int i=1,j=t+1;i<=tp2;i++,j++)
			g[j]=tmp2[i];
	}
	else
	{
		for(int i=1;i<=tp2;i++)
			g[++t]=tmp2[i];
		for(int i=1,j=t+1;i<=tp1;i++,j++)
			g[j]=tmp[i];
	}
	return 1;
}
const int cmp(const int x,const int y)
{
	return x>y;
}
int main()
{
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
			scanf("%d",&b[i]);
		if(n!=m)
		{
			printf("No\n");
			continue;
		}
		if(!solve(a,c,ct,0)||!solve(b,d,dt,1))
		{
			printf("No\n");
			continue;
		}
		sort(c+1,c+ct+1,cmp);
		sort(d+1,d+dt+1);
		sort(c+ct+1,c+n+1,cmp);
		sort(d+dt+1,d+n+1);
		/*printf("ct=%d,dt=%d\n",ct,dt);
		for(int i=1;i<=n;i++)
			printf("%d ",c[i]);
		printf("\n");
		for(int i=1;i<=n;i++)
			printf("%d ",d[i]);
		printf("\n");*/
		printf("Yes\n");
		int x=0,y=0;
		for(int i=1;i<=n;i++)
		{
			printf("%d %d\n",x,y);
			if(i<=ct) x+=c[i];
			else x-=c[i];
			printf("%d %d\n",x,y);
			if(i<=dt) y+=d[i];
			else y-=d[i];
		}
	}
	return 0;
}