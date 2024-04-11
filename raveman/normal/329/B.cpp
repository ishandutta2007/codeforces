#pragma comment(linker, "/STACK:60777216")  

#include <cassert>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstdlib>
#include<memory.h>
#include<ctime>

using namespace std;


typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<ld,ld>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int n,m;
string s[1111];
int d[1111][1111];

void bfs(int sx,int sy){
	CL(d,-1);
	queue<pii> q;
	q.push(pii(sx,sy));
	d[sx][sy]=0;
	while(!q.empty()){
		sx = q.front().first;
		sy = q.front().second;
		q.pop();
		FOR(dx,-1,2)FOR(dy,-1,2)if(abs(dx)+abs(dy)==1){
			int x = sx + dx;
			int y = sy + dy;
			if(x>=0 && x<n && y>=0 && y<m && s[x][y]!='T' && d[x][y]==-1){
				d[x][y]=d[sx][sy]+1;
				q.push(pii(x,y));
			}
		}
	}
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,n)cin>>s[i];
	REP(i,n)REP(j,m)if(s[i][j]=='E')bfs(i,j);
	int dist = 0;
	REP(i,n)REP(j,m)if(s[i][j]=='S')dist = d[i][j];
	int res = 0;
	REP(i,n)REP(j,m)if(isdigit(s[i][j]) && d[i][j]!=-1 && d[i][j]<=dist)res+=s[i][j]-'0';
	cout<<res<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}