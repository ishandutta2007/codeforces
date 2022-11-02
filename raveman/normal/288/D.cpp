#pragma comment(linker, "/STACK:60777216")  

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

int n;
vi v[88888];
ll res = 0;

map<int,int> trsz[88888];


int tree_sz(int ver, int par){
	if(trsz[ver].count(par)) return trsz[ver][par];
	int res = 1;
	REP(i,v[ver].size()) if(v[ver][i]!=par) res += tree_sz(v[ver][i],ver);
	return trsz[ver][par] = res;
}

map<int,ll> r[88888];

ll c2(ll x){return x*(x-1)/2;}

ll solve(int ver, int par){
	if(r[ver].count(par)) return r[ver][par];
	ll res = 0;
	vector<pii> w;
	REP(i,v[ver].size()) if(v[ver][i]!=par)
		w.pb(make_pair(v[ver][i],tree_sz(v[ver][i],ver)));
	ll sum = 0;
	REP(i,w.size()) sum += c2(w[i].second);
	res=sum;
	REP(i,w.size()){
		res += solve(w[i].first,ver);
		res += ll(w[i].second)*(sum-c2(w[i].second));
	}
	return r[ver][par] = res;
}

ll go(int ver, int par){
	ll res = 0;
	vector<pii> w;
	REP(i,v[ver].size()) if(v[ver][i]!=par)
		w.pb(make_pair(v[ver][i],tree_sz(v[ver][i],ver)));
	ll sum = 0,s =0;
	REP(i,w.size()) sum += c2(w[i].second),s+=w[i].second;
	REP(i,w.size()){
		res += c2(w[i].second)*(sum-c2(w[i].second));
		res += go(w[i].first, ver);
		res += 2 * solve(w[i].first, ver) * (s+1-w[i].second);
	}
	REP(i,w.size()){
		res += 2*c2(w[i].second)*(c2(s+1-w[i].second)-(sum-c2(w[i].second)));
	}
	return res;
}
int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n-1){
		int x,y;
		scanf("%d %d",&x,&y);
		x--,y--;
		v[x].pb(y);
		v[y].pb(x);
	}

	cout<<go(0,-1)<<endl;

	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
	return 0;
}