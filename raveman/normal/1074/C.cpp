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

int n;
int x[333333];
int y[333333];
pii c[333333];
int d(pii& p1,pii &p2){return abs(p1.first-p2.first)+abs(p1.second-p2.second);}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	int mx=1e9,MX=-1e9;
	int my=1e9,MY=-1e9;
	REP(i,n){
		scanf("%d %d",x+i,y+i);
		c[i]=pii(x[i],y[i]);
		mx=min(mx,x[i]);
		MX=max(MX,x[i]);
		my=min(my,y[i]);
		MY=max(MY,y[i]);
	}

	vector<pii> p;
	REP(i,n)if(x[i]==mx || x[i]==MX)p.pb(pii(x[i],y[i]));
	REP(i,n)if(y[i]==my || y[i]==MY)p.pb(pii(x[i],y[i]));
	UN(p);
	int a3 = 0;
	REP(i1,p.size())REP(i2,i1)REP(i3,i2){
		a3=max(a3,d(p[i1],p[i2])+d(p[i2],p[i3])+d(p[i3],p[i1]));
	}
	REP(i1,p.size())REP(i2,i1){
		REP(i,n)a3=max(a3,d(p[i1],p[i2])+d(p[i1],c[i])+d(p[i2],c[i]));
	}
	cout<<a3;
	for(int i=4;i<=n;i++)printf(" %d",2*(MX-mx+MY-my));
	puts("");
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}