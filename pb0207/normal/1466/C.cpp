#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,f[2][26][26],g[26][26],h[26][26];

char s[N];

int n;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		if(n==1)
		{
			puts("0");
		}
		else if(n==2)
		{
			if(s[1]==s[2])
				puts("1");
			else
				puts("0");
		}
		else
		{
			for(int i=0;i<2;i++)
				for(int j=0;j<26;j++)
					for(int k=0;k<26;k++)
						f[i][j][k]=1e9;
			for(int i=0;i<26;i++)
				for(int j=0;j<26;j++)
					if(i!=j)
						f[0][i][j]=(i!=s[2]-'a')+(j!=s[1]-'a');
			for(int i=3;i<=n;i++)
			{
				for(int j=0;j<26;j++)
				{
					g[j][0]=f[(i-1)&1][j][0];
					h[j][25]=f[(i-1)&1][j][25];
					for(int k=1;k<26;k++)
						g[j][k]=min(g[j][k-1],f[(i-1)&1][j][k]);
					for(int k=24;k>=0;k--)
						h[j][k]=min(h[j][k+1],f[(i-1)&1][j][k]);
				}
				for(int j=0;j<26;j++)
					for(int k=0;k<26;k++)
						if(j!=k)
						{
							f[i&1][j][k]=1e9;
							f[i&1][j][k]=min(f[i&1][j][k],min(j==0?(int)1e9:g[k][j-1],j==25?(int)1e9:h[k][j+1])+(j!=s[i]-'a'));
						}
			}
			int ans=1e9;
			for(int i=0;i<26;i++)
				for(int j=0;j<26;j++)
					ans=min(ans,f[n&1][i][j]);
			printf("%d\n",ans);
		}
	}
}