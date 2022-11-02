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

int n,m;
int w[1111][1111];

int u[1111][1111];
int now;
vi t;

bool good(int s){
	now++;
	//cout<<s<<endl;
	REP(i,n){
		t.clear();
		REP(j,m)if(w[i][j]>=s)t.pb(j);
		REP(j,t.size()) REP(k,j){
			if(u[t[k]][t[j]]==now) return 1;
			u[t[k]][t[j]]=now;
		}
	}
	return 0;
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
#endif

	cin>>n>>m;
	//n=m=1000;
	REP(i,n){
		REP(j,m) scanf("%d",&w[i][j]);
	}
	int a=1,b=1000000000,best=0;
	while(a<=b){
		int s = (a+b)/2;
		if(good(s)) best=s,a=s+1;
		else b=s-1;
	}
	cout<<best<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}