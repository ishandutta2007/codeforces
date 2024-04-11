#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,nxt[100005],len[100005],b[100005][2],c[100005];
char s[100005];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	nxt[n]=n+1;
	for(int i=n-1;i>=0;i--)
	{
		nxt[i]=i+1;
		if(s[i+1]==s[i+2]&&(s[nxt[i+2]]<s[i+1]||(s[nxt[i+2]]==s[i+1]&&c[i+2]<s[i+1])))
		{
		//	printf("%d,%d,s=%c,%c,c=%c,%c\n",nxt[i+2],i+1,s[nxt[i+2]],s[i+1],c[nxt[i+2]],c[i+1]);
			nxt[i]=nxt[i+2];
		}
		if(s[nxt[i]]!=s[nxt[nxt[i]]]) c[i]=s[nxt[nxt[i]]];
		else c[i]=c[nxt[i]];
	//	printf("i=%d,nxt=%d,c=%c\n",i,nxt[i],c[i]);
	}
	for(int i=n;i>=0;i--)
	{
		len[i]=len[nxt[i]]+1;
		b[i][0]=b[nxt[i]][0];
		b[i][1]=b[nxt[i]][1];
		if(len[i]==1) b[i][0]=s[i];
		if(len[i]==2) b[i][1]=s[i];
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",len[i-1]-1);
		if(len[i-1]<=11)
		{
			int u=i-1;
			while(u<=n)
			{
				u=nxt[u];
				if(u<=n) printf("%c",s[u]);
			}
			printf("\n");
			continue;
		}
		int u=i-1;
		for(int j=1;j<=5;j++)
		{
			u=nxt[u];
			printf("%c",s[u]);
		}
		printf("...%c%c\n",b[i-1][1],b[i-1][0]);
	}
	return 0;
}