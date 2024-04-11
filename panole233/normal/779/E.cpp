#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<map>
#include<string>

using namespace std;

map<string,int>mp;
int n,m,a[5001][3],wei,val[5001][1001],ans,minans[5001],maxans[5001],minsum,maxsum;
string s1,s2,s3,s4,s5;
bool bo[5001];
char ch;

void dfs(int x) 
{
	bo[x]=1;
	if (!bo[a[x][1]]) dfs(a[x][1]);
	if (!bo[a[x][2]]) dfs(a[x][2]);
	if (a[x][0]==1) val[x][wei]=val[a[x][1]][wei]^val[a[x][2]][wei]; else
	if (a[x][0]==2) val[x][wei]=val[a[x][1]][wei]&val[a[x][2]][wei]; else
	if (a[x][0]==3) val[x][wei]=val[a[x][1]][wei]|val[a[x][2]][wei];
}

int main()
{
	scanf("%d%d",&n,&m);
	mp["?"]=0;
	for (int i=1; i<=n; i++)
	{
		cin>>s1>>s2>>s3;
		mp[s1]=i; ch=getchar();
		while (ch==' ') ch=getchar();
		if (ch=='\n')
		{
			a[i][0]=-1; 
			for (int j=0; j<m; j++) val[i][j+1]=s3[j]-48;
		}
		else
		{
			cin>>s4>>s5;
			if (ch=='X') a[i][0]=1; else
			if (ch=='A') a[i][0]=2; else
			if (ch=='O') a[i][0]=3;
			a[i][1]=mp[s3]; a[i][2]=mp[s5];
		}
	}
	memset(bo,0,sizeof(bo)); bo[0]=1;
	for (int i=1; i<=n; i++)
		if (a[i][0]==-1) bo[i]=1;
	for (int i=m; i>=1; i--)
	{
		minsum=n+1; maxsum=-1;
		for (int j=0; j<=1; j++)
		{
			wei=i; val[0][i]=j;
			for (int k=1; k<=n; k++)
				if (!bo[k]) dfs(k);
			ans=0;
			for (int k=1; k<=n; k++)
				ans+=val[k][i];
			if (ans>maxsum) maxsum=ans,maxans[i]=j;
			if (ans<minsum) minsum=ans,minans[i]=j;
			for (int k=1; k<=n; k++) 
				if (a[k][0]!=-1) bo[k]=0;
		}
	}
	for (int i=1; i<=m; i++) printf("%d",minans[i]); printf("\n");
	for (int i=1; i<=m; i++) printf("%d",maxans[i]); printf("\n");
	return 0;
}