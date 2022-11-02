#include <bits/stdc++.h>
#define MAXN 1007
using namespace std;
bool b[MAXN][MAXN],vi[MAXN][MAXN];
int cntr,cntc,n,m,res;
void dfs(int x,int y)
{
	if(!b[x][y] || vi[x][y]) return;
	vi[x][y]=true;
	dfs(x+1,y);
	dfs(x-1,y);
	dfs(x,y+1);
	dfs(x,y-1);
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		for(int j=1;j<=m;j++) b[i][j]=(s[j-1]=='#');
	}
	for(int i=1;i<=n;i++)
	{
		int ch=0;
		for(int j=1;j<=m;j++) if(!b[i][j-1] && b[i][j]) ch++;
		if(ch>1) {printf("-1"); return 0;}
		if(ch==0) cntr++;
	}
	for(int j=1;j<=m;j++)
	{
		int ch=0;
		for(int i=1;i<=n;i++) if(!b[i-1][j] && b[i][j]) ch++;
		if(ch>1) {printf("-1"); return 0;}
		if(ch==0) cntc++;
	}
	if((cntr==0  && cntc!=0) || ((cntr!=0  && cntc==0))) {printf("-1"); return 0;}
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(!vi[i][j] && b[i][j]) {dfs(i,j); res++;}
	cout<<res;
}