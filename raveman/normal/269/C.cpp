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

int sum[222222];
int csum[222222];
int n,m;
int x[222222];
int y[222222];
int c[222222];
int d[222222];
vi v[222222];

void mark(int ver){
	if(ver==n-1)return;
	REP(i,v[ver].size()){
		int id = v[ver][i];
		if(d[id]==-1){
			if(x[id]==ver) d[id]=0;
			else d[id]=1;

			int other = x[id] + y[id] - ver;

			csum[other] += c[id];
			if(csum[other]*2==sum[other])
				mark(other);
		}
	}
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,m){
		scanf("%d %d %d",x+i,y+i,c+i);
		x[i]--,y[i]--;
		sum[x[i]]+=c[i];
		sum[y[i]]+=c[i];
		v[x[i]].pb(i);
		v[y[i]].pb(i);
	}
	CL(d,-1);

	mark(0);

	REP(i,m)printf("%d\n",d[i]);

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}