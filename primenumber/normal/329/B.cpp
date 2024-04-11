#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <numeric>
#include <utility>

#define rep(i,n)	for(int i = 0;i < n;i++)
#define rep2(i,n)	for(int i = 1;i <= n;i++)
#define each(i,x)	for(auto & i : x)

using namespace std;

const int INF=100000000;

vector<vector<int>> search(vector<vector<char>> & ary,int c,int r)
{
	int ex,ey;
	rep(i,r)rep(j,c)if(ary[i][j]=='E'){ex=j;ey=i;}
	vector<vector<int>> tb(r,vector<int>(c,INF));
	tb[ey][ex] = 0;
	queue<pair<int,int>> q;
	q.push(make_pair(ex,ey));
	while(!q.empty())
	{
		auto p = q.front();
		q.pop();
		int dx[]={1,0,-1,0};
		int dy[]={0,1,0,-1};
		int x=p.first;
		int y=p.second;
		rep(i,4)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx<0||nx>=c||ny<0||ny>=r)
				continue;
			else if(ary[ny][nx] == 'T')
				continue;
			else if(tb[ny][nx] > tb[y][x]+1)
			{
				tb[ny][nx] = tb[y][x]+1;
				q.push(make_pair(nx,ny));
			}
		}
	}
	return tb;
}

int main()
{
	int c,r;
	cin>>r>>c;
	vector<vector<char>> ary(r,vector<char>(c));
	rep(i,r)rep(j,c)cin>>ary[i][j];
	auto tb = search(ary,c,r);
	int sum = 0;
	int pdis;
	rep(i,r)rep(j,c)if(ary[i][j]=='S'){pdis=tb[i][j];break;}
	rep(i,r)rep(j,c){
		if(ary[i][j]>'0'&&ary[i][j]<='9' && tb[i][j] <= pdis)
		{
			sum+=ary[i][j]-'0';
		}
	}
	cout<<sum<<endl;
	return 0;
}