#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int f[200010][5],pre[200010][5],del[200010][5],n,a[200010];
char s[200010];
bool update(int&x,int y){if(y<x){x=y;return 1;}return 0;}
int main()
{
	int T;scanf("%d",&T);
	for(;T--;)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		for(int i=0;i<=n;i++)for(int j=0;j<=4;j++)f[i][j]=n;
		f[0][0]=0;
		for(int i=0;i<n;i++)
		for(int j=0;j<=4;j++)
		if(f[i][j]<n)
		{
			if(update(f[i+1][j],f[i][j]+1))pre[i+1][j]=j,del[i+1][j]=1;
			if(j==2&&s[i+1]=='e')continue;
			if(j==4&&s[i+1]=='o')continue;
			if(s[i+1]=='o'){if(update(f[i+1][1],f[i][j]))pre[i+1][1]=j,del[i+1][1]=0;}
			else if(s[i+1]=='t'){if(update(f[i+1][3],f[i][j]))pre[i+1][3]=j,del[i+1][3]=0;}
			else if(j==1&&s[i+1]=='n'){if(update(f[i+1][2],f[i][j]))pre[i+1][2]=j,del[i+1][2]=0;}
			else if(j==3&&s[i+1]=='w'){if(update(f[i+1][4],f[i][j]))pre[i+1][4]=j,del[i+1][4]=0;}
			else if(update(f[i+1][0],f[i][j]))pre[i+1][0]=j,del[i+1][0]=0;
		}
		int ans=n,p;
		for(int i=0;i<=4;i++)if(update(ans,f[n][i]))p=i;
		int x=0;
		for(int i=n,j=p;i;i--)
		{
			if(del[i][j])a[++x]=i;
			j=pre[i][j];
		}
		printf("%d\n",ans);
		reverse(a+1,a+x+1);
		for(int i=1;i<=x;i++)printf("%d%c",a[i]," \n"[i==x]);
	}
	return 0;
}