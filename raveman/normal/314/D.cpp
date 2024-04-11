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

int n;
int x[111111];
int y[111111];

pii v[111111];

int bmn[111111];
int bMX[111111];
int emn[111111];
int eMX[111111];

bool good2(ll r,int p1,int p2){
	ll mn=1e10,MX=-1e10;
	if(p1>0){
		mn=min(mn,(ll)bmn[p1-1]);
		MX=max(MX,(ll)bMX[p1-1]);
	}
	if(p2<n){
		mn=min(mn,(ll)emn[p2]);
		MX=max(MX,(ll)eMX[p2]);
	}
	//cout<<p1<<' '<<p2<<' '<<mn<<' '<<MX<<endl;
	return mn+r>=MX;
}

bool good(ll r){
	int p1 = 0, p2 = 0;
	while(p1<n){
		while(p2<n && v[p1].first+r>=v[p2].first) p2++;
		if(good2(r,p1,p2)) return true;
		p1++;
	}
	return false;
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n) scanf("%d %d",x+i,y+i),v[i]=pii(x[i]+y[i],x[i]-y[i]);
	sort(v,v+n);
	//REP(i,n) cout<<v[i].first<<' '<<v[i].second<<endl;
	bmn[0]=v[0].second;
	bMX[0]=v[0].second;
	FOR(i,1,n){
		bmn[i]=min(bmn[i-1],v[i].second);
		bMX[i]=max(bMX[i-1],v[i].second);
	}
	emn[n-1]=v[n-1].second;
	eMX[n-1]=v[n-1].second;
	for(int i=n-2;i>=0;i--){
		emn[i]=min(emn[i+1],v[i].second);
		eMX[i]=max(eMX[i+1],v[i].second);
	}
	ll a = 0;
	ll b = 1e10;
	ll best = 0;
	while(a<=b){
		ll s = (a+b)/2;
		if(good(s)) best=s,b=s-1;
		else a=s+1;
	}
	printf("%.10lf\n",best/2.0);
	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}