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

int n;
int p[2222],c[2222];
int a[2222];
vi  v[2222];

bool shit=0;

vi solve(int ver){
	vi w;
	REP(i,v[ver].size()){
		vi nd = solve(v[ver][i]);
		if(shit)return vi();
		REP(j,nd.size())a[nd[j]]+=w.size();
		REP(j,nd.size())w.pb(nd[j]);
	}
	if(w.size()<c[ver]){
		shit=1;
		return vi();
	}
	a[ver]=c[ver]+1;
	REP(i,w.size())if(a[w[i]]>=a[ver])a[w[i]]++;
	w.pb(ver);
	return w;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n)cin>>p[i]>>c[i],p[i]--;
	int r = 0;
	REP(i,n)if(p[i]==-1)r=i;else v[p[i]].pb(i);
	solve(r);
	if(shit){
		puts("NO");
		return 0;
	}
	puts("YES");
	REP(i,n){
		printf("%d ",a[i]);
	}
	puts("");


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}