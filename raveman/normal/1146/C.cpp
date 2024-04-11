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


int main(){	
#ifdef LocalHost
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		int n;
		cin>>n;
		int res=0;
		REP(i,9){
			vi k1,k2;
			REP(j,n)if(j&(1<<i))k1.pb(j);
			else k2.pb(j);
			if(k1.size()>0 && k2.size()>0){
				cout<<k1.size()<<' '<<k2.size();
				REP(j,k1.size())printf(" %d",k1[j]+1);
				REP(j,k2.size())printf(" %d",k2[j]+1);
				puts("");

				fflush(stdout);
				int x;
				cin>>x;
				res=max(res,x);
			}
		}
		cout<<"-1 "<<res<<endl;
		fflush(stdout);
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}