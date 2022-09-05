#include<bits/stdc++.h>
using namespace std;

long long ans;
int n,g[12][12],nw,F[2][11][11][11],x,y,mo[1001];
char s[100101];

int main()
{
	for (int i=0; i<=1000; i++) mo[i]=i%11;
	scanf("%s",s),n=strlen(s),ans=0;
	for (int i=0; i<11; i++)
	{
		g[i][0]=0;
		for (int j=1; j<11; j++) g[i][j]=(g[i][j-1]+i+j-1)%11;
	}
	x=1,y=0;
	memset(F,0,sizeof(F)); 
	for (int i=1; i<=n; i++)
	{
		x^=1,y^=1;
		nw=s[i-1]-'0';
		for (int j=0; j<11; j++) if (nw<j) 
			for (int k=0; k<11; k++)
				for (int l=0; l<11; l++) if (F[x][j][k][l])
				{
					ans+=F[x][j][k][l];
					F[y][mo[l+g[(k==10?0:k+1)][(j-k+10>=11?j-k-1:j-k+10)]+nw+1]][l][mo[l+g[(k==10?0:k+1)][l<k?l-k+11:l-k]]]+=F[x][j][k][l];
				}
		memset(F[x],0,sizeof(F[x]));
		if (nw) F[y][nw][0][9]++,ans++;
	}
	printf("%I64d\n",ans);
	return 0;
}