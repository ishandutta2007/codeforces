#include<bits/stdc++.h>
int n,m,fx,fy,dx[10111],dy[10111],len;
char s[1111][1111];
bool use[111][111];
bool dfs(int x,int y,int d=0)
{
	if(use[x][y]||s[x][y]=='*')return false;
	use[x][y]=1;
	dx[d]=x;dy[d]=y;
	if(x==fx&&y==fy)
	{
		len=d+1;
		return true;
	}
	if(dfs(x-1,y,d+1))return true;
	if(dfs(x+1,y,d+1))return true;
	if(dfs(x,y-1,d+1))return true;
	if(dfs(x,y+1,d+1))return true;
	return false;
}
bool chx,chy;void get2(int&x,int&y){scanf("%d%d",&x,&y);if(x==fx&&y==fy)exit(0);}
void go(int x,int y)
{
	dfs(x,y);
	int tx,ty;
	for(int i=1;i<len;i++)
	{
		if(dy[i]==dy[i-1]-1)puts(chy?"R":"L");
		else if(dy[i]==dy[i-1]+1)puts(chy?"L":"R");
		else if(dx[i]==dx[i-1]-1)puts(chx?"D":"U");
		else puts(chx?"U":"D");
		fflush(stdout);
		get2(tx,ty);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=0;i<1111;i++)for(int j=0;j<1111;j++)if(i<1||i>n||j<1||j>m)s[i][j]='*';else if(s[i][j]=='F')fx=i,fy=j;
	int cx=1,cy=1;
	if(s[1][2]!='*')
	{
		puts("R");fflush(stdout);
		int tx,ty;get2(tx,ty);
		if(ty==1)
			chy=1;
		else
		{
			puts("L");fflush(stdout);
			get2(tx,ty);
		}
		while(s[2][cy]=='*')
		{
			puts(chy?"L":"R");fflush(stdout);
			get2(tx,ty);cy=ty;
		}
		puts("D");fflush(stdout);
		get2(tx,ty);
		if(tx==1)chx=1;
		else
		{
			puts("U");fflush(stdout);
			get2(tx,ty);
		}
		go(tx,ty);
	}
	else
	{
		int tx,ty;
		puts("D");fflush(stdout);
		get2(tx,ty);
		if(tx==1)chx=1;
		else
		{
			puts("U");fflush(stdout);
			get2(tx,ty);
		}
		while(s[cx][2]=='*')
		{
			puts(chx?"U":"D");fflush(stdout);
			get2(tx,ty);cx=tx;
		}
		puts("R");fflush(stdout);
		get2(tx,ty);
		if(ty==1)
			chy=1;
		else
		{
			puts("L");fflush(stdout);
			get2(tx,ty);
		}
		go(tx,ty);
	}
	return 0;
}