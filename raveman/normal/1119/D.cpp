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

int n;
ll s[111111];
int q;
ll a[111111];


int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n)scanf("%I64d",s+i);
	sort(s,s+n);

	vector<pair<ll,ll>> e;
	FOR(i,1,n){
		e.pb(make_pair(s[i]-s[i-1],1e18));
	}

	ll res = 0;
	cin>>q;
	ll l,r;
	REP(i,q){
		scanf("%I64d %I64d",&l,&r);
		ll len = r - l + 1;
		e.pb(make_pair(len,i));
	}

	ll c = n;
	ll prev = 0;
	SORT(e);
	REP(i,e.size()){
		res += (e[i].first - prev) * c;
		prev = e[i].first;

		if(e[i].second>q)c--;
		else a[e[i].second]=res;
	}
	
	REP(i,q)printf("%I64d ",a[i]);
	puts("");
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}