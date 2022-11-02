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

int k;
vector<pii> v[222222];
ll total1;
ll total2;

int dfs(int ver,int par=-1){
	int num=1;
	REP(i,v[ver].size()){
		if(v[ver][i].first==par)continue;
		int t = dfs(v[ver][i].first,ver);
		if(t%2)total1+=v[ver][i].second;

		int t2 = 2*k-t;

		total2+=ll(v[ver][i].second)*min(t,t2);
		num += t;
	}
	return num;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		cin>>k;
		REP(i,2*k)v[i].clear();
		REP(i,2*k-1){
			int x,y,z;
			scanf("%d %d %d",&x,&y,&z);
			x--,y--;
			v[x].pb(pii(y,z));
			v[y].pb(pii(x,z));
		}
		total1=0;total2=0;
		dfs(0);
		cout<<total1<<' '<<total2<<endl;
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}