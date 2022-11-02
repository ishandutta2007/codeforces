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
#define CL(a,b)				memset(a,b,sizeof a)
#define pb				push_back

int n,k,s,t;
int c[222222];
int v[222222];
int x[222222];

bool good(ll V){
	ll tt = 0;
	FOR(i,1,k){
		int d = x[i] - x[i-1];
		if(d>V) return 0;
		int diff = V - d;

		tt += 2*d;
		tt -= min(d, diff);
	}
	return tt<=t;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>k>>s>>t;
	REP(i,n)scanf("%d %d",c+i,v+i);
	REP(i,k)scanf("%d",x+i+1);
	k++;
	x[k]=s;
	k++;
	sort(x,x+k);

	ll best=-1;
	ll from = 0, to = s;
	while(from<=to){
		ll m = (from + to)/2;
		if(good(m)) best=m,to=m-1;
		else from=m+1;
	}
	if(best==-1){puts("-1");return 0;}
	int res = 2e9;
	REP(i,n)if(v[i]>=best)res=min(res,c[i]);
	if( res==2e9)puts("-1");
	else cout<<res<<endl;
	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}