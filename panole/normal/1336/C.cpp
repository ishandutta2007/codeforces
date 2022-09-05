#include<bits/stdc++.h>
using namespace  std;

const int mod=998244353;
int n,m,f[3010][3010];
char s[3010],t[3010];

void add(int &x,int y) {x=(x+y>=mod?x+y-mod:x+y);}

int main()
{
	scanf("%s",s+1),n=strlen(s+1);
	scanf("%s",t+1),m=strlen(t+1);
	for (int i=1; i<=m; i++) if (s[1]==t[i]) f[1][i]=2;
	for (int i=m+1; i<=n; i++) f[1][i]=2;
	int ans=0;
	if (m==1) add(ans,f[1][1]);
	for (int i=2; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
			if (f[i-1][j])
			{
				if (j>1&&(j-1<=m&&s[i]==t[j-1]||j-1>m)) add(f[i][j-1],f[i-1][j]);
				if (i+j-1<=m&&s[i]==t[i+j-1]||i+j-1>m&&i+j-1<=n) add(f[i][j],f[i-1][j]);
			}
		if (i>=m) add(ans,f[i][1]);
	}
	printf("%d\n",ans);
	return 0;
}