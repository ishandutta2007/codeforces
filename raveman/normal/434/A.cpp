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

int n,m;
int a[111111];
map<int,vi> v;

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	
	cin>>n>>m;
	REP(i,m) scanf("%d",a+i);

	ll sum = 0;
	REP(i,m-1){
		sum+=abs(a[i]-a[i+1]);
		if(a[i]!=a[i+1]){
			v[a[i]].pb(a[i+1]);
			v[a[i+1]].pb(a[i]);
		}
	}
	ll res = sum;
	for(map<int,vi>::iterator it = v.begin();it!=v.end();it++){
		int x = it->first;
		vi pos = it->second;
		SORT(pos);
		ll diff = 0;
		//cout<<x<<' '<<pos.size()<<endl;
		REP(i,pos.size()) diff-=abs(pos[i]-x);
		int md = pos[pos.size()/2];
		REP(i,pos.size()) diff+=abs(pos[i]-md);

		//cout<<x<<' '<<pos[md]<<endl;
		
		res = min(res, sum + diff);
	}

	cout<<res<<endl;


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}