#include <bits/stdc++.h>
#define N 55
using namespace std;
int n,m;
char c[N][N];
bool book[N][N];
void dfs(int pre,int x,int y)
{
	book[x][y]=true;
	if(pre!=1)
	{
		if(c[x][y]==c[x+1][y])
		{
			if(book[x+1][y])
			{
				cout<<"Yes"<<endl;
				exit(0);
			}
			dfs(2,x+1,y);
		}
	}
	if(pre!=2)
	{
		if(c[x][y]==c[x-1][y])
		{
			if(book[x-1][y])
			{
				cout<<"Yes"<<endl;
				exit(0);
			}
			dfs(1,x-1,y);
		}
	}
	if(pre!=3)
	{
		if(c[x][y]==c[x][y+1])
		{
			if(book[x][y+1])
			{
				cout<<"Yes"<<endl;
				exit(0);
			}
			dfs(4,x,y+1);
		}
	}
	if(pre!=4)
	{
		if(c[x][y]==c[x][y-1])
		{
			if(book[x][y-1])
			{
				cout<<"Yes"<<endl;
				exit(0);
			}
			dfs(3,x,y-1);
		}
	}
}
int main(){
	int i,j,k,x,y;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>c[i][j];
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(book[i][j])
			{
				continue;
			}
			dfs(0,i,j);
		}
	}
	cout<<"No"<<endl;
	return 0;
}