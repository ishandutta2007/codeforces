#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 512
int read(){
	int x=0,t=1,c;
	while(!isdigit(c=getchar()))if(c=='-')t=-1;
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	return x*t;
}
int n;
int query(int x0,int y0,int x1,int y1)
{
	printf("? %d %d %d %d\n",x0,y0,x1,y1);
	fflush(stdout);
	char res[8];
	scanf("%s",res);
	return res[0]=='Y'?1:0;
}
bool vis[M][M];
int direct[M][M];
char ans[M<<1];
int main(){
	n=read();
	int x=1,y=1,res;
	for(int i=0;i<n-1;i++)
	{
		if(query(x+1,y,n,n)) direct[x][y]=1,x++;
		else direct[x][y]=2,y++;
	}
	x=n;y=n;
	for(int i=0;i<n-1;i++)
	{
		if(query(1,1,x,y-1))y--,direct[x][y]=2;
		else x--,direct[x][y]=1;
	}
	x=1,y=1;int p=0;
	while(x+y<2*n)
	{
		if(direct[x][y]==1)ans[p++]='D',x++;
		else ans[p++]='R',y++;
	}
	printf("! %s\n",ans);
	fflush(stdout);
	return 0;
}