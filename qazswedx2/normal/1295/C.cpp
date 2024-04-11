#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,tt,nxt[100005][26],vis[105];
char s[100005],t[100005];
int main()
{
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%s%s",s+1,t+1);
		n=strlen(s+1),m=strlen(t+1);
		for(int i=0;i<26;i++)
			vis[i]=n+1;
		for(int i=n;i>=0;i--)
		{
			for(int j=0;j<26;j++)
				nxt[i][j]=vis[j];
			if(i) vis[s[i]-'a']=i;
		}
		int tans=0,nw=0;
		for(int i=1;i<=m;i++)
		{
			nw=nxt[nw][t[i]-'a'];
			if(nw==n+1)
			{
				tans++;
				nw=nxt[0][t[i]-'a'];
				if(nw==n+1)
				{
					tans=-2;
					break;
				}
			}
		}
		printf("%d\n",tans+1);
	}
	return 0;
}