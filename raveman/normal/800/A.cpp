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

int n,p;
int a[111111];
int b[111111];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>p;
	ll sa=0;
	REP(i,n)scanf("%d %d",a+i,b+i),sa+=a[i];
	if(sa<=p){
		puts("-1");
		return 0;
	}

	double from = 0, to = 1e30;
	double best = 0;
	REP(i,200){
		double m = (from+to)/2;
		double need = 0;
		REP(j,n){
			double x = a[j] * m - b[j];
			if (x<0)x=0;
			need += x;
		}
		//cout<<i<<" "<<m<<": "<<need<<' '<<p*m<<" " <<(need<=p*m)<<endl;
		if(need <= p * m) best=m,from=m;
		else to=m;
	}
	printf("%.10lf\n",best);
		

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}