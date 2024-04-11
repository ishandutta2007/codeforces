#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int f[2][210][5010],a[210],b[210],n,k,ans;
long long x,y;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		for(y=x;y%2==0;y/=2)
			a[i]++;
		for(;x%5==0;x/=5)
			b[i]++;
	}
	for(int i=0;i<2;i++)
		for(int j=0;j<=k;j++)
			for(int p=0;p<=5000;p++)
				f[i][j][p]=-1000000000;
	f[0][0][0]=0;
	f[1][0][0]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=k;j++)
			for(int p=0;p<=5000;p++)
			{
				if(p>=b[i])
					f[i%2][j][p]=max(f[(i-1)%2][j][p],f[(i-1)%2][j-1][p-b[i]]+a[i]);
				else
					f[i%2][j][p]=f[(i-1)%2][j][p];
			}
	for(int i=1;i<=5000;i++)
		ans=max(ans,min(i,f[n%2][k][i]));
	printf("%d\n",ans);
	return 0;
}