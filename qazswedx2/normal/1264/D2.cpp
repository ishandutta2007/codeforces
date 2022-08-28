#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
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
char s[1000005];
int n,m,sum[1000005],sum2[1000005],fr[1000005],infr[1000005],pn=1e6;
int c[1000005][3];
int C(int x,int y)
{
	if(x<0||y<0) return 0;
	return 1ll*fr[x]*infr[y]%mod*infr[x-y]%mod;
}
int main()
{
	fr[0]=infr[0]=1;
	for(int i=1;i<=pn;i++)
		fr[i]=1ll*fr[i-1]*i%mod;
	infr[pn]=fpow(fr[pn],mod-2);
	for(int i=pn-1;i>0;i--)
		infr[i]=1ll*infr[i+1]*(i+1)%mod;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		c[i][0]=c[i-1][0],c[i][1]=c[i-1][1],c[i][2]=c[i-1][2];
		if(s[i]=='(') c[i][0]++;
		else if(s[i]==')') c[i][1]++;
		else c[i][2]++;
	}
	m=c[n][2];
	sum[0]=sum2[0]=1;
	for(int i=1;i<=m;i++)
	{
		sum[i]=addmod(sum[i-1]+C(m,i));
		sum2[i]=addmod(sum2[i-1]+C(m-1,i));
	}
//	for(int i=0;i<=m;i++)
//		printf("i=%d,sum=%d,%d\n",i,sum[i],sum2[i]);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int v=m-c[i][2]+c[n][1]-c[i][1]-c[i-1][0]-1;
		//printf("i=%d,v=%d\n",i,v);
		if(v<0) continue;
		v=min(v,m);
		if(s[i]=='(')
			ans=addmod(ans+sum[v]);
		if(s[i]=='?')
			ans=addmod(ans+sum2[v]);
	}
	printf("%d",ans);
	return 0;
}