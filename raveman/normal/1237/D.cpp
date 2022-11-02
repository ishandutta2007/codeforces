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
int a[111111];
set<pii> small,large;
set<pii> small_inv;
int r[111111];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n)scanf("%d",a+i);
	int mn=a[0],MX=a[0];
	REP(i,n)mn=min(mn,a[i]),MX=max(MX,a[i]);
	if(mn*2>=MX){
		REP(i,n)printf("-1 ");
		puts("");
		return 0;
	}
	

	REP(i,n){
		small_inv.insert(pii(a[i],i));
		small.insert(pii(i,a[i]));
		small.insert(pii(i+n,a[i]));
		small.insert(pii(i+n+n,a[i]));
	}
	vector<pii> v;
	REP(i,n)v.pb(pii(a[i],i));
	SORT(v);
	REP(i,n)r[i]=10*n;
	while(!v.empty()){
		int val = v.back().first;
		int ind = v.back().second;
		v.pop_back();

		while(!small_inv.empty()){
			pii smallest = *small_inv.rbegin();
			if(smallest.first*2>=val){
				small_inv.erase(smallest);
				small.erase(pii(smallest.second,smallest.first));
				small.erase(pii(smallest.second+n,smallest.first));
				small.erase(pii(smallest.second+n+n,smallest.first));
			}else break;
		}

		// find next largest
		set<pii>::iterator it = large.lower_bound(pii(ind,0));
		if(it != large.end()){
			r[ind]=min(r[ind],r[it->first%n]+it->first-ind);
		}
		// find next smallest
		it = small.lower_bound(pii(ind,0));
		if(it != small.end()){
			r[ind]=min(r[ind],it->first-ind);
		}
		

		//
		large.insert(pii(ind,val));
		large.insert(pii(ind+n,val));
		large.insert(pii(ind+n+n,val));
	}

	REP(i,n)printf("%d ",r[i]);
	puts("");

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}