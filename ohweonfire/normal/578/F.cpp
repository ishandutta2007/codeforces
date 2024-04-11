#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;

int mod;
int qpow(int x,int y)
{
	int ret=1;
	while(y)
	{
		if(y&1)ret=(LL)ret*x%mod;
		x=(LL)x*x%mod;
		y>>=1;
	}
	return ret;
}

int n,m;
char s[111][111];
int id[111][111],f[11111],id2[11111],sz,a[411][411];
int gf(int x){return x==f[x]?x:f[x]=gf(f[x]);}

void addedge(int u,int v)
{
	u=id2[gf(u)];v=id2[gf(v)];if(u==v)return;
	a[u][v]--;if(a[u][v]<0)a[u][v]+=mod;
	a[v][u]--;if(a[v][u]<0)a[v][u]+=mod;
	a[u][u]++;if(a[u][u]>=mod)a[u][u]-=mod;
	a[v][v]++;if(a[v][v]>=mod)a[v][v]-=mod;
}

int calc_det()
{
	int ret=1;sz--;
	for(int i=1;i<=sz;i++)
	{
		if(!a[i][i])
		{
			for(int j=i+1;j<=sz;j++)if(a[j][i])
			{
				for(int k=1;k<=sz;k++)swap(a[j][k],a[i][k]);
				break;
			}
			if(!a[i][i])return 0;
			ret=mod-ret;
		}
		int inv=qpow(a[i][i],mod-2);ret=(LL)ret*a[i][i]%mod;
		for(int j=1;j<=sz;j++)a[i][j]=(LL)a[i][j]*inv%mod;
		for(int j=i+1;j<=sz;j++)
		{
			int tmp=mod-a[j][i];
			for(int k=1;k<=sz;k++)a[j][k]=(a[j][k]+(LL)a[i][k]*tmp)%mod;
		}
	}
	return ret;
}

int check(int tp)
{
	int tot=0;
	for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)if((i+j)%2==tp)
	{
		id[i][j]=++tot;
		f[tot]=tot;
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
	{
		if((i+j)%2==tp&&s[i][j]!='/')f[gf(id[i-1][j-1])]=gf(id[i][j]);
		else if((i+j)%2!=tp&&s[i][j]!='\\')f[gf(id[i-1][j])]=gf(id[i][j-1]);
	}
	for(int i=1;i<=tot;i++)if(gf(i)!=gf(1))return 0;
	for(int i=1;i<=tot;i++)f[i]=i;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
	{
		if((i+j)%2==tp&&s[i][j]=='\\')
		{
			if(gf(id[i-1][j-1])==gf(id[i][j]))return false;
			f[gf(id[i-1][j-1])]=gf(id[i][j]);
		}
		else if((i+j)%2!=tp&&s[i][j]=='/')
		{
			if(gf(id[i-1][j])==gf(id[i][j-1]))return false;
			f[gf(id[i-1][j])]=gf(id[i][j-1]);
		}
	}
	sz=0;
	for(int i=1;i<=tot;i++)if(f[i]==i)id2[i]=++sz;
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(s[i][j]=='*')
	{
		if((i+j)%2==tp)addedge(id[i-1][j-1],id[i][j]);
		else addedge(id[i-1][j],id[i][j-1]);
	}
	return calc_det();
}

int main()
{
	scanf("%d%d%d",&n,&m,&mod);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	int k0=check(0),k1=check(1),ans=k0+k1;
//	fprintf(stderr,"K0= %d K1= %d\n",k0,k1);
	if(ans>=mod)ans-=mod;
	printf("%d\n",ans);
	return 0;
}