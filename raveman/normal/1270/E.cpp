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

int x[1111];
int y[1111];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n;
	cin>>n;
	REP(i,n)cin>>x[i]>>y[i];

	vector<ll> t;
	REP(i,n)REP(j,i)t.pb(ll(x[i]-x[j])*(x[i]-x[j])+ll(y[i]-y[j])*(y[i]-y[j]));
	SORT(t);
	ll sb = 1ll<<60;
	REP(i,t.size()){
		REP(j,60)if(t[i]&(1ll<<j))sb=min(sb,1ll<<j);
	}
	vi v;
	v.pb(0);
	FOR(i,1,n){
		ll z = ll(x[0]-x[i])*(x[0]-x[i])+ll(y[0]-y[i])*(y[0]-y[i]);
		if(z&sb){}
		else v.pb(i);
	}

	cout<<v.size()<<endl;
	REP(i,v.size()) cout<<v[i]+1<<' ';
	puts("");
	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}