#include <algorithm>
#include <bitset>
#include <cassert>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define FOR(i,a,b) for(int i=a;i<(b);i++)
#define FORN(i,b) for(int i=0;i<(b);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<pair<int,int> > vii;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

bool vis[1024][1024][4][4];
char b[1024][1024];
int n,m;
int xs,ys,xe,ye;

bool valid(int x, int y){
	return x>=0&&x<n&&y>=0&&y<m&&b[x][y]!='*';
}

void dfs(int x, int y, int d, int k){
	if(vis[x][y][d][k])return;
	//printf("%d %d %d %d %d %d\n",x,y,d,k,xe,ye);
	vis[x][y][d][k]=1;
	if(x==xe&&y==ye){puts("YES");exit(0);}
	int xx=x+dx[d],yy=y+dy[d];
	if(valid(xx,yy))dfs(xx,yy,d,k);
	if(k){
		FOR(i,-1,2){
			if(!i)continue;
			int dd=(d+4+i)%4;
			xx=x+dx[dd];yy=y+dy[dd];
			if(valid(xx,yy))dfs(xx,yy,dd,k-1);
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	FORN(i,n)scanf("%s",b[i]);
	FORN(i,n)FORN(j,m){
		if(b[i][j]=='S')xs=i,ys=j;
		else if(b[i][j]=='T')xe=i,ye=j;
	}
	FORN(i,4)dfs(xs,ys,i,2);
	puts("NO");
	return 0;
}

/*
  _____   ____  _____   ____  _   _  _____  ____  _   _
 |  __ \ / __ \|  __ \ / __ \| \ | |/ ____|/ __ \| \ | |
 | |__) | |  | | |__) | |  | |  \| | |  __| |  | |  \| |
 |  ___/| |  | |  _  /| |  | | . ` | | |_ | |  | | . ` |
 | |    | |__| | | \ \| |__| | |\  | |__| | |__| | |\  |
 |_|     \____/|_|  \_\\____/|_| \_|\_____|\____/|_| \_|

*/