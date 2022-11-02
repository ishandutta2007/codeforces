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
#define R(i,n)			REP(i,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)				memset(a,b,sizeof a)
#define pb				push_back

int n,m,q;
int x[222222];
int y[222222];
int l[222222];
int r[222222];
int s[222222];
int t[222222];

bool res[222222];

int d[1111][1111];
int t1[1111];
int t2[1111];

vi z[222222];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m>>q;

	FOR(i,1,m+1){
		scanf("%d %d",x+i,y+i);
		x[i]--,y[i]--;
	}

	REP(i,q)scanf("%d %d %d %d",l+i,r+i,s+i,t+i),s[i]--,t[i]--,z[l[i]].pb(i);
	REP(i,n)REP(j,n)d[i][j]=1e9;
	for(int i=m;i>=1;i--){
		memcpy(t1,d[x[i]],sizeof t1);
		memcpy(t2,d[y[i]],sizeof t2);
		REP(j,n)d[x[i]][j]=min(d[x[i]][j],t2[j]);
		REP(j,n)d[y[i]][j]=min(d[y[i]][j],t1[j]);
		d[x[i]][y[i]]=i;
		d[y[i]][x[i]]=i;

		REP(j,z[i].size()){
			int qq = z[i][j];

			if(d[s[qq]][t[qq]]<=r[qq]) res[qq]=true;
		}
	}

	REP(i,q)if(res[i])puts("Yes");else puts("No");

	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}