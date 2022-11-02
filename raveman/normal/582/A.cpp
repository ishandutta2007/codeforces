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

int gcd(int a,int b){
	while(a&&b)if(a>b)a%=b;else b%=a;return a+b;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	map<int,int> s;
	int n;
	cin>>n;
	REP(i,n*n){
		int x;
		scanf("%d",&x);
		s[x]++;
	}
	vi v;
	REP(i,n){
		map<int,int>::iterator it = s.end();
		--it;
		int val = it->first;
		s[val]--;
		if(s[val]==0)s.erase(val);
		REP(j,v.size()){
			int g =gcd(val,v[j]);
			s[g]--;
			s[g]--;
			if(s[g]==0)s.erase(g);
		}
		v.pb(val);		
	}

	REP(i,n){
		if(i)printf(" ");
		printf("%d",v[i]);
	}
	puts("");



#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}