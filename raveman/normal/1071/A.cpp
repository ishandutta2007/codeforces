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

set<int> t;

void solve(int n,int a){
	vi v;
	for(int i=n;i>=1;i--)if(a>=i){
		a-=i;
		v.pb(i);
		t.insert(i);
	}
	cout<<v.size()<<endl;
	SORT(v);
	REP(i,v.size()) cout<<v[i]<<' ';
	puts("");
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int a,b;
	cin>>a>>b;
	int s = a + b;
	int n = 0;
	int sum = 0;
	while(sum+n+1<=s){
		n++;
		sum+=n;
	}

	solve(n,a);

	cout<<n-t.size()<<endl;
	REP(i,n){
		if(!t.count(i+1)) cout<<i+1<<' ';
	}
	puts("");

	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}