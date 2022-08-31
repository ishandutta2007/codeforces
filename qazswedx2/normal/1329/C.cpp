#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll ans;
int t,g,h,n,m,a[2000005],b[2000005],c[2000005],f[2000005],vis[2000005];
int tmp[2000005][3],rt[2000005],sd[2000005];
bool cmp(const int x,const int y)
{
	return x>y;
}
void dfs(int x,int y,int dep)
{
	b[y]=a[x];
	if(dep==h) return;
	dfs(x*2,y+1,dep+1);
	dfs(x*2+1,y+(1<<(h-dep)),dep+1);
	int lnw=y+1,lmx=y+(1<<(h-dep))-1,rnw=y+(1<<(h-dep)),rmx=y+(2<<(h-dep))-2;
	tmp[y][0]=b[y];
	tmp[y][1]=2;
	int ct=y;
	int las=0,ras=0;
	while(lnw<=lmx&&rnw<=rmx)
	{
		if(b[lnw]>b[rnw])
		{
			tmp[++ct][0]=b[lnw];
			tmp[ct][1]=0;
			tmp[ct][2]=lnw;
		//	if(dep<g&&b[lnw]==f[x*2]) las=ct;
			lnw++;
		}
		else
		{
			tmp[++ct][0]=b[rnw];
			tmp[ct][1]=1;
			tmp[ct][2]=rnw;
		//	if(dep<g&&b[rnw]==f[x*2+1]) ras=ct;
			rnw++;
		}
	}
	while(lnw<=lmx)
	{
		tmp[++ct][0]=b[lnw];
		tmp[ct][1]=0;
		tmp[ct][2]=lnw;
		//if(dep<g&&b[lnw]==f[x*2]) las=ct;
		lnw++;
	}
	while(rnw<=rmx)
	{
		tmp[++ct][0]=b[rnw];
		tmp[ct][1]=1;
		tmp[ct][2]=rnw;
		//if(dep<g&&b[rnw]==f[x*2+1]) ras=ct;
		rnw++;
	}
	for(int i=y;i<=rnw;i++)
		b[i]=tmp[i][0];
	if(dep>g) return;
	/*printf("x=%d,y=%d,dep=%d,las=%d,ras=%d,lmx=%d,rmx=%d\n",x,y,dep,las,ras,lmx,rmx);*/
	/*for(int i=1;i<=n;i++)
		printf("%d ",b[i]);
	printf("\n");
	for(int i=1;i<=n;i++)
		printf("%d ",tmp[i][1]);
	printf("\n");*/
	if(dep==g) rt[x]=f[x]=b[rmx];
	else
	{
		if(rt[x*2]>rt[x*2+1])
		{
			for(int i=rmx;i>=y;i--)
				if(!vis[b[i]]&&(b[i]>rt[x*2]))
				{
					f[x]=b[i];
			//		printf("i=%d\n",i);
					break;
				}
			rt[x]=max(rt[x*2],f[x]);
			//sd[x]=max(rt[x*2+1],sd[x*2]);
		}
		else
		{
			for(int i=rmx;i>=y;i--)
				if(!vis[b[i]]&&(b[i]>rt[x*2+1]))
				{
					f[x]=b[i];
					break;
				}
			rt[x]=max(rt[x*2+1],f[x]);
			//sd[x]=max(rt[x*2],sd[x*2]);
			//if(rt[x*2+1]!=rt[x]) sd[]x=max(sd)
		}
	}
	//printf("x=%d,rt=%d,f=%d\n",x,rt[x],f[x]);
	vis[f[x]]=1;
	ans+=f[x];
//	printf("f=%d\n",f[x]);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&h,&g);
		n=(1<<h)-1;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),c[a[i]]=i;
		for(int i=1;i<=n;i++)
			vis[a[i]]=0;
		ans=0;
		dfs(1,1,1);
		printf("%I64d\n",ans);
		for(int i=n;i>0;i--)
			if(!vis[a[i]])
				printf("%d ",i);
		printf("\n");
	}
	return 0;
}