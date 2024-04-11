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
typedef pair<int,pii>	p3;
typedef pair<ll,ll> pl;
typedef pair<int,pl>	p3l;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int n;
int l[222222];
int r[222222];
int c[222222];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		cin>>n;
		REP(i,n)scanf("%d %d %d",l+i,r+i,c+i);
		int bp=l[0];
		int ep=r[0];
		int bc=c[0];
		int ec=c[0];
		int sp=c[0];
		REP(i,n){
			if(l[i]<bp)bp=l[i],bc=c[i],sp=-1;
			if(l[i]==bp)bc=min(bc,c[i]);
			if(r[i]>ep)ep=r[i],ec=c[i],sp=-1;
			if(r[i]==ep)ec=min(ec,c[i]);
			if(l[i]==bp && r[i]==ep){
				if(sp==-1 || sp>c[i])sp=c[i];
			}
			int res = bc + ec;
			if(sp!=-1)res=min(res,sp);
			printf("%d\n",res);
		}
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}