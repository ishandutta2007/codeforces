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
int v[2222];
vi  e[2222];
bool u[2222];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif


	cin>>n>>m;
	REP(i,n)cin>>v[i];
	REP(i,m){
		int x,y;
		scanf("%d %d",&x,&y);x--,y--;
		e[x].pb(y);
		e[y].pb(x);
	}
	vector<pii> t;
	REP(i,n)t.pb(pii(v[i],i));
	SORT(t);
	reverse(t.begin(),t.end());
	ll res = 0;
	REP(i,n){
		REP(j,e[t[i].second].size()){
			int other = e[t[i].second][j];
			if(u[other])continue;
			res += v[other];
		}
		u[t[i].second]=true;
	}
	cout<<res<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}