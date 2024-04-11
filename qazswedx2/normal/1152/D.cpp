#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,f[2005][2005][2],mod=1e9+7;
int main()
{
	memset(f,0xcf,sizeof(f));
	scanf("%I64d",&n);
	f[2*n][0][0]=0;
	for(ll i=2*n-1;i>=0;i--)
	{
		for(ll j=0;j<=min(n,2*n-i);j++)
		{
			if(j==0)
			{
				f[i][j][1]=(f[i+1][j+1][0]+1)%mod;
				f[i][j][0]=max(f[i+1][j+1][0],f[i+1][j+1][1]);
			}
			else if(j==min(n,2*n-i))
			{
				f[i][j][1]=(f[i+1][j-1][0]+1)%mod;
				f[i][j][0]=max(f[i+1][j-1][0],f[i+1][j-1][1]);
			}
			else
			{
				ll ls=max(f[i+1][j+1][0],f[i+1][j+1][1]),rs=max(f[i+1][j-1][0],f[i+1][j-1][1]);
				f[i][j][0]=(ls+rs)%mod;
				f[i][j][1]=max(ls+f[i+1][j-1][0]+1,rs+f[i+1][j+1][0]+1)%mod;
			}
		}
	}
	printf("%I64d",max(f[0][0][0],f[0][0][1]));
	return 0;
}