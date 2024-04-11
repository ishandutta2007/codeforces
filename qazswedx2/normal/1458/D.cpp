#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,vis[2000005],pn=1e6;
char s[1000005],ans[1000005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		for(int i=-n-1;i<=n+1;i++)
			vis[i+pn]=0;
		int nw=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0')
			{
				nw--;
				vis[nw+pn]++;
			}
			else
			{
				vis[nw+pn]++;
				nw++;
			}
		}
		ans[n+1]=0;
		nw=0;
		for(int i=1;i<=n;i++)
		{
			if(!vis[nw+pn]||vis[nw+pn-1]>=2)
			{
				vis[nw+pn-1]--;
				nw--;
				ans[i]='0';
			}
			else
			{
				vis[nw+pn]--;
				nw++;
				ans[i]='1';
			}
		}
		printf("%s\n",ans+1);
	}
	return 0;
}