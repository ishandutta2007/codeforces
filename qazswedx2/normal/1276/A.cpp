#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,tans[1000005],tt,vis[1000005];
char s[1000005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		tt=0;
		scanf("%s",s+1);
		n=strlen(s+1);
		for(int i=1;i<=n;i++)
			vis[i]=0;
		for(int i=1;i<=n-2;i++)
			if(s[i]=='o'&&s[i+1]=='n'&&s[i+2]=='e'&&!vis[i])
			{
				vis[i]=1;
				tans[++tt]=i+1;
			}
			else if(s[i]=='t'&&s[i+1]=='w'&&s[i+2]=='o')
			{
				if(i+4<=n&&s[i+3]=='n'&&s[i+4]=='e')
				{
					vis[i+2]=1;
					tans[++tt]=i+2;
				}
				else tans[++tt]=i+1;
			}
		printf("%d\n",tt);
		for(int i=1;i<=tt;i++)
			printf("%d ",tans[i]);
		printf("\n");
	}
	return 0;
}