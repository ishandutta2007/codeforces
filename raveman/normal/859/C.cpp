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

map<vi,pii> r;

pii solve(vi v){
	if(v.empty()) return pii(0,0);
	if(r.count(v)) return r[v];

	pii w(0,0);

	vi tv(v);
	int z = tv.back();
	tv.pop_back();

	// largest
	pii q = solve(tv);
	w.first = z + q.second;
	w.second = q.first;

	// smallest
	pii q2 = solve(tv);
	if(w.first<q2.first){
		w.first=q2.first;
		w.second=q2.second+z;
	}

	return r[v]=w;

}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n;
	cin>>n;
	vi v(n);
	REP(i,n)cin>>v[i];
	reverse(v.begin(),v.end());
	pii t = solve(v);
	cout<<t.second<<' '<<t.first<<endl;


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}