//#pragma comment(linker, "/STACK:60777216")  

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
#define CL(a,b)				memset(a,b,sizeof a)
#define pb				push_back

double maxi[111111];
double mini[111111];
double a[111111];
double b[111111];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n;
	cin>>n;
	REP(i,n)scanf("%lf",&maxi[i]);
	REP(i,n)scanf("%lf",&mini[i]);

	double ak = 0;
	double bk = 0;
	for(int i=n-1;i>=0;i--){
		double sum = maxi[i] + mini[i];
		double B = -(bk-ak+sum);
		double C = mini[i] - sum * ak;
		double D = B*B - 4 * C;
		D = max(D,0.);
		D = sqrt(D);

		a[i] = (-B+D)/2;
		b[i] = sum - a[i];
		a[i]=max(a[i],0.);
		b[i]=max(b[i],0.);
		ak += a[i];
		bk += b[i];
	}

	REP(i,n){
		if(i)printf(" ");
		printf("%.10lf",a[i]);
	}
	puts("");
	
	REP(i,n){
		if(i)printf(" ");
		printf("%.10lf",b[i]);
	}
	puts("");

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}