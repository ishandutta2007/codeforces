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
#include<unordered_map>
#include<unordered_set>

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
int r,c;
int x,y;
string s[2222];
pii res[2222][2222];

void go(int x,int y){
	res[x][y]=pii(0,0);

	queue<pii> q1;
	q1.push(pii(x,y));

	while(!q1.empty()){
		vector<pii> p;
		while(!q1.empty()){
			pii curr = q1.front();
			q1.pop();
			x=curr.first;
			y=curr.second;
			//cout<<x<<' '<<y<<": "<<res[x][y].first<<" " <<res[x][y].second<<endl;
			p.pb(curr);
			//up
			if(x>=1 && s[x-1][y]!='*'){
				if(res[x-1][y].first==-1 || res[x-1][y].first+res[x-1][y].second>res[x][y].first+res[x][y].second){
					res[x-1][y]=res[x][y];
					q1.push(pii(x-1,y));
				}
			}
			//down
			if(x+1<n && s[x+1][y]!='*'){
				if(res[x+1][y].first==-1 || res[x+1][y].first+res[x+1][y].second>res[x][y].first+res[x][y].second){
					res[x+1][y]=res[x][y];
					q1.push(pii(x+1,y));
				}
			}
		}
		REP(i,p.size()){
			x=p[i].first;
			y=p[i].second;
			//left
			if(y>=1 && s[x][y-1]!='*'){
				if(res[x][y-1].first==-1 || res[x][y-1].first+res[x][y-1].second>res[x][y].first+res[x][y].second+1){
					res[x][y-1]=res[x][y];
					res[x][y-1].first++;
					q1.push(pii(x,y-1));
				}
			}
			//right
			if(y+1<m && s[x][y+1]!='*'){
				if(res[x][y+1].first==-1 || res[x][y+1].first+res[x][y+1].second>res[x][y].first+res[x][y].second+1){
					res[x][y+1]=res[x][y];
					res[x][y+1].second++;
					q1.push(pii(x,y+1));
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

	cin>>n>>m>>r>>c>>x>>y;r--,c--;
	REP(i,n)cin>>s[i];
	REP(i,n)REP(j,m)res[i][j]=pii(-1,-1);
	go(r,c);
	int a=0;
	REP(i,n)REP(j,m)if(res[i][j].first!=-1 && res[i][j].first<=x && res[i][j].second<=y)a++;
	cout<<a<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}