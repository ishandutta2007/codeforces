#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push
#define int64 long long
#define ld long double  
#define setval(a,v) memset(a,v,sizeof(a))
using namespace std;

bool g[211][211];

void go(int& x,int& y,char c){
	if (c=='L')
		y--;
	else if (c=='R')
		y++;
	else if (c=='U')
		x--;
	else if (c=='D')
		x++;
	else assert(false);
}

const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
int d[211][211];


int bfs(int ex,int ey){
	queue<int> qx;
	queue<int> qy;
	qx.pb(105);
	qy.pb(105);
	setval(d,1);
	d[105][105]=0;
	for (;!qx.empty();){
		int x=qx.front();
		int y=qy.front();
		qx.pop();qy.pop();
		for (int i=0;i<4;i++)
			if (g[x+dx[i]][y+dy[i]] && d[x+dx[i]][y+dy[i]]>d[x][y]+1)
				{
					d[x+dx[i]][y+dy[i]]=d[x][y]+1;
					qx.push(x+dx[i]);
					qy.push(y+dy[i]);
				}
	}
	return d[ex][ey];
}


int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  int x=105;
  int y=105;
  g[x][y]=true;
  string s;
  getline(cin,s);
  for (int i=0;i<s.size();i++){
  	go(x,y,s[i]);
  	g[x][y]=true;
  }
  if (s.length()==bfs(x,y))
  	printf("OK\n");
  else
  	printf("BUG\n");
  return 0;
}