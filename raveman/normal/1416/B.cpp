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

int n;
int a[11111];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){

		cin>>n;
		REP(i,n)cin>>a[i];
		vector<p3> r;
		FOR(i,1,n){
			int need = ((i+1)-(a[i]%(i+1)))%(i+1);
			if(need>0){
				r.pb(p3(1,pii(i+1,need)));
			}
			r.pb(p3(i+1,pii(1,(a[i]+need)/(i+1))));
			a[0]+=a[i];
			a[i]=0;
		}
		if(a[0]%n)puts("-1");
		else{
			FOR(i,1,n){
				r.pb(p3(1,pii(i+1,a[0]/n)));
			}

			cout<<r.size()<<endl;
			REP(i,r.size()){
				printf("%d %d %d\n",r[i].first,r[i].second.first,r[i].second.second);
			}
		}
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}