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
int n,m,f[3005][3005];
char s[100005],t[100005];
int main()
{
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	//f[n][0]=1;
	for(int i=n;i>0;i--)
		for(int j=0;j<=n-i;j++)
		{
			if(i>=m&&j==0) f[i][j]=addmod(f[i][j]+1);
			if(j+1>m||t[j+1]==s[i]) f[i-1][j+1]=addmod(f[i-1][j+1]+f[i][j]);
			int r=n-(n-i-j);
			if(r>m||t[r]==s[i]) f[i-1][j]=addmod(f[i-1][j]+f[i][j]);
		//	if(f[i][j]) printf("i=%d,j=%d,f=%d\n",i,j,f[i][j]);
		}
	int ans=0;
	for(int i=0;i<=n;i++)
		ans=addmod(ans+f[0][i]);
	printf("%d",ans);
	return 0;
}