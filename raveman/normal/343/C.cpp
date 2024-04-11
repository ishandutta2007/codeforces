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
vector<ll> v1,v2;

bool good(ll s){
	int start = 0;
	REP(i,n){
		if(start >= v2.size()) return true;
		if(v2[start] >= v1[i]){
			while(start<v2.size() && v2[start]<=v1[i]+s) start++;
		}else{
			ll d = v1[i]-v2[start];
			if(d>s) continue;
			ll r1 = (s-d)/2;
			ll r2 = (s-2*d);
			ll r = max(r1,r2);
			while(start<v2.size() && v2[start]<=v1[i]+r)start++;
		}
	}
	return start >= v2.size();
}
	
int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	v1.resize(n);
	v2.resize(m);
	REP(i,n)cin>>v1[i];
	REP(i,m)cin>>v2[i];
	ll a = 0, b = 1e12 ,best=1e12;
	while(a<=b){
		ll s= (a+b)/2;
		if(good(s))best=s,b=s-1;
		else a=s+1;
	}
	cout<<best<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}