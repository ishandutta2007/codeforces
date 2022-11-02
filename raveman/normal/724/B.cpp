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
#define CL(a,b)				memset(a,b,sizeof a)
#define pb				push_back

int a[22][22];
int n,m;
set<pii> t;

bool good(int* a){
	vi p;
	REP(i,m)if(a[i]!=i)p.pb(i);
	if(p.size()==2){
		t.insert(pii(p[0],p[1]));
		t.insert(pii(p[1],p[0]));
	}
	return p.size()<=2;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	
	cin>>n>>m;
	REP(i,n)REP(j,m)cin>>a[i][j],a[i][j]--;
	map<pii,int> w;

	REP(i,n){
		t.clear();
		if(good(a[i])) t.insert(pii(-1,-1));
		REP(k1,m)REP(k2,m){
			swap(a[i][k1],a[i][k2]);
			if(good(a[i])) t.insert(pii(k1,k2));
			swap(a[i][k1],a[i][k2]);
		}

		for(set<pii>::iterator it = t.begin();it!=t.end();it++)w[*it]++;
	}

	for(map<pii,int>::iterator it = w.begin();it!=w.end();it++){
		if(it->second==n) {puts("YES");return 0;}
	}
	puts("NO");

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}