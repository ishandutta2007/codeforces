#include<bits/stdc++.h>
using namespace std;

int n,m,f[5010][5010];
char s[5010],t[5010];

int main()
{
	int ans=0;
	scanf("%d%d",&n,&m);
	scanf("%s",s+1),scanf("%s",t+1);
	for (int i=0; i<=max(n,m); i++) f[i][0]=f[0][i]=-12345;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
		{
			f[i][j]=max(f[i-1][j-1],0)+(s[i]==t[j]?2:-2);
			f[i][j]=max(f[i][j],f[i-1][j]-1);
			f[i][j]=max(f[i][j],f[i][j-1]-1);
			ans=max(ans,f[i][j]);
		}
	printf("%d\n",ans);
	return 0;
}