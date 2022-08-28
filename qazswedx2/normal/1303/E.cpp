#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int tt,f[1005][1005],n,m,nxt[1005][26],vis[26];
char s[100005],t[100005];
int main()
{
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%s%s",s+1,t+1);
		n=strlen(s+1);
		m=strlen(t+1);
		for(int i=0;i<26;i++)
			vis[i]=n+1;
		for(int i=n;i>=0;i--)
		{
			for(int j=0;j<26;j++)
			{
				nxt[i][j]=vis[j];
			//	printf("i=%d,j=%d,nxt=%d\n",i,j,nxt[i][j]);
			}
			vis[s[i]-'a']=i;
		}
		int fl=0;
		for(int i=1;i<=m;i++)
		{
			for(int j=0;j<=i;j++)
				for(int k=i;k<=m;k++)
					f[j][k]=1e9;
			f[0][i]=0;
			for(int j=0;j<=i;j++)
				for(int k=i;k<=m;k++)
				{
					if(f[j][k]>n) continue;
					if(j<i) f[j+1][k]=min(f[j+1][k],nxt[f[j][k]][t[j+1]-'a']);
					if(k<m) 
					{
						//printf("f=%d,f=%d,nxt=%d\n",f[j][k+1],f[j][k],nxt[f[j][k]][t[k+1]-'a']);
						f[j][k+1]=min(f[j][k+1],nxt[f[j][k]][t[k+1]-'a']);
					}
					//printf("i=%d,j=%d,k=%d,f=%d\n",i,j,k,f[j][k]);
				}
			if(f[i][m]<=n)
			{
				fl=1;
				break;
			}
		}
		if(fl) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}