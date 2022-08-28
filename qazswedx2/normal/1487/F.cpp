#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int len,f[60][805][805],pn=405;
char s[105];
inline int F(int x)
{
	return x>0?x:-x;
}
int dfs(int dep,int x,int y)
{
	if(dep==len+1) return x?1e9:0;
	if(F(x)>400||F(y)>400) return 1e9;
	if(f[dep][x+pn][y+pn]!=-1) return f[dep][x+pn][y+pn];
	int xx=x*10+s[dep]-'0'+y;
	int ans=1e9;
	for(int i=-6;i<=6;i++)
		ans=min(ans,F(i)*(len-dep+1)+dfs(dep+1,xx+i,y+i));
//	printf("dfs:dep=%d,x=%d,y=%d,ans=%d\n",dep,x,y,ans);
	return f[dep][x+pn][y+pn]=ans;
}
int main()
{
	memset(f,-1,sizeof(f));
	scanf("%s",s+6);
	len=strlen(s+6)+5;
	for(int i=1;i<=5;i++)
		s[i]='0';
	printf("%d\n",dfs(1,0,0));
	return 0;
}