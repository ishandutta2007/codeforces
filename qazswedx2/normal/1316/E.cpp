#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,p,k,a[100005],b[100005][9],cnt[100005],c[100005];
ll f[2][1005];
bool cmp(const int x,const int y)
{
	return a[x]>a[y];
}
int main()
{
	memset(f,0xcf,sizeof(f));
	scanf("%d%d%d",&n,&p,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),c[i]=i;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=p;j++)
			scanf("%d",&b[i][j]);
	sort(c+1,c+n+1,cmp);
	for(int j=1;j<(1<<p);j++)
		cnt[j]=cnt[j/2]+j%2;
	f[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		int nw=i&1;
		for(int j=0;j<(1<<p);j++)
		{
			f[nw][j]=f[nw^1][j]+(i<=k+cnt[j]?a[c[i]]:0);
			for(int k=1;k<=p;k++)
				if((1<<(k-1))&j)
					f[nw][j]=max(f[nw][j],f[nw^1][j-(1<<(k-1))]+b[c[i]][k]);
		//	printf("i=%d,j=%d,f=%I64d\n",i,j,f[nw][j]);
		}
	}
	printf("%I64d\n",f[n&1][(1<<p)-1]);
	return 0;
}