#include <iostream>
#include <string>
using namespace std;

int N,M;
string A[500];
bool reach[500][500];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void dfs(int x,int y)
{
	reach[x][y] = 1;
	for(int d=0;d<4;d++)
	{
		if(((x+dx[d])>=0)&&((y+dy[d])>=0)&&((x+dx[d])<N)&&((y+dy[d])<M))
			if(A[x+dx[d]][y+dy[d]]=='.')
				if(!reach[x+dx[d]][y+dy[d]])
					dfs(x+dx[d],y+dy[d]);
	}
}

int crackNei(int x,int y)
{
	int c = 0;
	for(int d=0;d<4;d++)
	{
		if(((x+dx[d])>=0)&&((y+dy[d])>=0)&&((x+dx[d])<N)&&((y+dy[d])<M))
			if(A[x+dx[d]][y+dy[d]]=='.')
				c++;
	}
	return c;
}

int main()
{
	ios::sync_with_stdio(0);
	int sx,sy,ex,ey;
	cin >> N >> M;
	for(int i=0;i<N;i++)
	{
		cin >> A[i];
		for(int j=0;j<M;j++)
			reach[i][j] = 0;
	}
	cin >> sx >> sy >> ex >> ey;
	sx--,sy--,ex--,ey--;
	A[sx][sy] = '.';
	if((sx==ex)&&(sy==ey))
	{
		if(crackNei(ex,ey)>0)
			cout << "YES\n";
		else
			cout << "NO\n";
		return 0;
	}
	bool endCracked = 0;
	if(A[ex][ey]=='X')
	{
		A[ex][ey] = '.';
		endCracked = 1;
	}
	dfs(sx,sy);
	if((!reach[ex][ey])||((!endCracked)&&(crackNei(ex,ey)<=1)))
		cout << "NO\n";
	else
		cout << "YES\n";
	return 0;
}