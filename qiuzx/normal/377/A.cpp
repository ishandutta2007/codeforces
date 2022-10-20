#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#define N 510
using namespace std;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}},s=0,n,m,pre=0;
char grid[N][N];
bool book[N][N]={};
void dfs(int x,int y)
{
	int i,j,tx,ty;
	if(pre>=s-1)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(!book[i][j]&&grid[i][j]=='.')
				{
					cout<<"X";
				}
				else
				{
					cout<<grid[i][j];
				}
			}
			cout<<endl;
		}
		exit(0);
	}
	for(i=0;i<4;i++)
	{
		tx=x+dir[i][0];
		ty=y+dir[i][1];
		if(tx<0||tx>=n||ty<0||ty>=m||book[tx][ty]||grid[tx][ty]=='#')
		{
			continue;
		}
		book[tx][ty]=true;
		pre++;
		dfs(tx,ty);
	}
}
int main(){
	int k,i,j,x,y;
	cin>>n>>m>>k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>grid[i][j];
			if(grid[i][j]=='.')
			{
				x=i;
				y=j;
				s++;
			}
		}
	}
	s-=k;
	book[x][y]=1;
 	dfs(x,y);
	return 0;
}