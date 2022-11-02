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

set<int> s;

pair<ll,ll> solve(ll n){
	ll b=1;
	while(n>=b){
		n-=b;
		b*=4;
	}
	ll bb=b,nn=n;
	ll sh=0;
	b/=4;


	while(b){
		if(n<b){
		
		}else if(n<2*b){
			n -= b;
			sh += 2*b;
		}else if(n<3*b){
			n -= 2 * b;
			sh += 3 * b;
		}else{
			n -= 3 * b;
			sh += b;
		}

	
		b/=4;
	}

	return make_pair(bb+nn,2*bb+sh);
	cout<<bb+nn<<' '<<2*bb+sh<<' '<<((bb+nn)^(2*bb+sh))<<endl;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif


	int tc;
	cin>>tc;
	REP(TC,tc){
		ll n;
		scanf("%lld",&n);
		ll t= ( n-1)/3;
		pair<ll,ll> x = solve(t);
		if(n%3==1)cout<<x.first<<'\n';
		else if(n%3==2) cout<<x.second<<'\n';
		else cout<<(x.first^x.second)<<'\n';
	}
	return 0;

	REP(it,10){
		for(int i=1;;i++)if(!s.count(i)){
			int t = 1;
			while(t*2<=i)t*=2;
			cout<<i<<' ';
			s.insert(i);
			for(int j=i+1;;j++)if(!s.count(j) && !s.count(i^j)){
				cout<<j<<' '<<(i^j)<<endl;
				s.insert(j);
				s.insert(i^j);
				solve(it);
				break;
			}
			break;
		}
	}


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}