#include<cstdio>
#include<cstring>
using namespace std;

#define ff fflush(stdout)
int n,ans[5001],an;
char s[5];

void dfs(int x,int y)
{
	if (x+y==n+1) return;
	if (x+1<=n)
	{
		printf("? %d %d %d %d\n",x+1,y,n,n);
		ff; scanf("%s",s); if (s[0]=='Y') {ans[++an]=1; dfs(x+1,y); return;}
	}
	ans[++an]=0; dfs(x,y+1);
}

void Dfs(int x,int y)
{
	if (x+y==n+1)
	{
		printf("! ");
		for (int i=1; i<n; i++) 
			if (ans[i]) printf("D"); else printf("R");
		for (int i=an; i>=n; i--)
			if (ans[i]) printf("D"); else printf("R");
		printf("\n");
		return;
	}
	if (y-1>0)
	{
		printf("? 1 1 %d %d\n",x,y-1);
		ff; scanf("%s",s); if (s[0]=='Y') {ans[++an]=0; Dfs(x,y-1); return;}
	}
	ans[++an]=1; Dfs(x-1,y);
}

int main()
{
	scanf("%d",&n);
	an=0; dfs(1,1); Dfs(n,n);
	return 0;
}