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

int n,r;
int f[55],s[55],P[55];
double p[55];

double d[51][5555];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>r;
	REP(i,n)cin>>f[i]>>s[i]>>P[i],p[i]=P[i]/100.;
	double res;
	double from = 0, to = 1e10;
	REP(TTT,100){
		//cout<<TTT<<" = "<<res<<endl;

		double best = (from+to)/2;

		REP(i,5001){
			if(i<=r)d[n][i]=0;
			else d[n][i]=best;
		}
		for(int i=n-1;i>=0;i--)REP(j,5001){
			d[i][j] = min(best, p[i] *(f[i]+ (j+f[i]>r?best:d[i+1][j+f[i]])) + (1-p[i])*(s[i]+(j+s[i]>r?best:d[i+1][j+s[i]])));
		}
		if(d[0][0]>=best-1e-10) from=best;
		else res=best,to=best;
	}

	printf("%.10lf\n",res);
	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}