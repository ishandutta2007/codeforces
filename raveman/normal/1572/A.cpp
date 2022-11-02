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

vi v[211111];
int n,now;
int u[222222];
int f[222222];
int r[222222];

int dfs(int ver){
	//cout<<ver<<endl;
	if(u[ver]==now)return r[ver];
	u[ver]=now;
	int res=1;
	REP(i,v[ver].size()){
		int nv=v[ver][i];
		//cout<<"!"<<nv<<endl;
		if(u[nv]==now && f[nv]!=now) {r[ver]=-1;f[ver]=now; return -1;}
		int t = dfs(nv);
		if(t==-1) {r[ver]=-1;f[ver]=now; return -1;}
		if(nv>ver)res=max(res,1+t);
		else res=max(res,t);
	}
	r[ver]=res;
	f[ver]=now;
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
		REP(i,n)v[i].clear();
		now++;
		REP(i,n){
			int x;
			scanf("%d",&x);
			REP(j,x){
				int y;
				scanf("%d",&y);
				y--;
				v[i].pb(y);
			}
		}
		int res=0;
		REP(i,n)if(u[i]!=now){
			int t = dfs(i);
			if(t==-1){res=-1;break;}
			else res=max(res,t);
		}
		//REP(i,n)cout<<i<<' '<<r[i]<<endl;
		cout<<res<<endl;
	}


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}