#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,k,m,f[1005][2];
ll a[1005][1005],tmp[1005][1005];
int main()
{
	scanf("%d",&k);
	n=(1<<k);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%lld",&a[i][j]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&f[i][0],&f[i][1]);
	for(int i=0;i<k;i++)
	{
		memcpy(tmp,a,sizeof(tmp));
		memset(a,0,sizeof(a));
		for(int j=0;j<n;j++)
			for(int l=0;l<n;l++)
				for(int nw=1;nw<=m;nw++)
					a[(j+(f[nw][0]<<i))&(n-1)][(l+(f[nw][1]<<i))&(n-1)]^=tmp[j][l];
	/*	for(int j=0;j<n;j++)
		{
			for(int l=0;l<n;l++)
				printf("%lld ",a[j][l]);
			printf("\n");
		}*/
	}
	int ans=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(a[i][j]) ans++;
	printf("%d\n",ans);
	return 0;
}