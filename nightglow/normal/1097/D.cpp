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

#define N 300005
#define M 8000005

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define mk make_pair
#define pb push_back
#define fi first
#define se second

#define Mo 1000000007

using namespace std;

int i,j,m,p,k,K,inv[105],f[55][10005];

long long n;

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

int Work(int pr,int cnt)
{
		int i,sum=0;
		memset(f,0,sizeof(f));
		f[cnt][0]=1;
		for (i=1;i<=K;++i)
		{
				for (j=cnt;j>=0;--j)
					for (k=j;k>=0;--k)
						(f[k][i]+=1ll*f[j][i-1]*inv[j+1]%Mo)%=Mo; 
		}
		for (i=0;i<=cnt;++i) sum=(sum+1ll*f[i][K]*power(pr,i)%Mo)%Mo;
		return sum;
}

int main()
{
		scanf("%lld%d",&n,&K); 
		for (i=0;i<105;++i) inv[i]=power(i,Mo-2);
		int ans=1;
		for (i=2;1ll*i*i<=n;++i)
		{
				int cnt=0;
				while (n%i==0) n/=i,++cnt;
				if (cnt>=1) ans=1ll*ans*Work(i,cnt)%Mo;
		}
		if (n>1) ans=1ll*ans*Work(n%Mo,1)%Mo;
		printf("%d\n",ans);
}