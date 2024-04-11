#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[100005],f[1005][1005],g[1005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		f[i][i]=a[i];
	for(int i=2;i<=n;i++)
		for(int l=1,r=l+i-1;r<=n;l++,r++)
		{
			for(int k=l;k<r;k++)
				if(f[l][k]&&f[l][k]==f[k+1][r])
				{
					f[l][r]=f[l][k]+1;
					break;
				}
		}
	g[0]=0;
	for(int i=1;i<=n;i++)
	{
		g[i]=1e9;
		for(int j=1;j<=i;j++)
			if(f[j][i]) g[i]=min(g[i],g[j-1]+1);
	}
	printf("%d",g[n]);
	return 0;
}