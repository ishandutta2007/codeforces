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

int a[222222];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		int n;
		cin>>n;
		ll sum=0,xr=0;
		REP(i,n)scanf("%d",a+i),sum+=a[i],xr^=a[i];
		ll c1=0,c2=0,c3=0;
		REP(i,60){
			ll st = (1ll<<i);
			ll mask = (1ll<<(i+1))-1;
			REP(j,4){
				ll tsum = sum + st * j;
				ll txr = xr  ^ (st * (j%2));


				if((tsum & mask) == ((2 * txr) & mask)){
					if(j>=1)c1|=st;
					if(j>=2)c2|=st;
					if(j>=3)c3|=st;
					sum=tsum;
					xr=txr;
					break;
				}
			}
		}
		vector<ll> v;
		if(c1)v.pb(c1);
		if(c2)v.pb(c2);
		if(c3)v.pb(c3);
		cout<<v.size()<<endl;
		REP(i,v.size()) cout<<v[i]<<' ';
		cout<<'\n';
	}
	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}