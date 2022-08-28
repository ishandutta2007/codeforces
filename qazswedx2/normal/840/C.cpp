#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
int n,a[100005],b[100005],c[100005],f[1005][1005],fr[100005],infr[100005],pn=1e5,bt;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x)
{
	return x<0?x+mod:x;
}
int fpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;
		y/=2; 
	}
	return ans;
}
int getansa(int x,int y)
{
	return 1ll*fr[x]*infr[x-y]%mod;
}
int getansc(int x,int y)
{
	if(x<0||y<0||x-y<0) return 0;
	return 1ll*fr[x]*infr[x-y]%mod*infr[y]%mod;
}
int main()
{
	fr[0]=infr[0]=1;
	for(int i=1;i<=pn;i++)
	{
		fr[i]=1ll*fr[i-1]*i%mod;
		infr[i]=fpow(fr[i],mod-2);
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=2;i*i<=1e9;i++)
	{
		int nw=i*i;
		for(int j=1;j<=n;j++)
			while(a[j]%nw==0) a[j]/=nw;
	}
	sort(a+1,a+n+1);
	a[n+1]=-1;
	int ct=1,val=a[1];
	for(int i=2;i<=n+1;i++)
		if(a[i]==val) ct++;
		else
		{
			b[++bt]=ct;
			ct=1;
			val=a[i];
		}
	for(int i=1;i<=bt;i++)
		c[i]=c[i-1]+b[i];
	//for(int i=1;i<=bt;i++)
	//	printf("%d ",b[i]);
	//printf("\n");
	f[0][0]=1;
	for(int i=1;i<=bt;i++)
		for(int j=0;j<c[i];j++)
		{
			for(int k=0;k<=min(b[i]-1,j);k++)
			{
				f[i][j]=addmod(f[i][j]+1ll*f[i-1][j-k]*getansc(b[i]-1,k)%mod*getansc(c[i]-j,b[i]-k)%mod);
			}
			//if(j<=2) printf("i=%d,j=%d,f=%d\n",i,j,f[i][j]);
		}
	int ans=0;
	for(int i=0;i<n;i++)
		if(i%2==0)
			ans=addmod(ans+f[bt][i]);
		else ans=submod(ans-f[bt][i]);
	for(int i=1;i<=bt;i++)
		ans=1ll*ans*fr[b[i]]%mod;
	printf("%d",ans);
	return 0;
}