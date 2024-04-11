#pragma comment(linker, "/STACK:60777216")  

#include <cassert>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
#include<cstring>
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
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int n,m,a,b;
vi v[222222];
int u[222222];
int now;
bool cana,canb;
int num;

void dfs(int ver){
	if(u[ver]==now)return;
	//cout<<ver<<endl;
	u[ver]=now;
	num++;
	REP(i,v[ver].size()){
		if(v[ver][i]==a)cana=1;
		else if(v[ver][i]==b)canb=1;
		else dfs(v[ver][i]);
	}
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	string s;
	cin>>tc;
	REP(TC,tc){
		cin>>n>>m>>a>>b;
		a--,b--;
		REP(i,n)v[i].clear();
		REP(i,m){
			int x,y;
			scanf("%d %d",&x,&y);x--,y--;
			v[x].pb(y);
			v[y].pb(x);
		}
		now++;
		int ca = 0;
		int cb = 0;
		REP(i,n)if(i!=a && i!=b && u[i]!=now){
			cana=0;canb=0;num=0;
			dfs(i);
			if(cana && !canb) ca += num;
			if(canb && !cana) cb += num;
			//cout<<cana<<' '<<canb<<' '<<i<<' '<<num<<endl;
		}

		cout<<ll(ca)*cb<<endl;
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}