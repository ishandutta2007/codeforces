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

int p[1<<20];

pii solve(int x){
	vi pr;
	int tx = x;
	while(p[tx]!=0){
		pr.pb(p[tx]);
		int z = p[tx];
		while(tx%z==0)tx/=z;
	}
	if(tx>1)pr.pb(tx);

	
	int from = x+1;
	int to = x;
	REP(i,pr.size()){
		int tfrom = max(pr[i]+1, x - pr[i] + 1);
		from = min(from,tfrom);
	}
	return pii(from,to);
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	for(int i=2;i<=1000000;++i){
		for(int j=2;j*j<=i;j++)if(i%j==0){
			p[i]=j;
			break;
		}
	}

	int x2;
	cin>>x2;

	pii x = solve(x2);

	int bst = 1<<20;
	for(int i=x.first;i<=x.second;++i){
		pii z = solve(i);
		if(z.first>z.second)continue;
		bst=min(bst,z.first);
	}
	cout<<bst<<endl;


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}