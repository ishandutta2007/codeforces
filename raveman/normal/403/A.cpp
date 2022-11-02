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

bool u[55][55];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		int n,p;
		cin>>n>>p;
		vi v;
		CL(u,0);
		REP(i,n)u[i][(i+1)%n]=u[(i+1)%n][i]=1;
		REP(i,n)v.pb(i);
		while(1){
			random_shuffle(v.begin(),v.end());
			bool good = true;
			REP(i,n){
				if(u[v[i]][v[(i+1)%n]]){good=0;break;}
			}
			if(good)break;
		}
		REP(i,n)u[v[i]][v[(i+1)%n]]=u[v[(i+1)%n]][v[i]]=true;
		REP(i,n)REP(j,n)if(!u[i][j] && i!=j && p){
			p--;
			u[i][j]=u[j][i]=true;
		}
		REP(i,n)REP(j,n)if(u[i][j] && i<j){
			printf("%d %d\n",i+1,j+1);
		}
	}

	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}