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

int n,x;
int t[2222],h[2222],m[2222];

int find_best(vector<pii>& v,int h){
	int best = -1;
	REP(i,v.size()) if(v[i].first<=h){
		if(best==-1 || v[best].second<v[i].second) best=i;
	}
	return best;
}

int solve(vector<pii> v1, vector<pii> v2){
	int cx = x;
	int num = 0;
	while(1){
		if(v1.size()==0) break;
		int best = find_best(v1, cx);
		if(best==-1) break;
		num++;
		cx += v1[best].second;
		v1.erase(v1.begin()+best);
		if(v2.size()==0) break;
		best = find_best(v2, cx);
		if(best==-1) break;
		num++;
		cx += v2[best].second;
		v2.erase(v2.begin()+best);
	}
	return num;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>x;
	vector<pii> v1,v2;
	REP(i,n){
		cin>>t[i]>>h[i]>>m[i];
		if(t[i]==0) v1.pb(pii(h[i],m[i]));
		else v2.pb(pii(h[i],m[i]));
	}
	cout<<max(solve(v1,v2),solve(v2,v1))<<endl;


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}