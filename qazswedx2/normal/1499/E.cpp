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
int n,m,f[1005][1005][2],g[1005],h[1005],ans;
char s[1005],t[1005];
int main()
{
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1),m=strlen(t+1);
	g[1]=h[1]=1;
	for(int i=2;i<=n;i++)
	{
		g[i]=1;
		if(s[i]!=s[i-1])
			g[i]+=g[i-1];
	}
	for(int i=2;i<=m;i++)
	{
		h[i]=1;
		if(t[i]!=t[i-1])
			h[i]+=h[i-1];
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			f[i][j][0]=0;
			f[i][j][1]=0;
			if(s[i]!=t[j])
			{
				f[i][j][0]=addmod(h[j]+f[i-1][j][1]);
				f[i][j][1]=addmod(g[i]+f[i][j-1][0]);
			}
			if(i>1&&s[i]!=s[i-1])
				f[i][j][0]=addmod(f[i][j][0]+f[i-1][j][0]);
			if(j>1&&t[j]!=t[j-1])
				f[i][j][1]=addmod(f[i][j][1]+f[i][j-1][1]);
			ans=(1ll*ans+f[i][j][0]+f[i][j][1])%mod;
		//	printf("i=%d,j=%d,f=%d,%d\n",i,j,f[i][j][0],f[i][j][1]);
		}
	printf("%d\n",ans);
	return 0;
}