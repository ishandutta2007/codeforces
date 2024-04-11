#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<set>
#include<map>
#include<iostream>

#define fi first
#define se second
#define mk make_pair
#define pb push_back

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define N 105

using namespace std;

int f[N][N][N*100],a[N],b[N],i,j,m,n,p,k;

int main()
{
	memset(f,60,sizeof(f));
	f[0][0][0]=0;
	scanf("%d",&n);
	for (i=1;i<=n;++i) scanf("%d%d",&a[i],&b[i]),a[0]+=a[i],b[0]+=b[i];
	for (i=1;i<=n;++i)
		 for (j=0;j<i;++j)
		 	for (k=0;k<=100*i;++k)
		 		if (f[i-1][j][k]<=100000)
		 		{
		 			f[i][j][k]=min(f[i][j][k],f[i-1][j][k]);
		 			f[i][j+1][k+b[i]]=min(f[i][j+1][k+b[i]],f[i-1][j][k]+a[i]);
		 		}
	for (j=n-1;j>=0;--j)
	{
		int ans=0;
		for (k=0;k<=100*i;++k) if (f[n][j][k]<=100000) ans=max(ans,2*(b[0]-k)+min(2*(a[0]-f[n][j][k]-(b[0]-k)),k));
		if (ans%2) printf("%d.5 ",ans/2);
		else printf("%d ",ans/2);
	}
}