#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,f[2005][2005],sum1[100005][26],sum2[100005][26];
char a[100005],b[100005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%s%s",&n,a+1,b+1);
		for(int i=1;i<=n;i++)
			for(int j=0;j<26;j++)
				if(a[i]-'a'==j) sum1[i][j]=sum1[i-1][j]+1;
				else sum1[i][j]=sum1[i-1][j];
		for(int i=1;i<=n;i++)
			for(int j=0;j<26;j++)
				if(b[i]-'a'==j) sum2[i][j]=sum2[i-1][j]+1;
				else sum2[i][j]=sum2[i-1][j];
		int fl=1;
		for(int i=0;i<26;i++)
			if(sum1[n][i]!=sum2[n][i])
				fl=0;
		if(!fl)
		{
			printf("-1\n");
			continue;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				f[i][j]=max(f[i-1][j],f[i][j-1]);
				int fl=(a[i]==b[j]);
				for(int k=0;k<26&&fl;k++)
					if(sum1[i][k]>sum2[j][k])
						fl=0;
			//	printf("i=%d,j=%d,fl=%d\n",i,j,fl);
				if(fl) f[i][j]=max(f[i][j],f[i-1][j-1]+1);
			}
		printf("%d\n",n-f[n][n]);
	}
	return 0;
}