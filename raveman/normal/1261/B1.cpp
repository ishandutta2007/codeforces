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

int n,m;
int a[222222];
int k[222222];
int pos[222222];
int w[222222];

vi z[222222];

int s[1<<20];

void addOne(int pos){
	pos += (1<<19);
	while(pos){
		s[pos]++;
		pos>>=1;
	}
}
int solve(int pos){
	int start = 1;
	while(start<(1<<19)){
		if(s[start*2]>=pos)start*=2;
		else{
			pos-=s[start*2];
			start=start*2+1;
		}
	}
	return start-(1<<19);
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n)scanf("%d",a+i);
	cin>>m;
	REP(i,m)scanf("%d %d",k+i,pos+i),z[k[i]].pb(i);

	vector<pii> v;
	REP(i,n)v.pb(pii(a[i],-i));
	SORT(v);
	reverse(v.begin(),v.end());

	REP(i,v.size()){
		int p = -v[i].second;
		addOne(p);

		REP(j,z[i+1].size()){
			int id = z[i+1][j];
			int pp = pos[id];
			w[id] = a[solve(pp)];
		}
	}
	REP(i,m)printf("%d\n",w[i]);

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}