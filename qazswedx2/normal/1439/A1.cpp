#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,m,tans[100005][6],tt,b[15]={11,7,14,13},f[105],rf[105];
int g[105][6]={{-1,-1,-1,0,0,-1},{-1,-1,-1,0,0,0},{-1,0,0,0,0,-1},{-1,-1,0,-1,0,0}};
char a[1005][1005];
void upd(int v0,int v1,int v2,int v3,int v4,int v5)
{
	tt++;
	tans[tt][0]=v0,tans[tt][1]=v1,tans[tt][2]=v2;
	tans[tt][3]=v3,tans[tt][4]=v4,tans[tt][5]=v5;
	a[v0][v1]^=1,a[v2][v3]^=1,a[v4][v5]^=1;
}
int main()
{
	for(int i=0;i<16;i++)
	{
		for(int j=0;j<4;j++)
			if(i&(1<<j))
				f[i]^=b[j];
		rf[f[i]]=i;
	}
	scanf("%d",&t);
	while(t--)
	{
		tt=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf(" %c",&a[i][j]);
		for(int i=1;i<=n-2;i++)
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]=='0') continue;
				if(j<m) upd(i,j,i,j+1,i+1,j+1);
				else upd(i,j,i+1,j,i+1,j-1);
			}
		for(int j=1;j<=m-2;j++)
		{
			int nw=(a[n-1][j]-'0')*2+a[n][j]-'0';
			if(nw==1) upd(n,j,n-1,j+1,n,j+1);
			if(nw==2) upd(n-1,j,n-1,j+1,n,j+1);
			if(nw==3) upd(n-1,j,n,j,n,j+1);
		}
		int nw=0;
		if(a[n-1][m-1]=='1') nw+=(1<<0);
		if(a[n-1][m]=='1') nw+=(1<<1);
		if(a[n][m]=='1') nw+=(1<<2);
		if(a[n][m-1]=='1') nw+=(1<<3);
		nw=rf[nw];
		for(int i=0;i<4;i++)
			if(nw&(1<<i))
			{
				tt++;
				for(int j=0;j<6;j+=2)
					tans[tt][j]=n+g[i][j],tans[tt][j+1]=m+g[i][j+1];
			}
		printf("%d\n",tt);
		for(int i=1;i<=tt;i++)
		{
			for(int j=0;j<6;j++)
				printf("%d ",tans[i][j]);
			printf("\n");
		}
	}
	return 0;
}