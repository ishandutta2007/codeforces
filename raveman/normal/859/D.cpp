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
int a[111][111];

bool   c[111][111];
double p[111][111][111];
double r[111][111][111];


double solve(int from,int to,int winner){
	if(from+1==to) {
		p[from][to][from] = a[from][to]/100.;
		p[from][to][to] = a[to][from]/100.;
		return a[winner][from+to-winner]/100.;
	}
	if(r[from][to][winner]>=0)return r[from][to][winner];
	
	int middle = (from+to)/2;

	if(!c[from][to]){
		c[from][to]=1;
		FOR(i,from,middle+1) solve(from,middle,i);
		FOR(i,middle+1,to+1) solve(middle+1,to,i);


	//	cout<<from<<' '<<to<<' '<<winner<<" = ";
		FOR(i,from,to+1){
			if(i<=middle){
				FOR(j,middle+1,to+1)p[from][to][i] += p[from][middle][i] * p[middle+1][to][j] * a[i][j]/100.;
			}else{
				FOR(j,from,middle+1)p[from][to][i] += p[middle+1][to][i] * p[from][middle][j] * a[i][j]/100.;
			}
		//	cout<<p[from][to][i]<<' ';
		}
	//	puts("");
	}

	//cout<<from<<' '<<to<<' '<<winner<<endl;

	//REP(i,mi

	double b = 0;

	if(winner<=middle){
		double t = 0;
		FOR(i,middle+1,to+1){
			b+=p[from][middle][winner]*p[middle+1][to][i]*a[winner][i]/100.*(to-from+1)/2;
			t=max(t,solve(middle+1,to,i));
		}
		b+=solve(from,middle,winner);
		b += t;
	}else{
		double t = 0;
		FOR(i,from,middle+1){
			b+=p[from][middle][i]*p[middle+1][to][winner]*a[winner][i]/100.*(to-from+1)/2;
			t=max(t,solve(from,middle,i));
		}
		b+=solve(middle+1,to,winner);
		b += t;
	}

	//cout<<" = " << b<<endl;
	
	return r[from][to][winner] = b;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,1<<n)REP(j,1<<n)cin>>a[i][j];

	double res = 0;
	REP(i,1<<n)REP(j,1<<n)REP(k,1<<n)r[i][j][k]=-1;
	REP(i,1<<n)res=max(res, solve(0,(1<<n)-1,i));

	printf("%.10lf\n",res);


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}