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

int n,m,k;
int x[222222],y[222222];

vi v[222222];
int nm[222222];
set<pii> p;

int res[222222];

int solve(){
	while(!p.empty() && p.begin()->first<k){
		int ver = p.begin()->second;
		p.erase(p.begin());

		REP(i,v[ver].size()){
			if (x[v[ver][i]]==-1) continue;
			int other = x[v[ver][i]]+y[v[ver][i]]-ver;

			p.erase(pii(nm[other],other));
			nm[other]--;
			p.insert(pii(nm[other],other));
			x[v[ver][i]]=-1;
			y[v[ver][i]]=-1;
		}
	}
	return p.size();
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m>>k;
	REP(i,m){
		scanf("%d %d",x+i,y+i);
		x[i]--,y[i]--;
		nm[x[i]]++;
		nm[y[i]]++;
		v[x[i]].pb(i);
		v[y[i]].pb(i);
	}

	REP(i,n)p.insert(pii(nm[i],i));
	for(int i=m-1;i>=0;i--){
		res[i]=solve();
		int t1 = x[i];
		int t2 = y[i];
		if(t1==-1 || t2==-1) continue;
		x[i]=y[i]=-1;
		if(p.count(pii(nm[t1],t1)) && p.count(pii(nm[t2],t2))){
			p.erase(pii(nm[t1],t1));
			p.erase(pii(nm[t2],t2));
			nm[t1]--;
			nm[t2]--;
			p.insert(pii(nm[t1],t1));
			p.insert(pii(nm[t2],t2));
		}
	}


	REP(i,m)printf("%d\n",res[i]);
	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}