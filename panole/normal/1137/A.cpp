#include<bits/stdc++.h>
using namespace std;

int s[1001][1001],n,m,dal[1001][1001],dah[1001][1001],xil[1001][1001],xih[1001][1001],id[1002],nw;

int cmp1(int a,int b) {return s[nw][a]<s[nw][b];}
int cmp2(int a,int b) {return s[a][nw]<s[b][nw];}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++) 
		for (int j=1; j<=m; j++) scanf("%d",&s[i][j]);
	int cnt;
	for (int i=1; i<=n; i++)
	{
		nw=i;
		for (int j=1; j<=m; j++) id[j]=j;
		sort(id+1,id+1+m,cmp1),cnt=0,s[i][0]=id[0]=0;
		for (int j=1; j<=m; j++)
		{
			if (s[i][id[j]]!=s[i][id[j-1]]) cnt++;
			xih[i][id[j]]=cnt-1;
		}
		cnt=s[i][0]=id[m+1]=0;
		for (int j=m; j; j--)
		{
			if (s[i][id[j]]!=s[i][id[j+1]]) cnt++;
			dah[i][id[j]]=cnt-1;
		}
	}
	for (int j=1; j<=m; j++)
	{
		nw=j;
		for (int i=1; i<=n; i++) id[i]=i;
		sort(id+1,id+1+n,cmp2),cnt=0,s[0][j]=id[0]=0;
		for (int i=1; i<=n; i++)
		{
			if (s[id[i]][j]!=s[id[i-1]][j]) cnt++;
			xil[id[i]][j]=cnt-1;
		}
		cnt=s[0][j]=id[n+1]=0;
		for (int i=n; i; i--)
		{
			if (s[id[i]][j]!=s[id[i+1]][j]) cnt++;
			dal[id[i]][j]=cnt-1;
		}
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++) printf("%d ",max(dah[i][j],dal[i][j])+max(xih[i][j],xil[i][j])+1);
		puts("");
	}
	return 0;
}