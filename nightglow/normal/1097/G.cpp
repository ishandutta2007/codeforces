#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<set>
#include<vector>
#include<map>
#include<queue>

#define N 100005
#define K 205

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define mk make_pair
#define pb push_back
#define fi first
#define se second

#define Mo 1000000007

using namespace std;

int i,j,m,n,p,k,f[N][K],fa[N],Size[N],g[K][3],x,y,Pow[N],ans,G[K],inv[N];

vector<int>v[N];

void Work(int ID,int a,int b)
{
		int i,j,p;
		for (i=a;i>=0;--i)
			for (j=2;j>=0;--j)
				if (g[i][j])
					for (p=1;p<=b&&i+p<=k;++p)
							(g[i+p][min(2,j+1)]+=1ll*g[i][j]*f[ID][p]%Mo)%=Mo; 
}

void dfs(int x)
{
		int i,j;
		for (i=0;i<(int)v[x].size();++i)
		{
				int p=v[x][i];
				if (fa[x]==p) continue;
				fa[p]=x;
				dfs(p);
		}
		memset(g,0,sizeof(g));
		g[0][0]=1;
		for (i=0;i<(int)v[x].size();++i)
		{
				int p=v[x][i];
				if (fa[x]==p) continue;
				Work(p,min(Size[x],k),min(Size[p],k));
				Size[x]+=Size[p];
		}
		for (i=0;i<=k;++i) 
		  for (j=0;j<3;++j)
			(f[x][i]+=g[i][j])%=Mo;
		for (i=0;i<=k;++i)
			if (g[i][2]) ans=(ans+1ll*g[i][2]*G[i]%Mo)%Mo; 
		Size[x]++;
		if (x>1)
		for (i=k-1;i>=0;--i)
		{
				int cnt;
				if (i==0) cnt=1ll*f[x][i]*(Pow[Size[x]]-1)%Mo*inv[Size[x]]%Mo;
				else cnt=f[x][i];
				(f[x][i+1]+=cnt)%=Mo;
				ans=(ans+1ll*cnt*G[i+1]%Mo*(Pow[n-Size[x]]-1)%Mo*inv[n-Size[x]]%Mo)%Mo;
		}
}

int temp[K][K],C[K][K];

int power(int x,int y)
{
		int sum=1;
		for (;y;y>>=1)
		{
				if (y&1) sum=1ll*sum*x%Mo;
				x=1ll*x*x%Mo; 
		}
		return sum;
}

void pre()
{
	Pow[0]=1;for (i=1;i<N;++i)Pow[i]=1ll*Pow[i-1]*2%Mo;
	for (i=0;i<N;++i) inv[i]=power(Pow[i],Mo-2)%Mo;
	for (i=0;i<K;++i)
	{
			C[i][0]=C[i][i]=1;
			for (j=1;j<i;++j) C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mo;
	}
	int i,j,p;
	temp[0][0]=1;
	for (i=1;i<=k;++i)
		for (j=0;j<=k;++j)
			for (p=1;j+p<=k;++p)
				(temp[i][j+p]+=1ll*temp[i-1][j]*C[k-j][p]%Mo)%=Mo; 
	for (i=1;i<=k;++i) G[i]=temp[i][k];
}

int main()
{
		scanf("%d%d",&n,&k);
		pre();
		for (i=1;i<n;++i)
		{
				scanf("%d%d",&x,&y);
				v[x].pb(y); v[y].pb(x); 
		}
		dfs(1);
		printf("%d\n",1ll*ans*Pow[n]%Mo);
}