//#pragma comment(linker, "/STACK:60777216")  

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
typedef pair<ll,ll> pl;
typedef pair<int,pl>	p3l;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int d[101][100*100+1];
int a[111];
int b[111];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	CL(d,-1);
	int n;
	cin>>n;
	REP(i,n)cin>>a[i]>>b[i];
	d[0][0]=0;
	int v;
	REP(i,n)for(int j=n;j>=0;j--)REP(k,i*100+1)if((v=d[j][k])>=0){
		//t1
		if(d[j+1][k+b[i]]==-1 || d[j+1][k+b[i]]<v+a[i]-b[i])d[j+1][k+b[i]]=v+a[i]-b[i];
	}
	int ts = 0;
	REP(i,n)ts+=b[i];
	REP(i,n){
		double res = 0;
		REP(j,100*100+1)if(d[i+1][j]!=-1)res=max(res,j+min(d[i+1][j]*2,ts-j)/2.);
		printf("%.10lf ",res);
	}
	puts("");

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}