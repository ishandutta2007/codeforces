#pragma comment(linker, "/STACK:65777216")

#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <cassert>
#include <complex>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<list>

using namespace std;
 
typedef long long ll;
typedef vector<int> vi;	 
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef unsigned long long ull;
 
#define FOR(i,a,b) for (int i(a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define SORT(v) sort((v).begin(),(v).end())
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back

struct P{
	int x,y;
	int id;
};

bool cmp(const P&s1,const P&s2){
	return pii(s1.x,s1.y)<pii(s2.x,s2.y);
}

P USE;
vector<P> p;

bool cmp2(const P&s1,const P&s2){
	return (s1.x-USE.x)*ll(s2.y-USE.y)-(s2.x-USE.x)*ll(s1.y-USE.y)>0;
}



int n;
vi v[1555];
int sz[1555];
int res[1555];

void solve(vector<P> p, int curr,int par){

	int fix = 0;
	REP(i,p.size()) if(cmp(p[i],p[fix])) fix = i;
	res[p[fix].id] = curr;
	if(sz[curr]==1) return;
	USE = p[fix];
	p.erase(p.begin()+fix);
	sort(p.begin(), p.end(), cmp2);

	REP(i,v[curr].size()) if(v[curr][i]!=par){
		vector<P> t(p.end()-sz[v[curr][i]], p.end());
		p.erase(p.end()-sz[v[curr][i]],p.end());
		solve(t, v[curr][i], curr);
	}
}

int dfs(int ver,int par=-1){
	sz[ver] = 1;
	REP(i,v[ver].size()) if(v[ver][i]!=par)
		sz[ver] += dfs(v[ver][i], ver);
	return sz[ver];
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
	dfs(0);
	p.resize(n);
	REP(i,n) scanf("%d %d",&p[i].x, &p[i].y),p[i].id=i;

	solve(p, 0, -1);
	REP(i,n){
		if(i) printf(" ");
		printf("%d",res[i]+1);
	}
	puts("");

#ifdef LocalHost
	cerr<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}