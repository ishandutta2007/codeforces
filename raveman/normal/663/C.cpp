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
#define CL(a,b)				memset(a,b,sizeof a)
#define pb				push_back

int n,m;
vector<pii> v[111111];

int best=-1;
vi solution;

vi p1,p2;
bool good;
int u[111111];
int C;

void dfs(int ver,int col=0){
	if(u[ver]!=-1){
		if(u[ver]==col)return;
		good=0;
		return;
	}
	u[ver]=col;
	if(col)p2.pb(ver);
	else p1.pb(ver);

	REP(i,v[ver].size()){
		dfs(v[ver][i].first,v[ver][i].second^C^col);
	}
}

void go(int color){
	C=color;
	CL(u,-1);
	vi s;
	REP(i,n)if(u[i]==-1){
		p1.clear();p2.clear();
		good=true;
		dfs(i);
		if(!good) return;
		if(p1.size()>p2.size())swap(p1,p2);
		s.insert(s.end(),p1.begin(),p1.end());
	}
	if(best==-1 || best>s.size()){
		best=s.size();
		solution=s;
	}
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,m){
		int x,y;char c;
		scanf("%d %d %c",&x,&y,&c);
		x--,y--;
		v[x].pb(pii(y,c=='R'));
		v[y].pb(pii(x,c=='R'));
	}

	go(0);
	go(1);

	cout<<best<<endl;
	if(best >= 1){
		REP(i,solution.size()){
			if(i)printf(" ");
			printf("%d",solution[i]+1);
		}
		puts("");
	}

#ifdef LocalHost
	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}