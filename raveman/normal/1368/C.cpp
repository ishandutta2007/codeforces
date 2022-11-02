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
typedef pair<int,pii>	p3;
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

ll d[22][1000];
int f[22][1000];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n;
	cin>>n;
	vector<pii> r;
	r.pb(pii(0,0));
	REP(i,n+1){
		r.pb(pii(0+2*i,1+2*i));
		r.pb(pii(0+2*i,2+2*i));
		r.pb(pii(1+2*i,0+2*i));
		r.pb(pii(1+2*i,2+2*i));
		r.pb(pii(2+2*i,0+2*i));
		r.pb(pii(2+2*i,1+2*i));
		r.pb(pii(2+2*i,2+2*i));
	}

	cout<<r.size()<<endl;
	REP(i,r.size()) printf("%d %d\n",r[i].first,r[i].second);

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}