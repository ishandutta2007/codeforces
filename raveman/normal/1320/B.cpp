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
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int n,m;
vi  v[2][222222];
int k;
int p[222222];

int d1[222222];
int d2[222222];

void solve(int* d,int p,int g){
	REP(i,n)d[i]=-1;
	d[p]=0;
	queue<int> q;
	q.push(p);
	while(!q.empty()){
		int z = q.front();
		q.pop();
		REP(i,v[g][z].size()){
			int nv = v[g][z][i];
			if(d[nv]==-1){
				d[nv]=d[z]+1;
				q.push(nv);
			}
		}
	}
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,m){
		int x,y;
		scanf("%d %d",&x,&y);
		x--,y--;
		v[0][x].pb(y);
		v[1][y].pb(x);
	}
	cin>>k;
	REP(i,k)scanf("%d",p+i),p[i]--;
	solve(d1,p[0],0);
	solve(d2,p[k-1],1);

	int mn = 0;
	int mx = 0;
	FOR(i,1,k-1){
		if(d2[p[i]]==d2[p[i-1]]-1);
		else mn++;
	}
	REP(i,k-1){
		// p[i] -> p[i+1]
		if(d2[p[i+1]]==d2[p[i]]-1){
			int nm=0;
			REP(j,v[0][p[i]].size()){
				int nv = v[0][p[i]][j];
				if(d2[nv]==d2[p[i]]-1)nm++;
			}
			if(nm>1)mx++;
		}else mx++;
	}
	cout<<mn<<' '<<mx<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}