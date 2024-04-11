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
int x[222222];
int y[222222];

pii p[222222];
pii t[222222];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	//n=2*2*3*5*7*11*13;
	//m=200000;
	REP(i,m){
		scanf("%d %d",x+i,y+i);
		x[i]--,y[i]--;
		//x[i]=rand()%n+1;
		//y[i]=rand()%n+1;
		if(y[i]<x[i])y[i]+=n;
		int d = y[i]-x[i];
		if(d+d>n){
			swap(x[i],y[i]);
			d=n-d;
			if(x[i]>=n)x[i]-=n;
		}else if(d+d==n){
			if(x[i]>=n/2)x[i]-=n/2;
		}
		p[i]=pii(x[i],d);
	}
	sort(p,p+m);
	FOR(i,1,n)if(n%i==0){
		REP(j,m){
			t[j]=pii(p[j].first+i,p[j].second);
			if(t[j].first>=n)t[j].first-=n;
			if(t[j].second*2==n && t[j].first>=n/2){
				t[j].first-=n/2;
			}
		}
		sort(t,t+m);
		bool g = 1;
		REP(j,m)if(t[j]!=p[j]){g=0;break;}
		if(g){
			puts("Yes");
			return 0;
		}

	}
	puts("No");
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}