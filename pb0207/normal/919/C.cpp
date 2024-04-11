#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int N=2e3+1e2+7;

int n,m,k,f[N][N],g[N][N];

char s[N][N];

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			f[i][j]=f[i][j-1]+(s[i][j]=='.');
	for(int j=1;j<=m;j++)
		for(int i=1;i<=n;i++)
			g[i][j]=g[i-1][j]+(s[i][j]=='.');
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=k;j<=m;j++)
			if(f[i][j]-f[i][j-k]==k)
				ans++;
	for(int i=k;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(g[i][j]-g[i-k][j]==k)
				ans++;
	printf("%d",ans/(k==1?2:1));
}