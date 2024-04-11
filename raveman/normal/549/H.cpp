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

pdd solve(double a,double b,double c){
	double mn = a*b;
	double mx = a*b;
	mn=min(mn,(a-c)*(b-c));
	mn=min(mn,(a-c)*(b+c));
	mn=min(mn,(a+c)*(b+c));
	mn=min(mn,(a+c)*(b-c));
	mx=max(mx,(a-c)*(b-c));
	mx=max(mx,(a-c)*(b+c));
	mx=max(mx,(a+c)*(b+c));
	mx=max(mx,(a+c)*(b-c));
	return pdd(mn,mx);
}

bool good(pdd x1, pdd x2){
	if(x1.second<x2.first)return false;
	if(x2.second<x1.first)return false;
	return true;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	double a,b,c,d;
	cin>>a>>b>>c>>d;

	//cout<<solve(a,d,1).first<<' '<<solve(a,d,1).second<<endl;
	//cout<<solve(,d,1).first<<' '<<solve(a,d,1).second<<endl;
	//return 0;

	double res = 1e50;
	double from = 0, to = 1e50;
	REP(i,1000){
		double s = (from+to)/2;

		pdd x1 = solve(a,d,s);
		pdd x2 = solve(b,c,s);
		//cout<<good(x1,x2)<<' '<<s<<' '<<from<<' '<<to<<endl;
		if(good(x1,x2)) res=s,to=s;
		else from=s;
	}

	printf("%.10lf\n",res);



#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}