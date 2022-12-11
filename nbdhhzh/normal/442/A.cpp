#include<cstdio>
using namespace std;
const char c[]={'R','G','B','Y','W'};
int ans,ss[11],ff[11],n,kn[110],us[11],vs[11],f[110],i,g[266],j,v;
char s[100];
void dfs(int x)
{
	int i,j,vv[110];
	if(x>=ans)return;
	for(i=1;i<=n;i++)if(kn[i]^(1<<f[i]))break;
	if(i>n){ans=x;return;}
	for(i=1;i<=n;i++)vv[i]=kn[i];
	for(i=0;i<5;i++)if(!us[i])
	{
		us[i]=1;
		for(j=1;j<=n;j++)
			if(f[j]/5==i)kn[j]&=ff[i];
			else kn[j]&=~ff[i];
		dfs(x+1);us[i]=0;
		for(j=1;j<=n;j++)kn[j]=vv[j];
	}for(i=0;i<5;i++)if(!vs[i])
	{
		vs[i]=1;
		for(j=1;j<=n;j++)
			if(f[j]%5==i)kn[j]&=ss[i];
			else kn[j]&=~ss[i];
		dfs(x+1);vs[i]=0;
		for(j=1;j<=n;j++)kn[j]=vv[j];
	}
}
int main()
{
	scanf("%d",&n);ans=10;
	for(i=0;i<5;i++)g[c[i]]=i;
	for(i=1;i<=n;i++)
	{
		scanf("%s",&s);
		f[i]=g[s[0]]*5+s[1]-'1';
		v|=1<<f[i];
	}for(i=1;i<=n;i++)kn[i]=v;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			ss[i]|=1<<j*5+i,ff[i]|=1<<i*5+j;
	dfs(0);printf("%d\n",ans);
}