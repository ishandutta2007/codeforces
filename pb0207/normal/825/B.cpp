#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4e5+1;

char s[151][151];

void dfs1(int x,int y)
{
	for(int i=x;i<=x+4;++i)
	if(s[i][y]!='X')return;
	cout<<"YES";exit(0);
}
void dfs2(int x,int y)
{
	for(int i=y;i<=y+4;++i)
	if(s[x][i]!='X')return;
	cout<<"YES";exit(0);
}
void dfs3(int x,int y)
{
	for(int i=x,t=y;i<=x+4;++i,++t)
	if(s[i][t]!='X')return;
	cout<<"YES";exit(0);
}
void dfs4(int x,int y)
{
	for(int i=x,t=y;i<=x+4;++i,--t)
	if(s[i][t]!='X')return;
	cout<<"YES";exit(0);
}
void solve()
{
	for(int i=0;i<10;++i)
	for(int t=0;t<10;++t)
	{
		dfs1(i,t);dfs2(i,t);
		dfs3(i,t);dfs4(i,t);
	}
}
/*
xxxx......
........X.
.......X..
......X...
..........
x...X.....
x.........
x.........
x.........
..........
*/
int main()
{
	for(int i=0;i<10;++i)scanf("%s",s+i);
	bool flag=0;
	for(int i=0;i<10;++i)
	{
		for(int t=0;t<10;++t)
		{
			if(s[i][t]=='.')
			{
				s[i][t]='X';
				solve();
				s[i][t]='.';
			}
		}
	}
	cout<<"NO";
}