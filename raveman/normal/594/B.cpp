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
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

const double pi = acos(-1.);

int n,r,v;

void solve(double d){
	double D = d / double(r);
	double ans = 1e100;
	double a = 0, b = D+1;
	REP(i,100){
		double s = (a+b)/2;
		double diff = D - s;
		if(diff<0) ans=min(ans,s),b=s;
		else{
			double s2 = s/2;
			double x = fabs(cos(pi/2-s2))*2;
			if(diff<=x) ans=min(ans,s),b=s;
			else a=s;
		}
	}
	printf("%.10lf\n",ans*r/v);
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>r>>v;
	REP(i,n){
		int s,f;
		scanf("%d %d",&s,&f);
		int d = f - s;

		solve(d);
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}