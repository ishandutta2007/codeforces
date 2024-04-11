#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,vis[1005];
char s[1000005];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		memset(vis,0,sizeof(vis));
		scanf("%s",s+1);
		n=strlen(s+1);
		int nw=n;
		for(int i=n;i>0;i--)
		{
			if(!vis[s[i]])
			{
				vis[s[i]]=1;
				nw=i;
			}
		}
		printf("%s\n",s+nw);
	}
	return 0;
}