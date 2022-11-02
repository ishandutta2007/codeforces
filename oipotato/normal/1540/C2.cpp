#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<cassert>
#include<set>
#include<map>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int MOD=(int)1e9+7;
const int N=110;
int f[N][N*N],ssb[N],sc[N],b[N],c[N],n,q,ans[N];
void work(int&ans,int x)
{
	memset(f,0,sizeof(f));
	rep(i,n)
	{
		if(i==1)for(int j=max(0,x);j<=c[1];j++)f[1][j]=1;
		else
		{
			rep(j,sc[i])(f[i-1][j]+=f[i-1][j-1])%=MOD;
			for(int j=max(0,i*x+ssb[i]);j<=sc[i];j++)f[i][j]=(f[i-1][j]-(j-c[i]-1>=0?f[i-1][j-c[i]-1]:0)+MOD)%MOD;
		}
	}
	ans=0;
	for(int i=0;i<=sc[n];i++)(ans+=f[n][i])%=MOD;
}
int main()
{
	scanf("%d",&n);
	rep(i,n)scanf("%d",&c[i]),sc[i]=sc[i-1]+c[i];
	rep(i,n-1)scanf("%d",&b[i+1]),ssb[i+1]=ssb[i]+b[i+1];
	rep(i,n)ssb[i]+=ssb[i-1];
	int L=(-ssb[n])/n,R=(sc[n]-ssb[n])/n;
	rep(i,n-1)L=min(L,(-ssb[i])/i),R=min(R,(sc[i]-ssb[i])/i);
	L=max(L,-(int)1e5);R=min(R,(int)1e5);
	for(int i=L;i<=R;i++)work(ans[i-L+1],i);
	scanf("%d",&q);
	int pw2=1;
	rep(i,n)pw2=1ll*pw2*(c[i]+1)%MOD;
	rep(Q,q)
	{
		int x;scanf("%d",&x);
		if(x>R)puts("0");
		else if(x<L)printf("%d\n",pw2);
		else printf("%d\n",ans[x-L+1]);
	}
    return 0;
}