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
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)				memset(a,b,sizeof a)
#define pb				push_back

int n,m,k;
bool c[1111];
vi v[1111];
int nmv,nme;
bool u[1111];

void dfs(int ver){
	if(u[ver])return;
	u[ver]=1;
	nmv++;
	REP(i,v[ver].size()){
		nme++;
		dfs(v[ver][i]);
	}
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m>>k;
	REP(i,k){
		int x;
		cin>>x;
		x--;
		c[x]=1;
	}
	REP(i,m){
		int x,y;
		scanf("%d %d",&x,&y);
		x--,y--;
		v[x].pb(y);
		v[y].pb(x);
	}
	int res = 0;
	int mc=0;
	int restv = n;
	int reste = m;
	REP(i,n)if(c[i]){
		nmv=0;
		nme=0;
		dfs(i);
		mc=max(mc,nmv);
		res += nmv * (nmv - 1) / 2 - nme / 2;
		restv-=nmv;
		reste-=nme/2;
	}
	res += restv * (restv-1)/2 - reste;
	res += mc * restv;
	cout<<res<<endl;

	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}