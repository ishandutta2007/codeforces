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

vi w[3333];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

    int n,m;
    ll p[3333],c[3333];
    cin>>n>>m;
    REP(i,n){
        cin>>p[i]>>c[i];
        w[p[i]].pb(c[i]);
        
    }
    REP(i,m+1)SORT(w[i]);
	ll best = 1e18;
	for(int i = max((int)w[1].size(),1); i <= n; i++){
	    ll cost = 0;
	    int cnt = w[1].size();
	    vi rest;
	    FOR(j,2,m+1){
	        if(w[j].size() >= i){
	            REP(k,w[j].size()-i+1)cost += w[j][k],cnt++;
	            FOR(k,w[j].size()-i+1,w[j].size()) rest.pb(w[j][k]);
	        }else{
	            REP(k,w[j].size())rest.pb(w[j][k]);
	        }
	    }
	    if(cnt>i) continue;
	    if(cnt<i){
	        SORT(rest);
	        REP(k,i-cnt) cost += rest[k];
	    }
	    best=min(best,cost);
	}
	
	cout<<best<<endl;

	
#ifdef LocalHost
	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}