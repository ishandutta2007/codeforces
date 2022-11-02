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

const int mod = 1000000007;

ll stupid(int n,int k){
	ll sum=0;
	REP(i,1<<n)if(i){
		int nm=0;
		REP(j,n)if(i&(1<<j))nm++;
		ll tmp = 1;
		REP(j,k)tmp*=nm;
		sum+=tmp;
	}
	return sum;
}

ll qp(ll c,ll st){
	ll r=1;
	while(st){
		if(st&1)r*=c,r%=mod;
		c*=c,c%=mod;
		st>>=1;
	}
	return r;
}

void add(vector<pl>& p, int pos,ll val){
	int sz = p.size();
	for(int i=sz-1;i>=max(0,sz-2);i--){
		if(p[i].first==pos){
			p[i].second+=val;
			if(p[i].second>=mod)p[i].second-=mod;
			return;
		}
	}
	p.pb(pl(pos,val));
}

ll smart(ll n,ll k){	
	vector<pl> p;
	p.pb(pl(n, 1));

	REP(i,k){
		vector<pl> np;
		REP(j,p.size()){
			if(p[j].first==0) continue;
			ll t = p[j].first*p[j].second%mod;
			add(np,p[j].first,t);
			t=mod-t;
			if(t==mod)t=0;
			add(np,p[j].first-1,t);
		}
		p=np;
	//	cout<<p.size()<<endl;
	}

	ll res = 0;
	REP(i,p.size()){
		res=(res + qp(2,p[i].first)*p[i].second)%mod;
	}
	return res;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	ll n,k;
	cin>>n>>k;

	cout<<smart(n,k)<<endl;


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}