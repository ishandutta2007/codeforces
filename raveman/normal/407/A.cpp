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

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int a,b;
	cin>>a>>b;
	vector<pii> v1,v2;
	FOR(x1,-1111,1111)FOR(y1,-1111,1111)if(x1&&y1){
		if(x1*x1+y1*y1==a*a)v1.pb(pii(x1,y1));
		if(x1*x1+y1*y1==b*b)v2.pb(pii(x1,y1));
		//if(x1*x1+y1*y1==b*b)cout<<x1<<' '<<y1<<endl;
	}
	
	REP(i,v1.size())REP(j,v2.size()){
		if(v1[i].first==v2[j].first)continue;
		if(v1[i].second==v2[j].second)continue;

		int d = (v1[i].first-v2[j].first)*(v1[i].first-v2[j].first)+(v1[i].second-v2[j].second)*(v1[i].second-v2[j].second);
		//cout<<d<<endl;
		if(d==a*a+b*b){
			cout<<"YES"<<endl;
			puts("0 0");
			printf("%d %d\n",v1[i].first,v1[i].second);
			printf("%d %d\n",v2[j].first,v2[j].second);
			return 0;
		}
	}
	puts("NO");

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}