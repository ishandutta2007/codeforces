#include<cstdio>
#include<iostream>
#include<cmath>
#include<cassert>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<vector>
using namespace std;
#define pb push_back
#define x0 fuckcjb
#define x1 fuckshb
#define y0 fucksub
#define y1 fuckjtjl
const int MOD=1E9+7;
const int inv=(MOD+1)>>1;
int vab[1<<17],vc[1<<17],vde[1<<17],f[1<<17],B[20],n,ans,x;
void FWT(int *a,int n,int type)
{
	for(int d=1;d<n;d<<=1)
	{
		for(int m=d<<1,i=0;i<n;i+=m)
		{
			for(int j=0;j<d;j++)
			{
				int x=a[i+j],y=a[i+j+d];
				if(type==0)
				{
					a[i+j]=(x+y)%MOD;
					a[i+j+d]=(x-y+MOD)%MOD;
				}
				else
				{
					a[i+j]=(x+y)%MOD;
				}
			}
		}
	}
}
void UFWT(int *a,int n,int type)
{
	for(int d=1;d<n;d<<=1)
	{
		for(int m=d<<1,i=0;i<n;i+=m)
		{
			for(int j=0;j<d;j++)
			{
				int x=a[i+j],y=a[i+j+d];
				if(type==0)
				{
					a[i+j]=1ll*(x+y)*inv%MOD;
					a[i+j+d]=1ll*(x-y+MOD)*inv%MOD;
				}
				else
				{
					a[i+j]=(x-y+MOD)%MOD;
				}
			}
		}
	}
}
int main()
{
	for(int i=0;i<=17;i++)
	{
		B[i]=1<<i;
	}
	f[0]=0;f[1]=1;
	for(int i=2;i<B[17];i++)
	{
		f[i]=(f[i-1]+f[i-2])%MOD;
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		vc[x]++;vde[x]++;
	}
	for(int i=0;i<B[17];i++)
	{
		for(int j=i;;j=(j-1)&i)
		{
			vab[i]=(vab[i]+1ll*vc[j]*vc[i^j])%MOD;
			if(!j)
			{
				break;
			}
		}
	}
	FWT(vde,B[17],0);
	for(int i=0;i<B[17];i++)
	{
		vde[i]=1ll*vde[i]*vde[i]%MOD;
	}
	UFWT(vde,B[17],0);
	for(int i=0;i<B[17];i++)
	{
		vab[i]=1ll*vab[i]*f[i]%MOD;
		vc[i]=1ll*vc[i]*f[i]%MOD;
		vde[i]=1ll*vde[i]*f[i]%MOD;
	}
	FWT(vab,B[17],1);FWT(vc,B[17],1);FWT(vde,B[17],1);
	for(int i=0;i<B[17];i++)
	{
		vab[i]=1ll*vab[i]*vc[i]%MOD*vde[i]%MOD;
	}
	UFWT(vab,B[17],1);
	for(int i=0;i<17;i++)
	{
		ans=(ans+vab[1<<i])%MOD;
	}
	printf("%d\n",ans);
	return 0;
}