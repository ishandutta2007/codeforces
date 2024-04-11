#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x)
{
	return x<0?x+mod:x;
}
int fpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;
		y/=2;
	}
	return ans;
}
struct mat
{
	int v[215][215],x,y;
	mat(){memset(v,0,sizeof(v));}
}a,s;
mat operator*(const mat &x,const mat &y)
{
	mat z;
	z.x=x.x,z.y=y.y;
	for(int i=1;i<=z.x;i++)
		for(int k=1;k<=x.y;k++)
			for(int j=1;j<=z.y;j++)
				z.v[i][j]=addmod(z.v[i][j]+1ll*x.v[i][k]*y.v[k][j]%mod);
	return z;
}
mat mfpow(mat x,int y)
{
	mat ans=x;
	y--;
	while(y)
	{
		if(y&1) ans=ans*x;
		x=x*x;
		y/=2;
	}
	return ans;
}
int n,m,k;
#define id(x,y) ((x)+((y)<<m)+1)
int main()
{
	scanf("%d%d%d",&n,&k,&m);
	a.x=a.y=((k+1)<<m);
	for(int i=0;i<(1<<m);i++)
	{
		int ct=1;
		for(int j=0;j<m;j++)
			ct+=(i>>j)&1;
		for(int j=0;j<=k;j++)
		{
			a.v[id(((i<<1)&((1<<m)-1)),j)][id(i,j)]=1;
			if(j<k)
			{
				a.v[id(((i<<1)&((1<<m)-1))|1,j+1)][id(i,j)]=ct;
			}
		}
	}
/*	for(int i=1;i<=a.x;i++)
	{
		for(int j=1;j<=a.y;j++)
			printf("%d ",a.v[i][j]);
		printf("\n");
	}*/
	s.x=a.x;
	s.y=1;
	s.v[1][1]=1;
	a=mfpow(a,n);
	s=a*s;
/*	for(int i=1;i<=a.x;i++)
	{
		for(int j=1;j<=a.y;j++)
			printf("%d ",a.v[i][j]);
		printf("\n");
	}*/
	int ans=0;
	for(int i=0;i<(1<<m);i++)
		ans=addmod(ans+s.v[id(i,k)][1]);
	printf("%d\n",ans);
	return 0;
}