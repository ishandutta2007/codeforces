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

int n,m;
int x[333333];
int y[333333];
ll sum[333333];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	vector<pii> d;
	REP(i,n)scanf("%d %d",x+i,y+i),d.pb(pii(y[i]-x[i], i));

	REP(i,n){
		/*
		min(d, c+delta)
		d==c+delta
		delta = d-c;

		delta >= d-c -> d
			  <  d-c -> c+delta
			  */
	}

	ll rsum = 0;
	ll ndelta = 0;
	REP(i,n) rsum += x[i], ndelta++;

	SORT(d);
	for(int i=0;i<d.size();){
		int j = i;
		
		while(i<d.size() && d[j].first==d[i].first){
			
			rsum -= x[d[i].second];
			ndelta--;

			rsum += y[d[i].second];

			++i;
		}

		FOR(k,j,i){
			//cout<<d[k].second<<' '<<rsum<<' '<<x[d[k].second]<<' '<<n<<' '<<ndelta<<' '<<d[j].first<<endl;
			sum[d[k].second] = rsum + x[d[k].second] * ll(n) + ndelta * d[j].first;
		}
	}

	REP(i,n){
		sum[i]-=x[i];sum[i]-=y[i];
	}
	REP(i,m){
		int l,r;
		scanf("%d %d",&l,&r);
		l--,r--;

		int v = min(x[l]+y[r],x[r]+y[l]);

		sum[l]-=v;
		sum[r]-=v;


	}
	REP(i,n)printf("%lld ",sum[i]);
	puts("");
	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}