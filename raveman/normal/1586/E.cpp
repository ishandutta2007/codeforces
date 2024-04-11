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

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int n,m;
vi v[333333];
int s[333333];
int p[333333];
int d[333333];
bool u[333333];

vi solve(int v1,int v2){
	vi r1,r2;
	while(v1!=v2){
		if(d[v1]>=d[v2]){
			r1.pb(v1);
			v1=p[v1];
		}else{
			r2.pb(v2);
			v2=p[v2];
		}
	}
	r1.pb(v1);
	reverse(r2.begin(),r2.end());
	REP(i,r2.size())r1.pb(r2[i]);
	return r1;
}

void dfs(int ver,int par=-1,int depth=0){
	if(u[ver])return;
	u[ver]=1;
	p[ver]=par;
	d[ver]=depth;
	REP(i,v[ver].size()){
		if(v[ver][i]==par)continue;
		dfs(v[ver][i],ver,depth+1);
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
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(0);
	int q;
	cin>>q;
	vector<vi> r;
	REP(i,q){
		int x,y;
		scanf("%d %d",&x,&y);
		x--,y--;
		s[x]^=1;
		s[y]^=1;
		r.pb(solve(x,y));
	}
	int numodd=0;
	REP(i,n)if(s[i])numodd++;
	if(numodd){
		cout<<"NO"<<endl<<numodd/2<<endl;
	}else{
		puts("YES");
		REP(i,r.size()){
			printf("%d\n",r[i].size());
			REP(j,r[i].size())printf("%d ",r[i][j]+1);
			puts("");
		}
	}
		
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}