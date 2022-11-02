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

int n;
vi v[111111];
int l[111111];
int r[111111];

pl solve(int ver,int par=-1){
	pl res;
	REP(i,v[ver].size()){
		if(v[ver][i]==par)continue;
		pl t = solve(v[ver][i],ver);
		res.first+=max(t.first+abs(l[ver]-l[v[ver][i]]),t.second+abs(l[ver]-r[v[ver][i]]));
		res.second+=max(t.first+abs(r[ver]-l[v[ver][i]]),t.second+abs(r[ver]-r[v[ver][i]]));
	}
	return res;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		cin>>n;
		REP(i,n)scanf("%d %d",l+i,r+i),v[i].clear();
		REP(i,n-1){
			int x,y;
			scanf("%d %d",&x,&y);
			x--,y--;
			v[x].pb(y);
			v[y].pb(x);
		}
		pl t = solve(0);
		cout<<max(t.first,t.second)<<endl;
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}