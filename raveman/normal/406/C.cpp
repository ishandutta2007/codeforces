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

int n,m;
vi v[111111];
vi t[111111];
int ts[111111];
vi r[111111];

int  p[111111];
bool u[111111];
void dfs(int ver,int par=-1){
	if(u[ver])return;
	u[ver]=1;
	p[ver]=par;
	REP(i,v[ver].size()){
		int tt = v[ver][i];
		if(u[tt]) continue;
		dfs(tt,ver);
		t[tt].pb(ver);
		t[ver].pb(tt);
		ts[tt]++;
		ts[ver]++;
	}
}

set<pii> killed;

int dfs2(int ver){
	vi hang;
	REP(i,t[ver].size())if(t[ver][i]!=p[ver]){
		int val = dfs2(t[ver][i]);
		if(val==-1) continue;
		hang.push_back(val);
	}
	while(hang.size()>=2){
		int v1 = hang.back();
		hang.pop_back();
		int v2 = hang.back();
		hang.pop_back();
		printf("%d %d %d\n",v1+1,ver+1,v2+1);
	}

	vi rem;
	for(int i=0;i<r[ver].size();i++){
		if(killed.count(pii(ver,r[ver][i]))|| killed.count(pii(r[ver][i],ver)))continue;
		rem.pb(r[ver][i]);
	}
	// hang 0
	if (hang.size()==0){
		if (rem.size()==1){
			killed.insert(pii(ver,rem[0]));
			printf("%d %d %d\n",rem[0]+1,ver+1,p[ver]+1);
			return -1;
		}else{
			return ver;
		}
	}
	// hang 1
	if (hang.size()==1){
		if(rem.size()==1){
			killed.insert(pii(ver,rem[0]));
			printf("%d %d %d\n",hang[0]+1,ver+1,rem[0]+1);
			return ver;
		}else{
			printf("%d %d %d\n",hang[0]+1,ver+1,p[ver]+1);
			return -1;
		}
	}
	while(1);
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	CL(p,-1);

	cin>>n>>m;
	if(m%2){
		puts("No solution");
		return 0;
	}
	REP(i,m){
		int x,y;
		scanf("%d %d",&x,&y);
		x--,y--;
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(0);
	//REP(i,n)cout<<i<<' '<<p[i]<<endl;
	REP(i,n){
		vi tmp;
		REP(j,v[i].size()){
			int ver = v[i][j];
			if(p[ver]==i || p[i]==ver) continue;
			if(killed.count(pii(i,ver)) || killed.count(pii(ver,i))) continue;
			tmp.pb(ver);
		}
		while(tmp.size()>=2){
			int v1 = tmp.back();
			tmp.pop_back();
			int v2 = tmp.back();
			tmp.pop_back();
			printf("%d %d %d\n",v1+1,i+1,v2+1);
			killed.insert(pii(i,v1));
			killed.insert(pii(i,v2));
		}
	}
	REP(i,n){
		vi tmp;
		REP(j,v[i].size()){
			int ver = v[i][j];
			if(p[ver]==i || p[i]==ver) continue;
			if(killed.count(pii(i,ver)) || killed.count(pii(ver,i))) continue;
			r[i].pb(ver);
		}
		while(r[i].size()>=2);
	}
	dfs2(0);
	

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}