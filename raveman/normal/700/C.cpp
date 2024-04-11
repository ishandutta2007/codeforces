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
#include<unordered_set>

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

int n,m,s,t;
vi v[1111];

int x[33333];
int y[33333];
int w[33333];

bool u[1111];
vi edges;

bool dfs(int ver){
	if(ver==t) return 1;
	if(u[ver])return 0;
	u[ver]=true;
	REP(i,v[ver].size()){
		int e = v[ver][i];
		if(dfs(x[e]+y[e]-ver)){
			edges.pb(e);
			return 1;
		}
	}
	return 0;
}

int FORBIDDEN;


int mask[1111];
int d[4][1111];

void dfs2(int ver,int to,int mm){
	queue<int> q;
	q.push(ver);
	mask[ver] |= mm;
	while(!q.empty()){
		ver = q.front();
		q.pop();
		if(ver==to)continue;
		REP(i,v[ver].size()){
			int e = v[ver][i];
			if(e==FORBIDDEN)continue;
			int nx = x[e] + y[e]-ver;
			if(mask[nx]&mm)continue;
			mask[nx]|=mm;
			q.push(nx);
			d[mm][nx] = d[mm][ver] + 1;
		}
	}
}

int bestb;
int be;

int intime[1111];
int outtime[1111];
int it;

void dfs3(int ver,int pe=-1){
	if(u[ver])return;
	u[ver]=true;

	it++;
	intime[ver] = it;
	outtime[ver] = it;

	REP(i,v[ver].size()){
		int e = v[ver][i];
		if(e==FORBIDDEN)continue;
		if(pe==e)continue;
		int nx = x[e]+y[e]-ver;
		if(mask[nx]!=3)continue;


		//cout<<"consider " << ver << " "<<nx<<' '<<d[1][nx]<<' '<<d[1][ver]<<' '<<d[2][nx]<<' '<<d[2][ver]<<endl;

		if(u[nx]){
			outtime[ver] = min(outtime[ver], intime[nx]);
		}else{
			dfs3(nx,e);
			outtime[ver] = min(outtime[ver], outtime[nx]);
		}


		if(outtime[nx] > intime[ver]) {
			if (d[1][nx] > d[1][ver] && d[2][nx] > d[2][ver]) continue;
			if(bestb > w[e]){
				bestb=w[e];
				be=e;
			}
		}
	}
}

pii solve(){
	CL(d,0);
	CL(mask,0);
	dfs2(s,t,1);
	dfs2(t,s,2);

	if(mask[s]!=3 || mask[t]!=3) return pii(0,0);


	bestb=1e9+7;


	CL(intime,0);CL(u,0);
	CL(outtime,0);
	it=0;
	dfs3(s);

	if(bestb > 1e9+4) return pii(-1,0);
	return pii(bestb,be);
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m>>s>>t;s--,t--;
	REP(i,m){
		cin>>x[i]>>y[i]>>w[i];
		x[i]--,y[i]--;
		v[x[i]].pb(i);
		v[y[i]].pb(i);
	}

	if(!dfs(s)){
		puts("0");
		puts("0");
	}else{
		int best=2e9+7;
		vi r;
		REP(f,edges.size()){
			FORBIDDEN = edges[f];
			pii t = solve();
			//cout<<"TEST " << FORBIDDEN << " = "<<t.first<<' '<<t.second<<endl;
			if(t.first==-1) continue;
			if(t.first + w[FORBIDDEN] < best){
				best = t.first + w[FORBIDDEN];
				r.clear();
				r.pb(FORBIDDEN);
				if(t.first!=0)r.pb(t.second);
			}
		}
		if(best>2e9+4)puts("-1");
		else{
			cout<<best<<endl;
			cout<<r.size()<<endl;
			REP(i,r.size()){
				if(i)printf(" ");
				printf("%d",r[i]+1);
			}
			puts("");
		}
	}


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}