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

int n;
string s[22];
int id[22][22];
vector<pii> v[44];

map<int,int> r[44];

int go(int pos,int mask){
	if(pos==n+n-2) return 0;
	if(r[pos].count(mask)) return r[pos][mask];
	vi t;
	REP(i,20)if(mask&(1<<i))t.pb(i);
	int m[26];
	CL(m,0);
	REP(i,t.size()){
		int px = v[pos][t[i]].first;
		int py = v[pos][t[i]].second;
		if(px+1<n)m[s[px+1][py]-'a']|=(1<<id[px+1][py]);
		if(py+1<n)m[s[px][py+1]-'a']|=(1<<id[px][py+1]);
	}
	int best = (pos%2==0 ? 100 : -100);
	REP(i,26)if(m[i]){
		int diff = go(pos+1,m[i]);
		if(i==0) diff++;
		if(i==1) diff--;
		if(pos%2==0) best=min(best,diff);
		else best=max(best,diff);
	}
	return r[pos][mask]=best;
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n) cin>>s[i];
	REP(i,n)REP(j,n){
		id[i][j]=v[i+j].size();
		v[i+j].pb(pii(i,j));		
	}
	int d = go(0,1)+(s[0][0]=='a'?1:(s[0][0]=='b'?-1:0));
	//cout<<d<<endl;

	if(d==0) puts("DRAW");
	else if(d>0) puts("FIRST");
	else puts("SECOND");

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}