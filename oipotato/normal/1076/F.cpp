#include<cstdio>
#include<algorithm>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
int f[2][300010],a[2][300010],n,k;
void update(int rest,int o1,int o2,int id)
{
	if(o1==o2)
	{
		if(1ll*k*a[o2][id]<a[o2^1][id])return;
		f[o2][id]=min(f[o2][id],(int)max(1ll,a[o2][id]-1ll*k*(a[o2^1][id]-1)-rest));
	}
	else
	{
		if(1ll*k*(a[o2][id]-1)<a[o2^1][id]-rest)return;
		f[o2][id]=min(f[o2][id],(int)max(1ll,a[o2][id]-1ll*k*(a[o2^1][id])));
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	rep(i,n)f[0][i]=f[1][i]=k+1;
	rep(i,n)scanf("%d",&a[0][i]);
	rep(i,n)scanf("%d",&a[1][i]);
	rep(i,n)
	for(int j=0;j<2;j++)
	for(int k=0;k<2;k++)
	if(f[j][i-1]<=::k)
	update(::k-f[j][i-1],j,k,i);
	//rep(i,n)printf("%d %d\n",f[0][i],f[1][i]);
	puts(f[0][n]<=k||f[1][n]<=k?"YES":"NO");
	return 0;
}