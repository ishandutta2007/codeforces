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
#include<bitset>
#include<fstream>
#include<queue>
#include<stack>

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
int    d[3][1111][1111];
int a[3][3];

void solve(int c){
	queue<pii> q;
	REP(i,n)REP(j,m)if(s[i][j]-'1'==c){
		d[c][i][j]=0;
		q.push(pii(i,j));
	}
	int x,y;
	while(!q.empty()){
		x=q.front().first;
		y=q.front().second;
		q.pop();

		FOR(dx,-1,2)FOR(dy,-1,2)if(abs(dx)+abs(dy)==1){
			int nx = x + dx;
			int ny = y + dy;
			if(nx>=0 && nx<n && ny>=0 && ny<m && s[nx][ny]!='#' && d[c][nx][ny]==-1){
				d[c][nx][ny]=d[c][x][y]+1;
				q.push(pii(nx,ny));
				if(isdigit(s[nx][ny])){
					a[c][s[nx][ny]-'1']=min(a[c][s[nx][ny]-'1']==-1?10000000:a[c][s[nx][ny]-'1'],d[c][x][y]+1);
				}
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

	CL(d,-1);
	CL(a,-1);

	solve(0);
	solve(1);
	solve(2);


	int res = 1e9;
	if(a[0][1]!=-1 && a[0][2]!=-1)res=min(res,a[0][1]+a[0][2]);
	if(a[1][0]!=-1 && a[1][2]!=-1)res=min(res,a[1][0]+a[1][2]);
	if(a[2][0]!=-1 && a[2][1]!=-1)res=min(res,a[2][0]+a[2][1]);
	REP(i,n)REP(j,m)if(s[i][j]!='#' && d[0][i][j]!=-1 && d[1][i][j]!=-1 && d[2][i][j]!=-1)res=min(res,d[0][i][j]+d[1][i][j]+d[2][i][j]);

	if(res==1e9)cout<<-1<<endl;
	else cout<<res-2<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}