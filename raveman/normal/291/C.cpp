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

ll p[111111];
set<ll> w;
int n,k;

int num(ll mask){
	w.clear();
	REP(i,n)w.insert(p[i]&mask);
	return w.size();
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	cin>>n>>k;
	REP(i,n){
		int a[4];
		scanf("%d.%d.%d.%d",a+0,a+1,a+2,a+3);
		REP(j,4) p[i]=(p[i]<<8)+a[j];
	}
	ll mask = 0;
	for(int i=31;i>0;i--){
		mask|=(1ll<<i);
		if(num(mask)==k){
			int v4 = mask&255;
			mask>>=8;
			int v3 = mask&255;
			mask>>=8;
			int v2 = mask&255;
			mask>>=8;
			int v1 = mask&255;
			printf("%d.%d.%d.%d\n",v1,v2,v3,v4);
			return 0;
		}
	}
	puts("-1");
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}