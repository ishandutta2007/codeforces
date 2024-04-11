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

int n;
double x[1111],y[1111];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n)cin>>x[i]>>y[i];
	double best = 1e100;

	REP(i,n){
		double x1 = x[i];
		double y1 = y[i];
		double x2 = x[(i+1)%n];
		double y2 = y[(i+1)%n];
		double x3 = x[(i+n-1)%n];
		double y3 = y[(i+n-1)%n];

		double d = hypot(x2-x3,y2-y3);
		double s = (x2-x1)*(y3-y1)-(x3-x1)*(y2-y1);
		if(s<0)s=-s;

		best=min(best,s/2/d);
		best=min(best,hypot(x2-x1,y2-y1)/2);
	}

	printf("%.10lf\n",best);
		

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}