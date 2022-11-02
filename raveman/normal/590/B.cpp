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

int x,y;
int v,t;
int vx,vy;
int wx,wy;

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	
	int xxx,yyy;
	cin>>xxx>>yyy>>x>>y;
	x-=xxx;y-=yyy;
	cin>>v>>t;
	cin>>vx>>vy;
	cin>>wx>>wy;

	double a = 0, b = 1e10;
	double best = 1e10;
	REP(it,200){
		double s = (a+b)/2;
		
		double nx = 0;
		double ny = 0;

		nx += min(t+0.,s) * vx;
		ny += min(t+0.,s) * vy;

		if(s>t){
			nx += (s-t)*wx;
			ny += (s-t)*wy;
		}

		double d = hypot(nx-x,ny-y);
		if (d < s * v) best = s,b=s;
		else a=s;
	}

	printf("%.10lf\n",best);


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}