//#pragma comment(linker, "/STACK:60777216")  

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

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int n,m;
bool   u[222222];
vi     o;

vector<pii> rg[222222];
vi     v[222222];
vi    vt[222222];

void dfs(int ver){
	u[ver]=1;
	REP(i,v[ver].size())if(!u[v[ver][i]]) dfs(v[ver][i]);
	o.pb(ver);
}

vi c;
void dfs2(int ver){
	u[ver]=1;
	c.pb(ver);
	REP(i,vt[ver].size())if(!u[vt[ver][i]])dfs2(vt[ver][i]);
}

int msk[222222];
int solvetime;
ll rt[222222];
ll res[222222];

ll gcd(ll a,ll b){
	if(b<0)b=-b;
	while(a&&b)
		if(a>b)a%=b;
		else b%=a;
	return a+b;
}

void solve(vi c){
	solvetime++;
	REP(i,c.size())msk[c[i]]=solvetime;
	queue<int> q;
	q.push(c[0]);
	rt[c[0]]=0;
	while(!q.empty()){
		int ver = q.front();
		q.pop();

		REP(i,rg[ver].size()){
			int nver=rg[ver][i].first;
			if(msk[ver]!=msk[nver])continue;
			if(rt[nver]<=0){
				rt[nver]=rt[ver]+rg[ver][i].second;
				q.push(nver);
			}
		}
	}

	ll g = rt[c[0]];
	REP(i,c.size()){
		int ver = c[i];
		REP(j,rg[ver].size()){
			int nver=rg[ver][j].first;
			if(msk[ver]!=msk[nver])continue;
			ll nt = rt[ver] + rg[ver][j].second;
			g = gcd(g, rt[nver] - nt);
		}
	}

	REP(i,c.size()) res[c[i]]=g;

}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,m){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);x--,y--;
		v[x].pb(y);
		vt[y].pb(x);
		rg[x].pb(pii(y,z));
	}

	REP(i,n)if(!u[i])dfs(i);

	reverse(o.begin(),o.end());

	CL(rt,-1);
	CL(u,0);
	REP(i,o.size())if(!u[o[i]]){
		c.clear();
		dfs2(o[i]);
		solve(c);
	}
	int q;
	cin>>q;
	REP(i,q){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);x--;
		if(y%gcd(z,res[x])==0){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}