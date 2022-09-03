#include <map>
#include <iostream>
#include <string>
using namespace std;
map<string,string> ans;
bool win(string &grid,char player)
{
	for(int i=0;i<3;i++)
	{
		if(grid[i*3]==player&&grid[i*3+1]==player&&grid[i*3+2]==player)
			return true;
		if(grid[i]==player&&grid[i+3]==player&&grid[i+6]==player)
			return true;
	}
	if(grid[2]==player&&grid[4]==player&&grid[6]==player)
		return true;
	if(grid[0]==player&&grid[4]==player&&grid[8]==player)
		return true;
	return false;
}
string grid=".........";
void dfs(int k)
{
	if(win(grid,'X'))
		ans[grid]="the first player won";
	else if(win(grid,'0'))
		ans[grid]="the second player won";
	else if(k==9)
		ans[grid]="draw";
	else
	{
		if(k&1)
			ans[grid]="second";
		else
			ans[grid]="first";
		for(int i=0;i<9;i++)
			if(grid[i]=='.')
			{
				grid[i]=(k&1?'0':'X');
				dfs(k+1);
				grid[i]='.';
			}
	}
}
int main()
{
	dfs(0);
	string a,b;
	cin>>b;
	a+=b;
	cin>>b;
	a+=b;
	cin>>b;
	a+=b;
	if(ans.find(a)==ans.end())
		cout<<"illegal";
	else cout<<ans[a];
	return 0;
}