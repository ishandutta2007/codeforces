#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
int n,f[1005][1005][2],pw[1005];
char s[1005];
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x)
{
	return x<0?x+mod:x;
}
int dfs(int dep,int cnt,int lim,int x)
{
	if(dep==n+1) return pw[cnt];
	if(f[dep][cnt][lim]!=-1) return f[dep][cnt][lim];
	int ans=0,mx=(lim==0?s[dep]-'0':9);
	for(int i=0;i<=mx;i++)
		ans=addmod(ans+dfs(dep+1,cnt+(i>=x),lim||i<mx,x));
	return f[dep][cnt][lim]=ans;
}
int main()
{
	pw[1]=1;
	for(int i=2;i<=1000;i++)
		pw[i]=addmod(10ll*pw[i-1]%mod+1);
	scanf("%s",s+1);
	n=strlen(s+1);
	int ans=0;
	for(int i=1;i<=9;i++)
	{
		memset(f,0xff,sizeof(f));
		ans=addmod(ans+dfs(1,0,0,i));
	}
	printf("%d",ans);
	return 0;
}